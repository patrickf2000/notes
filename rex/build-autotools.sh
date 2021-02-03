#!/bin/bash
cd $REX_ROOT
mkdir rex_build

cd rex_src
./build
cd ../rex_build
#../rex_src/configure --prefix=$REX_ROOT/rex_install --with-boost=/usr --with-boost-libdir=/usr/lib/x86_64-linux-gnu/ --enable-languages=c,c++ --disable-tests-directory --disable-tutorial-directory --with-ompparser=$REX_ROOT/ompparser_install
../rex_src/configure --prefix=$REX_ROOT/rex_install --with-boost=/usr --with-boost-libdir=/usr/lib64/ --enable-languages=c,c++ --disable-tests-directory --disable-tutorial-directory --with-ompparser=$REX_ROOT/ompparser_install
make core -j8

