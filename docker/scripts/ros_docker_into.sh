#!/usr/bin/env bash

xhost +local:root 1>/dev/null 2>&1
docker exec \
    -u root \
    -it ros_noetic_proto \
    /bin/bash
xhost -local:root 1>/dev/null 2>&1
