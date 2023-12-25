cmake_minimum_required(VERSION 3.10)
project(test)

include_directories(
  include
)

add_executable(test_temple test_template.cc)

add_executable(test_sfinae sfinae_test.cc)

