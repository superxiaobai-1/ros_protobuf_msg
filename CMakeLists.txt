cmake_minimum_required(VERSION 3.10)
project(myproject)

# Build the talker and listener. Each one uses the following ROS packages,
# which we need to find_package() individually:
#   roscpp (the client library)
#   std_msgs (contains the std_msgs/String message type)
find_package(catkin REQUIRED COMPONENTS
  roscpp_traits rostime
  roscpp
  roslib)

catkin_package()
# catkin_package(
#   INCLUDE_DIRS include
#   CATKIN_DEPENDS cpp_common rostime)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

# We've found them; now use their variables in the usual way to configure
# the compile and link steps.
# Note: we skip calling link_directories() because ROS packages follow the
# recommended CMake practice of returning absolute paths to libraries
add_subdirectory(message_traits)
add_subdirectory(message_serialization)
add_subdirectory(sample_protos)
# add_subdirectory(roscpp)

include_directories(${roscpp_INCLUDE_DIRS})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pb_talker pb_talker.cpp
)

add_dependencies(pb_talker copy_traits_files copy_serialization_files)

target_link_libraries(pb_talker 
${roscpp_LIBRARIES} 
pb_proto
roscpp_proto_serialization
)


add_executable(pb_listener pb_listener.cpp)
target_link_libraries(pb_listener 
${roscpp_LIBRARIES} 
pb_proto
roscpp_proto_serialization
)
add_dependencies(pb_listener copy_traits_files copy_serialization_files)

add_executable(talker talker.cpp)
target_link_libraries(talker ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES})

add_executable(listener listener.cpp)
target_link_libraries(listener ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES})

# (optional) Install the executables.
install(TARGETS talker listener
        DESTINATION bin)

# # (optional) Install the executables.
# install(TARGETS talker listener
#         DESTINATION bin)

# install(TARGETS pb_talker pb_listener 
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

message("!!!!!!!!!!!!!!")
message("pb = ${CMAKE_CURRENT_SOURCE_DIR}")
message("${CATKIN_DEVEL_PREFIX}")
message("${CATKIN_PACKAGE_ETC_DESTINATION}")


execute_process(COMMAND cmake -E create_symlink ${CATKIN_DEVEL_PREFIX}
${CMAKE_CURRENT_SOURCE_DIR}/devel)
        