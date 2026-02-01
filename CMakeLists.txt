cmake_minimum_required(VERSION 3.16)

project(doom C)

set(CMAKE_C_STANDARD 11)

add_executable(doom
    src/main.c
    src/platform_sdl.c
    src/renderer.c
)

target_include_directories(doom PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/SDL2
)

target_link_directories(doom PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/x64
)

# IMPORTANT: order matters
target_link_libraries(doom
    SDL2

    # --- Windows system libraries required by SDL ---
    mingw32
    setupapi
    imm32
    winmm
    version
    cfgmgr32
    ole32
    shell32
    advapi32
    user32
    gdi32
    kernel32
)

# MinGW console subsystem
if (MINGW)
    target_link_options(doom PRIVATE -mconsole)
endif()

add_custom_command(TARGET doom POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/bin/x64/SDL2.dll
    $<TARGET_FILE_DIR:doom>
)
