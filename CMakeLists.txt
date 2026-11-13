cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_MODULE_STD ON)

project(db LANGUAGES CXX)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g3 -gdwarf-5 -O0 -fstandalone-debug)
endif()

add_subdirectory(libdb)
add_subdirectory(dbcli)

execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    RESULT_VARIABLE _symlink_result
    ERROR_QUIET
)
if(NOT _symlink_result EQUAL 0)
    message(WARNING "Failed to create symlink for compile_commands.json. Some tools may not work correctly.")
endif()
