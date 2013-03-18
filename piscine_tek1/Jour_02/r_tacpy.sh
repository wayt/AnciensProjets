cat /afs/epitech.net/users/all/astek/public/piscine/passwd | sed '2~2d' | cut -f 1 -d ':' | rev | sort -r | head -42 | tail -n 18 | tr '
' ',' | sed 's/,/, /g' | sed 's/\(.*\), /\1./'
