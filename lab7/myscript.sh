#!/bin/bash
toBeCopied=README.md
copiedTo=~/zhuocaili_CS5008/lab7/
TIME_STAMP="$(date). by $USER"

read -p "Are your sure to copy $toBeCopied to $copiedTo?" -n 1 -r

if [[ $REPLY =~ ^[Yy]$ ]]; then
  cd ~/zhuocaili_CS5008/resources/resources/lab7/
  cp -r $toBeCopied $copiedTo
  echo "Copied folder from $toBeCopied to $copiedTo at $TIME_STAMP"
fi
