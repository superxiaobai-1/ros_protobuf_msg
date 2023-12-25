#!/usr/bin/env bash

set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

THREAD_NUM=$(nproc)

# https://github.com/protocolbuffers/protobuf/releases/download/v3.14.0/protobuf-cpp-3.14.0.tar.gz
# Install proto.
VERSION="3.14.0"
PKG_NAME="protobuf-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd protobuf-${VERSION}
    mkdir cmake/build && cd cmake/build

    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -Dprotobuf_BUILD_TESTS=OFF \
        -DCMAKE_INSTALL_PREFIX:PATH="/usr/local" \
        -DCMAKE_BUILD_TYPE=Release

    make -j$(nproc)
    make install
popd

ldconfig

# Clean up
rm -rf PKG_NAME protobuf-${VERSION}
