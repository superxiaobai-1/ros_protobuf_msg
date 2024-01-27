# find_package(protobuf CONFIG REQUIRED)
# find_package(Threads)
find_package(Protobuf REQUIRED)
#
# Protobuf/Grpc source files
#
set(PROTO_FILES
    superbai.proto
    
)

#
# Add Library target with protobuf sources
#
add_library(proto_test ${PROTO_FILES})
target_link_libraries(proto_test
    PUBLIC
        protobuf::libprotobuf
        # gRPC::grpc
        # gRPC::grpc++
)
target_include_directories(proto_test PUBLIC
${PROTOBUF_INCLUDE_DIRS} 
${CMAKE_CURRENT_BINARY_DIR})

#
# Compile protobuf and grpc files in mointor proto target to cpp
#
# get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET proto_test LANGUAGE cpp)
# protoc -I$SRC_DIR --cpp_out=$DST_DIR superbai.proto
# 使用protoc 
# protobuf_generate(TARGET pb_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")