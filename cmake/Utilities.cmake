##
# @brief Add a Google Test executable to the project with automatic CTest registration.
#
# This function simplifies creating test executables for Google Test. It automatically:
# - Generates a unique test name based on the file path and prefix.
# - Adds an executable from the specified .cpp test file.
# - Links against GTest::gtest_main and a specified library.
# - Sets the runtime output directory for the test executable.
# - Registers the executable with CTest.
# - Labels the test for selective test runs.
#
# @param test_file_path Path to the folder containing the test file, relative to the project root.
# @param test_file_prefix Prefix Name of the test file; the source file is assumed to be <test_file_prefix>.cpp.
# @param test_lib The library to link against and use as a test label.
#
# @note Use CTest to run the tests. Labels allow selective execution, e.g., `ctest -L my_lib`.
#
# @example
#   # Add a test executable for tests/my_lib/test_my_file.cpp linking against my_lib
#   add_project_gtest(tests/my_lib test_my_file my_lib)
##
function(add_project_gtest test_file_path test_file_prefix test_lib)
  file(RELATIVE_PATH relative_test_file_path 
    "${CMAKE_SOURCE_DIR}"
    "${test_file_path}"
  )

  string(REPLACE "/" "_" test_file_path_underscore ${relative_test_file_path})
  set(test_name "${test_file_path_underscore}_${test_file_prefix}")
  add_executable(${test_name} ${test_file_path}/${test_file_prefix}.cpp)
  target_link_libraries(${test_name}
    PRIVATE
        GTest::gtest_main
        ${test_lib}
  )

  set_target_properties(${test_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY}
  )
  add_test(NAME ${test_name} COMMAND ${test_name})
  set_tests_properties(${test_name} PROPERTIES LABELS "${test_lib}")
endfunction()
