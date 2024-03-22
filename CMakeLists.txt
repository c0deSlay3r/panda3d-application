cmake_minimum_required(VERSION 3.18)

project(PandaProg)

set(PANDA3D_INCLUDE_DIR "" CACHE PATH "Path to Panda3D include file")
set(PANDA3D_LIBS_DIR "" CACHE PATH "Path to Panda3D libs file")
set(EIGEN3_DIR "")

if(UNIX)
    message(STATUS "Looking for Panda3D directory")

    if(NOT PANDA3D_INCLUDE_DIR AND NOT PANDA3D_LIBS_DIR)
        message(WARNING "There are no provided paths to Panda3D")
        
        message(STATUS "Default directory search")

        if(NOT EXISTS "/usr/lib/panda3d" AND NOT EXISTS "/usr/include/panda3d/")
            message(FATAL_ERROR "Unable to find the paths to Panda3D. Restart and specify paths to include and library directory.")
        endif()

        set(PANDA3D_INCLUDE_DIR "/usr/include/panda3d/")
        set(PANDA3D_LIBS_DIR "/usr/lib/panda3d")
    endif()

    message(STATUS "Looking for Panda3D directory - done")

    message(STATUS "LIB: ${PANDA3D_LIBS_DIR}")
    message(STATUS "INCLUDE: ${PANDA3D_INCLUDE_DIR}")

    message(STATUS "Checking files in directories")

    message(STATUS "Looking for libpanda.so")

    if(NOT EXISTS "${PANDA3D_LIBS_DIR}/libpanda.so")
        message(FATAL_ERROR "Looking for libpanda.so - not found")
    endif()
    
    message(STATUS "Looking for libpanda.so - found")

    message(STATUS "Looking for pandaFramework.h")

    if(NOT EXISTS "${PANDA3D_INCLUDE_DIR}/pandaFramework.h")  
        message(FATAL_ERROR "Looking for pandaFramework.h - not found")
    endif()

    message(STATUS "Looking for pandaFramework.h - found")

    message(STATUS "Checking files in directories - done")


    message(STATUS "Search Eigen")
    if(NOT EXISTS "/usr/include/eigen3")
        message(FATAL_ERROR "Search Eigen - not found")
    endif()
    set(EIGEN3_DIR "/usr/include/eigen3")
    message(STATUS "Search Eigen - found")
endif(UNIX)

if(WIN32)
    message(FATAL_ERROR "Support for Windows be added coming soon")
endif(WIN32)


set(CMAKE_CXX_STANDARD 20)


message(STATUS "Search for project files")

file(GLOB_RECURSE CXX_HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.hpp")
message(STATUS "CXX header files: ${CXX_HEADER_FILES}")

file(GLOB_RECURSE CXX_SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
message(STATUS "CXX source files: ${CXX_SOURCE_FILES}")

message(STATUS "Search for project files - done")

message(STATUS "Search for all Panda3D libraries")
file(GLOB PANDA3D_LIBS "${PANDA3D_LIBS_DIR}/*.so*")
message(STATUS "${PANDA3D_LIBS}")
message(STATUS "Search for all Panda3D libraries - done")

add_executable(${PROJECT_NAME} ${CXX_HEADER_FILES} ${CXX_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PANDA3D_INCLUDE_DIR} PRIVATE ${EIGEN3_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PANDA3D_LIBS})

