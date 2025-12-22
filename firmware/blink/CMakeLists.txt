cmake_minimum_required(VERSION 3.20)

project(blink C ASM)

set (LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/linker/STM32F091RCTX_FLASH.ld")

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/../lib/gpio
    ${CMAKE_BINARY_DIR}/gpio
)

add_executable(${PROJECT_NAME}
	startup/startup_stm32f091rctx.s
	src/main.c
	src/syscalls.c
	src/sysmem.c
)

target_compile_options(blink PRIVATE -O0
    -mcpu=Cortex-M0
    -std=gnu11    
    -Wall
    -Werror
    -ffunction-sections
    -fdata-sections
)

target_link_libraries(blink
    PRIVATE
        gpio
)

target_link_options(${PROJECT_NAME} PRIVATE
    -T${LINKER_SCRIPT}
    -Wl,-Map=${PROJECT_NAME}.map
    -static
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    SUFFIX ".elf"
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex
            $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
            ${CMAKE_PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary
            $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
            ${CMAKE_PROJECT_NAME}.bin
)
