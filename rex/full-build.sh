#!/bin/bash
cd $REX_ROOT
git clone -b dev git@github.com:passlab/ompparser.git
git clone -b dev git@github.com:passlab/rexompiler.git rex_src

cd rex_src
git submodule update --init
cd ..

cd ompparser
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../../ompparser_install ..
make -j12
make install

cd $REX_ROOT
mkdir rex_build

cd rex_build
cmake ../rex_src -DOMPPARSER_PATH=$REX_ROOT/ompparser_install

make -j12

echo ""
echo "Done"
echo ""

