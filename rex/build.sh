#!/bin/bash
cd $REX_ROOT
mkdir rex_build
cd rex_build
cmake ../rex_src -DOMPPARSER_PATH=$REX_ROOT/ompparser_install
make -j12
