cmake_minimum_required(VERSION 4.0)
project(Ballzy C)

set(CMAKE_C_STANDARD 23)

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 5.0
            GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

file(GLOB_RECURSE SOURCES src/*.c)
file(GLOB_RECURSE HEADERS src/*.h)

add_executable(Ballzy ${SOURCES} ${HEADERS})

target_link_libraries(Ballzy PUBLIC raylib)

if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS)

    add_custom_command(TARGET Ballzy POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:raylib> $<TARGET_FILE_DIR:Ballzy>)
    file(COPY resource DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug")
elseif(APPLE)
    add_definitions(-DPLATFORM_MACOS)

    add_custom_command(TARGET Ballzy POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:raylib> $<TARGET_FILE_DIR:Ballzy>)
    file(COPY resource DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
elseif(UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()
