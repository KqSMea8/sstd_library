TEMPLATE = lib

QT -= gui
QT -= core

CONFIG(debug,debug|release){
    TARGET = sstd_library_debug
}else{
    TARGET = sstd_library
}

#boost
INCLUDEPATH += $$PWD/sstd_boost
include($$PWD/cplusplus_basic.pri)
include($$PWD/sstd_boost/sstd_boost.pri)
include($$PWD/sstd_boost/sstd_boost_when_build.pri)

#output path
include($$PWD/sstd_build_path.pri)
DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}

equals(TEMPLATE, "vclib") {
    SOURCES += $$ASM_FILES_TOBUILD
}else{
    DISTFILES += $$ASM_FILES_TOBUILD
}

DEFINES *= SSTD_BUILD_SOURCE
HEADERS += $$PWD/sstd_library.hpp
HEADERS += $$PWD/global_sstd_library.hpp

HEADERS += $$PWD/sstd_library_memory/sstd_library_memory.hpp
SOURCES += $$PWD/sstd_library_memory/sstd_library_memory.cpp

HEADERS += $$PWD/sstd_library_exception/sstd_library_exception.hpp
SOURCES += $$PWD/sstd_library_exception/sstd_library_exception.cpp

