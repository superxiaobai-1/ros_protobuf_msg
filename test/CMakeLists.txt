cmake_minimum_required(VERSION 3.10)
project(test)

include_directories(
  include
)

add_subdirectory(proto)

add_executable(test_temple test_template.cc)

add_executable(test_sfinae sfinae_test.cc)

add_executable(test_proto  test_proto.cpp)

target_link_libraries(test_proto 
proto_test
)