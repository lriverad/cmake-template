cmake_minimum_required(VERSION 3.10)

# Requires emsdk environment to be setup
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")
set(CMAKE_AR "emar")
set(CMAKE_RANLIB "emranlib")

set(CMAKE_EXE_LINKER_FLAGS "-s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
set(CMAKE_SHARED_LINKER_FLAGS "-s WASM=1 -s ALLOW_MEMORY_GROWTH=1")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/wasm/")

set(TOOLCHAIN_PLATFORM "wasm" CACHE STRING "Custom name for toolchain")
