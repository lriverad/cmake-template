cmake_minimum_required(VERSION 3.10)

project(NewProject
  VERSION 1
  LANGUAGES C CXX)

set(CMAKE_C_STANDARD            11)
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
# add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
# target_link_directories(${PROJECT_NAME} PRIVATE)
# target_link_libraries(${PROJECT_NAME} PRIVATE)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  target_compile_definitions(${PROJECT_NAME} PRIVATE NDEBUG)
endif()
