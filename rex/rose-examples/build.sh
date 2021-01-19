#!/bin/bash
g++ $1.cpp -o $1 -I$HOME/passlab/install/include/rose -L$HOME/passlab/install/lib -lrose -lboost_system -lboost_chrono
echo "Done"
