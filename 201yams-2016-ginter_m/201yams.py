#!/usr/bin/python3

import os, sys

def yams(num, des):
    result = 1.0
    for de in des:
        if de != num:
            result *= 1.0 / 6.0
    print("probabilité d’obtenir un yams de %s : %.2f%%" % (num, round(result * 100.0, 2)))

def full(trois, deux, des):
    result = 1.0
    nb = 0
    for de in des:
        if de == trois:
            nb += 1
    result *= pow(1.0 / 6.0, 3 - (nb > 3 and 3 or nb))
    nb = 0
    for de in des:
        if de == deux:
            nb += 1
    result *= pow(1.0 / 6.0, 2 - (nb > 2 and 2 or nb))
    print("probabilité d’obtenir un full de %s par les %s : %.2f%%" % (trois, deux, round(result * 100.0, 2)))

def paire(num, des):
    count = 0
    chance = 0.0
    for de in des:
        if de == num:
            count += 1
    chance = pow(1.0 / 6.0, 2 - (count > 2 and 2 or count)) * 100.0
    print("probabilité d’obtenir une paire de %s : %.2f%%" % (num, round(chance, 2)))

def brelan(num, des):
    count = 0
    chance = 0.0
    for de in des:
        if de == num:
            count += 1
    chance = pow(1.0 / 6.0, 3 - (count > 3 and 3 or count)) * 100.0
    print("probabilité d’obtenir un brelan de %s : %.2f%%" % (num, round(chance, 2)))

def carre(num, des):
    count = 0
    chance = 0.0
    for de in des:
        if de == num:
            count += 1
    chance = pow(1.0 / 6.0, 4 - (count > 4 and 4 or count)) * 100.0
    print("probabilité d’obtenir un carre de %s : %.2f%%" % (num, round(chance, 2)))

def main():
    if len(sys.argv) != 7:
        print("Bug")
        sys.exit(1)

    des = sys.argv[1:6]
    comb = sys.argv[6].split('_')
    if comb[0] == "yams":
        yams(comb[1], des)
    elif comb[0] == "full":
        full(comb[1], comb[2], des)
    print(des)
    print(comb)

if __name__ == "__main__":
    main()
