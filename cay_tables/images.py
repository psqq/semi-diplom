import sys, os
from subprocess import call

semilattice_filename = "/tmp/semilattice.txt"
digraph_filename = "/tmp/digraph.txt"
dot_filename = "/tmp/digraph.dot"
img_filename = "/tmp/digraph.png"
output_directory = "images"

def make_images(n):
    with open("semilattices/cay{}.txt".format(n), "r") as f:
        lines = f.readlines()
    i = 0
    s = [None] * n
    for line in lines:
        line = line.strip()
        if len(line) == 0:
            continue
        s[i] = line
        i += 1
        if i < n:
            continue
        i = 0
        with open(semilattice_filename, "w") as f:
            f.write("\n".join(s) + "\n")
        call("./semi tog {} {}".format(semilattice_filename, digraph_filename), shell=True)
        call("./semi todot {} {}".format(semilattice_filename, digraph_filename), shell=True)
        call("dot -Tpng -o {} {}".format(dot_filename, img_filename), shell=True)
        print(s)

if not os.path.exists(output_directory):
    os.makedirs(output_directory)

for arg in sys.argv[1:]:
    make_images(int(arg))
