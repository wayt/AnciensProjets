#!/bin/bash
mkdir /home/ginter_m/afs/rendu/piscine
mkdir /home/ginter_m/afs/rendu/piscine/Jour_01
touch /home/ginter_m/afs/rendu/piscine/Jour_01/midLS
echo 'ls --format=across -p --format=commas' > /home/ginter_m/afs/rendu/piscine/Jour_01/midLS
chmod 750 /home/ginter_m/afs/rendu/piscine/Jour_01/midLS
