import sys, os, shutil
from subprocess import call

def ff(n):
    with open("semilattices/cay{}.txt".format(n), "r") as f:
        s = ""
        for c in iter(lambda: f.read(1), ''):
            if c.isdigit():
                s += c
    return s

with open("semilattices_1_8.txt", "w") as f:
    for i in range(1, 9):
        f.write(ff(i) + "\n")
