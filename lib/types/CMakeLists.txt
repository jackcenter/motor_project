add_library(types INTERFACE)

target_include_directories(types
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(types INTERFACE cxx_std_20)
