#!/bin/bash
sudo dnf -y install \
    java-1.8.0-openjdk \
    java-1.8.0-openjdk-devel

sudo dnf -y install \
    autoconf \
    automake \
    libtool-ltdl-devel \
    bc \
    binutils \
    bison \
    gcc \
    g++ \
    cmake \
    curl \
    dtc \
    dkms \
    doxygen \
    flex \
    gawk \
    glibc-devel \
    gdb \
    gfortran \
    ghostscript \
    git \
    gperf \
    graphviz \
    boost-devel \
    gmp-devel \
    libharu-devel \
    libmpc-devel \
    mpfr-devel \
    libomp-devel \
    libtool \
    libxml2-devel \
    patchutils \
    perl-doc \
    python3-devel \
    sqlite \
    texinfo \
    unzip \
    wget \
    zip \
    zlib \
    zlib-devel
    
sudo ln -s /usr/bin/bison /usr/bin/yacc

