#!/bin/bash
sudo docker run --rm -ti \
                -v "${HOME}/.Xauthority:/root/.Xauthority:rw" \
                --env="DISPLAY" \
                --hostname airliner \
                --cap-add=SYS_ADMIN \
                airliner:0.0.1 \
                bash
