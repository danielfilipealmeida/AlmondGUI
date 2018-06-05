cmake_minimum_required(VERSION 2.8)
project(AlmondGUI)


## SET COMPILER FLAGS
set(C++11FLAG "-std=c++11")


find_package(PkgConfig REQUIRED)



## GATHER ALL COMPILER FLAGS INTO ONE VARIABLE
set(COMPILER_FLAGS "${C++11FLAG}")

## SET COMPILER FLAGS
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")

## PACKAGES
SET(GLIB_VERSION "glib-2.0")
SET(GSTREAMER_VERSION "gstreamer-1.0")

## CHECK MODULES
pkg_check_modules(GLIB2 REQUIRED ${GLIB_VERSION})
pkg_check_modules(GSTREAMER REQUIRED ${GSTREAMER_VERSION})


## PATHS
SET(EXTERNAL_PATH "External")
SET(OPENFRAMEWORKS_PATH "../openFrameworks-0.9.8")
SET(GSTREAM_PATH "/usr/include/gstreamer-1.0/")
SET(GLIB_PATH "/usr/include/${GLIB_VERSION}/")
SET(JSON_PATH "${EXTERNAL_PATH}/json/")


## SET UP ALL THE INCLUDES
include_directories("Sources/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/3d/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/app/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/communication/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/events/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/gl/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/graphics/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/math/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/sound/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/types/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/utils/")
include_directories("${OPENFRAMEWORKS_PATH}/libs/openFrameworks/video/")

include_directories("${OPENFRAMEWORKS_PATH}/libs/tess2/include")
include_directories("${OPENFRAMEWORKS_PATH}/libs/utf8cpp/include")
include_directories("${OPENFRAMEWORKS_PATH}/libs/poco/include")
include_directories("${OPENFRAMEWORKS_PATH}/libs/cairo/include/cairo")
include_directories("${OPENFRAMEWORKS_PATH}/libs/glfw/include")
include_directories("${OPENFRAMEWORKS_PATH}/libs/kiss/include")
include_directories("${GSTREAM_PATH}")
include_directories("${GLIB_PATH}")
include_directories("${GLIB_PATH}/glib")
include_directories("${EXTERNAL_PATH}/src/")


## GET ALL FILES TO COMPILE FOR THE LIB
file(GLOB Sources_SRC
    "Sources/*.hpp"
    "Sources/*.cpp"
)



## ADD FILES TO COMPILE
add_library(AlmondGUI STATIC
    Sources/Element.cpp
    Sources/Button.cpp
    Sources/ButtonGroup.cpp
    Sources/ElementStyle.cpp
    Sources/GUI.cpp)


## COMPILE HELLO WORLD
add_executable(HelloWorld examples/HelloWorld/main.cpp)


## glib2 stuff
target_include_directories(HelloWorld PUBLIC ${GLIB2_INCLUDE_DIRS})
target_link_libraries(HelloWorld ${GLIB2_LIBRARIES})
target_compile_options(HelloWorld PUBLIC ${GLIB2_CFLAGS_OTHER})


## gtreamer stuff
target_include_directories(HelloWorld PUBLIC ${GSTREAMER_INCLUDE_DIRS})
target_link_libraries(HelloWorld ${GSTREAMER_LIBRARIES})
target_compile_options(HelloWorld PUBLIC ${GSTREAMER_CFLAGS_OTHER})

