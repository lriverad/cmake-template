cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED PROJECT_NAME)
  set(PROJECT_NAME "app" CACHE STRING "Project name")
endif()

project(${PROJECT_NAME}
  VERSION 1
  LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
# add_library(${PROJECT_NAME} STATIC ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL "debug")
  target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "release")
  target_compile_definitions(${PROJECT_NAME} PRIVATE NDEBUG)
endif()

if(TOOLCHAIN_PLATFORM STREQUAL "windows")
    target_include_directories(${PROJECT_NAME} PRIVATE include)

    file(GLOB LIB_FILES "${CMAKE_SOURCE_DIR}/lib/windows/*.dll")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/windows")

    foreach(LIB_FILE ${LIB_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        ${LIB_FILE} "${CMAKE_SOURCE_DIR}/bin/windows"
    )
    endforeach()

    # target_link_directories(${PROJECT_NAME} PRIVATE lib/windows)
    # target_link_libraries(${PROJECT_NAME} PRIVATE)
elseif(TOOLCHAIN_PLATFORM STREQUAL "linux")
    target_include_directories(${PROJECT_NAME} PRIVATE include)

    file(GLOB LIB_FILES "${CMAKE_SOURCE_DIR}/lib/linux/*.so" "${CMAKE_SOURCE_DIR}/lib/linux/*.so.*")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/linux")

    foreach(LIB_FILE ${LIB_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        ${LIB_FILE} "${CMAKE_SOURCE_DIR}/bin/linux"
    )
    endforeach()

    # target_link_directories(${PROJECT_NAME} PRIVATE lib/linux)
    # target_link_libraries(${PROJECT_NAME} PRIVATE)
elseif(TOOLCHAIN_PLATFORM STREQUAL "wasm")
    target_include_directories(${PROJECT_NAME} PRIVATE include)

    file(GLOB WASM_SRC_FILES "${CMAKE_SOURCE_DIR}/web/*")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/wasm")

    foreach(WASM_SRC_FILE ${WASM_SRC_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        ${LIB_FILE} "${CMAKE_SOURCE_DIR}/bin/wasm"
    )
    endforeach()

    # target_link_directories(${PROJECT_NAME} PRIVATE lib/wasm)
    # target_link_libraries(${PROJECT_NAME} PRIVATE)
endif()
