cmake_minimum_required(VERSION 3.8.2)
project(app
  VERSION 1
  LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES src/*.c src/*.cc src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
# target_link_directories(${PROJECT_NAME} PRIVATE)
# target_link_libraries(${PROJECT_NAME} PRIVATE)

# Platform Specific
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set_target_properties(${PROJECT_NAME} PROPERTIES
    CMAKE_INSTALL_RPATH "$ORIGIN"
    CMAKE_BUILD_WITH_INSTALL_RPATH TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/linux/")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_SHARED_LIBS TRUE
    CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/windows/")
endif()

# Macros
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_DEBUG)
endif()
