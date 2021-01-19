#!/bin/bash

BACKUP="/run/media/patrick/31a7bfe4-8116-4b3c-95f8-8bd735e757d4/xps-dev-main"

if [[ ! -d $BACKUP ]] ; then
    mkdir $BACKUP
fi

rsync -av --delete $HOME/Arduino $BACKUP
rsync -av --delete $HOME/Desktop $BACKUP
rsync -av --delete $HOME/Documents $BACKUP
rsync -av --delete $HOME/Downloads $BACKUP
rsync -av --delete $HOME/opt $BACKUP
rsync -av --delete $HOME/passlab $BACKUP
rsync -av --delete $HOME/Projects $BACKUP
rsync -av --delete $HOME/Projects_Github $BACKUP
rsync -av --delete $HOME/Projects_Gitlab $BACKUP
rsync -av --delete $HOME/Projects_snippets $BACKUP
rsync -av --delete $HOME/scripts $BACKUP

echo ""
echo "Done"

