#!/bin/bash
touch /home/ginter_m/afs/rendu/piscine/Jour_01/find_and_clean_it
chmod 640 /home/ginter_m/afs/rendu/piscine/Jour_01/find_and_clean_it
echo 'find . -type f \( -name "*~" -or -name "#*#" \) -delete' > /home/ginter_m/afs/rendu/piscine/Jour_01/find_and_clean_it
