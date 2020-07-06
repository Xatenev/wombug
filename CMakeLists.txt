cmake_minimum_required(VERSION 3.14)
project(wombug)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/include)
aux_source_directory(src/shared sources_shared)

if (WIN32)
    aux_source_directory(src/win32 sources_os_specific)
endif ()

if (UNIX)
    aux_source_directory(src/unix sources_os_specific)
endif ()

add_executable(wombug
        src/main.c
        ${sources_shared}
        ${sources_os_specific}
        )