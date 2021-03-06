﻿#pragma once

#include "../sstd_library.hpp"

namespace _theSSTDLibraryFunctionFile {

    /*判断一个类是否包含 .quit() 函数*/
    template<typename T, typename = void>
    class HasQuit : public std::false_type {
    };

    template<typename T>
    class HasQuit< T, std::void_t< decltype(std::declval<
        std::remove_cv_t<
        std::remove_reference_t< T > > >().quit()) > > : public std::true_type {
    };

    /*包装一个包含 .quit() 的类，保证其在析构的时候执行quit() */
    template<typename T>
    class QuitWrap {
        sstd_delete_copy_create(QuitWrap);
    public:
        using U = std::remove_cv_t<
            std::remove_reference_t< T > >;
        U thisData;

        inline QuitWrap() : thisData{} {
        }

        template<typename A0, typename ... Args,
            typename = std::enable_if_t< std::is_constructible_v< U, A0&&, Args&&... > >
        >inline QuitWrap(A0&&a0, Args&&...args) : thisData(std::forward<A0>(a0),
            std::forward<Args>(args)...) {
        }

        template<typename A0, typename ... Args,
            typename = void ******,
            typename = std::enable_if_t< !std::is_constructible_v< U, A0&&, Args&&... > >
        >inline QuitWrap(A0&&a0, Args&&...args) : thisData{ std::forward<A0>(a0),
            std::forward<Args>(args)... } {
        }

        inline ~QuitWrap() {
            thisData.quit();
        }

    private:
        sstd_class(QuitWrap);
    };

}/**/

namespace sstd {

    /*T should have ->start()  ; */
    template <typename T>
    class StartFunction {
        T thisFunction;
    public:

        template<typename U,
            typename = std::enable_if_t< std::is_constructible_v< T, U&& > >
        > inline StartFunction(U && arg) :
            thisFunction{ std::forward<U>(arg) } {
        }

        inline void operator()() const {
            this->start();
        }

        inline void start() const {
            (const_cast<StartFunction *>(this)->thisFunction)->start();
        }

        template< typename = std::enable_if_t<
            _theSSTDLibraryFunctionFile::HasQuit<
            decltype(*(std::declval<T>())) >::value > >
            inline void quit() const {
            (const_cast<StartFunction *>(this)->thisFunction)->quit();
        }

        inline auto getFunction() & {
            return thisFunction;
        }

        inline auto getFunction() const & {
            return thisFunction;
        }

        inline auto getFunction() && {
            return std::move(thisFunction);
        }

    public:
        sstd_default_copy_create(StartFunction);
    private:
        sstd_class(StartFunction);
    };


    template <typename U, typename ... Args>
    inline StartFunction< std::shared_ptr<U> > makeStartFunction(Args && ... args) {
        if constexpr (!_theSSTDLibraryFunctionFile::HasQuit<U>::value) {
            return StartFunction< std::shared_ptr<U> >{
                sstd_make_shared<U>(std::forward<Args>(args)...)
            };
        } else {
            using QuitWrapType =
                _theSSTDLibraryFunctionFile::QuitWrap<U>;
            auto varAns = sstd_new< QuitWrapType >( std::forward<Args>(args)... );
            assert(reinterpret_cast<QuitWrapType*>(&(varAns->thisData)) == varAns);
            return StartFunction< std::shared_ptr<U> >{
                std::shared_ptr<U>{ &(varAns->thisData),
                    [](auto ptr) { delete reinterpret_cast<QuitWrapType*>(ptr); },
                    sstd_allocator<U>{}
                }};
        }
    }

}/*namespace sstd*/

template <typename U, typename ... Args>
inline sstd::StartFunction< std::shared_ptr<U> > sstd_make_start_function(Args && ... args) {
    return sstd::makeStartFunction<U>(std::forward<Args>(args)...);
}

namespace sstd {
    class SSTD_SYMBOL_DECL YieldFunctionBasic {
        sstd_delete_copy_create(YieldFunctionBasic);
    public:
        YieldFunctionBasic();
        virtual ~YieldFunctionBasic();
    protected:
        virtual void doRun() = 0;
        virtual void doException() noexcept;
    private:
        sstd_class(YieldFunctionBasic);
    };
}/*namespace sstd*/

namespace sstd {

    class YieldResumeFunctionPrivate;

    class SSTD_SYMBOL_DECL YieldResumeFunction : 
        public YieldFunctionBasic , 
        public std::enable_shared_from_this<YieldResumeFunction> {
        YieldResumeFunctionPrivate * const thisPrivate;
        using SuperType = std::enable_shared_from_this<YieldResumeFunction>;
    public:
        template<typename T>
        class BindFunction final {
            using FunType = std::remove_cv_t< std::remove_reference_t<T> >;
            FunType thisFunction;
            YieldResumeFunction * super;
            std::shared_ptr<const void> thisData;
        public:
            template<typename U>
            inline BindFunction(U && argFunc,YieldResumeFunction * arg):
                thisFunction( std::forward<U>(argFunc) ),
                super(arg) {
                thisData = arg->shared_from_this();
            }
            inline void operator()() const {
                auto varThis = const_cast<BindFunction*>(this);
                sstd_try {
                    varThis->thisFunction();
                } sstd_catch (...) {
                    varThis->super->resumeWithException();
                    return;
                }
                varThis->super->resume();
            }
            sstd_default_copy_create(BindFunction);
        public:
            sstd_class(BindFunction);
        };
    public:
        YieldResumeFunction(std::size_t=1024uLL*1024uLL*64uLL);
        ~YieldResumeFunction();
    public:
        void start();
        void quit();
    protected:
        virtual void doQuit() noexcept;
    public:
        bool isOuter() const;
        bool isFinished() const;
        bool hasException() const;
        bool isStart() const;
    protected:
        void innerYield();
        void outerYiled();
        template<typename T>
        BindFunction< std::remove_cv_t< std::remove_reference_t<T> > > bind(T &&) const;
    private:
        void resume();
        void resumeWithException();
        void directResume();
        void directYield();
        using SuperType::shared_from_this;
        using SuperType::weak_from_this;
    private:
        sstd_delete_copy_create(YieldResumeFunction);
        sstd_class(YieldResumeFunction);
    };

    template<typename T>
    YieldResumeFunction::BindFunction< std::remove_cv_t< std::remove_reference_t<T> > > YieldResumeFunction::bind(T && arg) const {
        return { 
            std::forward<T>(arg),
            const_cast<YieldResumeFunction *>(this) };
    }
   
}/*namespace sstd*/




