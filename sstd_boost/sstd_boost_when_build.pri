
DEFINES *= SSTD_BUILD_BOOST_SOURCE

DEFINES *= BOOST_ATOMIC_SOURCE
DEFINES *= BOOST_CHRONO_SOURCE
DEFINES *= BOOST_DATE_TIME_SOURCE
DEFINES *= BOOST_SYSTEM_SOURCE
DEFINES *= BOOST_THREAD_BUILD_DLL
DEFINES *= BOOST_CONTEXT_SOURCE

SOURCES += $$PWD/source/boost_atomic.cpp
SOURCES += $$PWD/source/boost_chrono.cpp
SOURCES += $$PWD/source/boost_system.cpp
SOURCES += $$PWD/source/boost_exception.cpp
SOURCES += $$PWD/source/boost_date_time.cpp
SOURCES += $$PWD/source/boost_thread.cpp
SOURCES += $$PWD/source/boost_context.cpp

win32-g++*{
    include($$PWD/source/boost_context_mingw64.pri)
}

linux-g++*{
    include($$PWD/source/boost_context_linux_gcc64.pri)
}

win32-msvc*{
    include($$PWD/source/boost_context_win64_msvc.pri)
}

