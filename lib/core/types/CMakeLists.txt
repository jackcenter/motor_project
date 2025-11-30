add_library(types INTERFACE)

find_package(fmt REQUIRED)

target_include_directories(types
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(types
  INTERFACE
    fmt::fmt
)

target_compile_features(types INTERFACE cxx_std_20)
