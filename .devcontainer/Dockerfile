FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

# install env tools
RUN apt update && \
	apt install -y \
	git \
	curl \
	bat \
	vim \
	btop \
	xauth \
	x11-apps \
	fish
# C tools
RUN apt install -y \
	build-essential \
	clang \
	gdb \
	valgrind
# Norminette
RUN apt install -y \ 
	python3-pip && \
	python3 -m pip install -U norminette --break-system-packages

# Macrolibx
RUN apt install -y \
	libsdl2-2.0-0 \
	libsdl2-dev \
	mesa-vulkan-drivers \
	libvulkan1 \
	vulkan-tools \
	libx11-dev \
	libxext-dev \
	libxrender-dev \
	libxrandr-dev \
	libbsd-dev \
	xorg

RUN mkdir -p /tmp/runtime-root && chmod 0700 /tmp/runtime-root
ENV XDG_RUNTIME_DIR=/tmp/runtime-root

WORKDIR /workspaces/so_long