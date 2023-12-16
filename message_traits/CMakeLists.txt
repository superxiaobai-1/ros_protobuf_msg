

set(traits_files
${CMAKE_CURRENT_SOURCE_DIR}/include/ros/*
)


add_custom_target(copy_traits_files
  COMMAND ${CMAKE_COMMAND} -E copy ${traits_files} /opt/ros/noetic/include/ros/
)

# install(DIRECTORY include/
#   DESTINATION /opt/ros/noetic/include/
#   FILES_MATCHING PATTERN "*.h")
