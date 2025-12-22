add_library(gpio STATIC
    src/gpio.c
)

target_include_directories(gpio
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(gpio
    PRIVATE
        -ffunction-sections
        -fdata-sections
        -Wall
        -Wextra
)
