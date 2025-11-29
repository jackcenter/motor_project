add_executable(motor_project main.cpp)

target_compile_features(motor_project PRIVATE cxx_std_20)
target_compile_options(motor_project PRIVATE -Wall -Wextra -Wpedantic)
