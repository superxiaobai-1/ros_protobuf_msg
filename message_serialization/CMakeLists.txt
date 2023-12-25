
# project(roscpp_serialization)
# find_package(catkin REQUIRED COMPONENTS cpp_common roscpp_traits rostime)
# catkin_package(
#   INCLUDE_DIRS include
#   LIBRARIES roscpp_serialization
#   CATKIN_DEPENDS cpp_common roscpp_traits rostime
# )

include_directories(include ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})
# include_directories(message_serialization/ros)

add_library(roscpp_proto_serialization src/serialization.cpp)

install(TARGETS roscpp_proto_serialization
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

message("!!!!!!!!!!!!!!!!!!!!!!")
message("var = ${CMAKE_CURRENT_SOURCE_DIR}")

set(files_to_install
${CMAKE_CURRENT_SOURCE_DIR}/include/ros/*
)


add_custom_target(copy_serialization_files
  COMMAND ${CMAKE_COMMAND} -E copy ${files_to_install} /opt/ros/noetic/include/ros/
)



# install(DIRECTORY include/
#   DESTINATION /opt/ros/melodic/include/
#   FILES_MATCHING PATTERN "*.h")
