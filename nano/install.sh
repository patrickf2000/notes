#!/bin/bash

cp ./nanorc $HOME/.nanorc

if [[ ! -d $HOME/.nano ]] ; then
    mkdir -p $HOME/.nano
fi
cp -r ./syntax/* $HOME/.nano/

echo "Done"
