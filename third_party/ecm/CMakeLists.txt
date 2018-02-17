cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(ecm VERSION 0.1.0 LANGUAGES C CXX)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
else()
    # Realization of MSVC compiler support
    message(FATAL_ERROR "You are seriously, man? Use GNU or Clang compiler or go away!")
endif()

set(HEADER_SUFFIX "h")
set(SOURCE_SUFFIX "cpp")

file(GLOB INCLUDES "*.${HEADER_SUFFIX}")
file(GLOB SOURCES "*.${SOURCE_SUFFIX}")

include_directories(${INCLUDE_DIR})

add_library(${PROJECT_NAME} ${INCLUDES} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} gmp ntl)
