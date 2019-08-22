#Airliner Dockerfile
#
# https://github.com/WindhoverLabs/airliner
#

# Pull base image
FROM ubuntu:16.04

MAINTAINER Casey Nalley <cnalley@windhoverlabs.com>

# Install dependencies for getting keys and adding sources
RUN \
  apt-get update && \
  apt-get install -y ca-certificates && \
  apt-get install -y wget && \
  apt-get install -y curl

# Install sources
RUN \
 echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable xenial main" > /etc/apt/sources.list.d/gazebo-stable.list

# Add keys
RUN wget http://packages.osrfoundation.org/gazebo.key
RUN apt-key add gazebo.key

# Update
RUN apt-get update

# Install Python 
RUN \
  apt-get install -y python-jinja2 && \
  apt-get install -y python-empy && \
  apt-get install -y python-pip && \
  apt-get install -y python-dev && \
  apt-get install -y cookiecutter

# Install python packages
RUN \
  pip install virtualenv && \
  pip install catkin_pkg && \
  pip install merge-json && \
  pip install --upgrade cookiecutter

# Install gazebo
RUN \ 
  apt-get install -y gazebo8 && \
  apt-get install -y libgazebo8 && \
  apt-get install -y libgazebo8-dev

# Install Node LTS 6
RUN curl -sL https://deb.nodesource.com/setup_6.x | bash -


# Install packages
RUN \
  ##sed -i 's/# \(.*multiverse$\)/\1/g' /etc/apt/sources.list && \
  apt-get install -y cmake && \
  apt-get install -y make && \
  apt-get install -y protobuf-compiler && \
  apt-get install -y python-protobuf && \
  apt-get install -y doxygen && \
  apt-get install -y g++-multilib && \
  apt-get install -y gcc-multilib && \
  apt-get install -y graphviz && \
  apt-get install -y libeigen3-dev && \
  apt-get install -y libopencv-dev && \
  apt-get install -y valgrind && \
  apt-get install -y libimage-exiftool-perl && \
  apt-get install -y catkin && \
  apt-get install -y build-essential && \
  apt-get install -y flex && \
  apt-get install -y bison && \
  apt-get install -y libncurses5-dev && \
  apt-get install -y libc6-dbg && \
  apt-get install -y gstreamer1.0-plugin* && \  
  apt-get install -y libgstreamer1.0-* && \  
  apt-get install -y wget && \  
  apt-get install -y curl && \  
  apt-get install -y git && \  
  apt-get install -y vim && \  
  apt-get install -y htop && \  
  apt-get install -y unzip && \  
  apt-get install -y man && \  
  apt-get install -y software-properties-common && \
  apt-get install -y tmux && \
  apt-get install -y valgrind && \
  apt-get install -y gcovr && \
  apt-get install -y lcov && \
  apt-get install -y xsltproc && \
  # apt-get install -y npm && \
  apt-get install -y nodejs && \
  apt-get install -y default-jre && \
  apt-get install -y default-jdk && \
  apt-get install -y python3-pip && \
  rm -rf /var/lib/apt/lists/*

# Install npm packages
#RUN \
#  npm install -g n

# Update node with n to version 6
#RUN n 6

# Pull down repos
RUN \
  git clone https://github.com/WindhoverLabs/airliner.git

# Install commander packages
RUN \
  cd /airliner/tools/commander && \
  npm install

# Build sitl flight software
RUN \
  cd /airliner && \
  make typhoon_h480/sitl

# Make ground tools
RUN \
  cd /airliner/build/typhoon_h480/sitl && \
  make ground_tools

# Expose commander port
EXPOSE 3000/udp

# Set environment variables.
ENV HOME /root

# Define working directory.
WORKDIR /root

# Define default command.
CMD ["bash"]
