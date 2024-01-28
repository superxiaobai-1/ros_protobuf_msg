# find_package(protobuf CONFIG REQUIRED)
# find_package(Threads)
find_package(Protobuf REQUIRED)
#
# Protobuf/Grpc source files
#
set(PROTO_FILES
    publish_info.proto
    
)

#
# Add Library target with protobuf sources
#
add_library(pb_proto ${PROTO_FILES})
target_link_libraries(pb_proto
    PUBLIC
        protobuf::libprotobuf
        # gRPC::grpc
        # gRPC::grpc++
)
target_include_directories(pb_proto PUBLIC
${PROTOBUF_INCLUDE_DIRS} 
${CMAKE_CURRENT_BINARY_DIR})

#
# Compile protobuf and grpc files in mointor proto target to cpp
#
# get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET pb_proto LANGUAGE cpp)
# 使用protoc 
# protobuf_generate(TARGET pb_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")