#!/usr/bin/env bash

set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

#https://github.com/abseil/abseil-cpp/archive/refs/tags/20230802.0.tar.gz
# Install abseil.
THREAD_NUM=$(nproc)
VERSION="20230802.0"
PKG_NAME="abseil-cpp-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd "abseil-cpp-${VERSION}"
    mkdir build && cd build
    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_CXX_STANDARD=14 \
        -DCMAKE_INSTALL_PREFIX=/usr/local
    make -j${THREAD_NUM}
    make install
popd

ldconfig

# Clean up
rm -rf "abseil-cpp-${VERSION}" "${PKG_NAME}"
