# Project name
project(test_functor_type)

cmake_minimum_required(VERSION 2.6)
if ( NOT CMAKE_BUILD_TYPE )
    SET(CMAKE_BUILD_TYPE Release)
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

if ( APPLE )
    set(CMAKE_CXX_FLAGS "-D OSX -D UNIX -stdlib=libc++ ${CMAKE_CXX_FLAGS}")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -stdlib=libc++")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
elseif ( UNIX )
    set(CMAKE_CXX_FLAGS "-D LINUX -D UNIX ${CMAKE_CXX_FLAGS}")
elseif ( WIN32 )
    set(CMAKE_CXX_FLAGS "-D WIN32 ${CMAKE_CXX_FLAGS}")
endif()

set(EXECUTABLE_NAME "test_functor_type")

file(GLOB source_file *.cpp *.h *.hpp)
set(current_SRCS
    ${current_SRCS}
    ${source_file}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${EXECUTABLE_NAME}
    ${current_SRCS}
)

install_targets(/ ${EXECUTABLE_NAME})
