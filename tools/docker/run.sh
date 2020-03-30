sudo docker run --rm -ti \
                -v "${HOME}/.Xauthority:/root/.Xauthority:rw" \
                -v "$(pwd)/../../../:/home/docker:rw" \
                --env="DISPLAY" \
                --hostname airliner \
                --cap-add=SYS_ADMIN \
                --security-opt apparmor:unconfined \
                --net=bridge \
                -p 3000:3000/udp \
                airliner:0.0.1 \
                /usr/bin/supervisord
