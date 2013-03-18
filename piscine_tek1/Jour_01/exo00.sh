#!/bin/bash
mkdir /home/ginter_m/afs/public/exo00
cd /home/ginter_m/afs/public/exo00
mkdir test1 test2 test3 test4
fs setacl test1 astek all
fs setacl test2 astek rlidwk
fs setacl test3 astek rl
fs setacl test4 astek a
