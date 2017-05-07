import sys, os, shutil
from subprocess import call

# Print iterations progress
def printProgressBar (iteration, total, prefix = '', suffix = '', decimals = 1, length = 100, fill = '█'):
    """
    Call in a loop to create terminal progress bar
    @params:
        iteration   - Required  : current iteration (Int)
        total       - Required  : total iterations (Int)
        prefix      - Optional  : prefix string (Str)
        suffix      - Optional  : suffix string (Str)
        decimals    - Optional  : positive number of decimals in percent complete (Int)
        length      - Optional  : character length of bar (Int)
        fill        - Optional  : bar fill character (Str)
    """
    percent = ("{0:." + str(decimals) + "f}").format(100 * (iteration / float(total)))
    filledLength = int(length * iteration // total)
    bar = fill * filledLength + '-' * (length - filledLength)
    print('\r%s |%s| %s%% %s' % (prefix, bar, percent, suffix), end = '\r')
    # Print New Line on Complete
    if iteration == total:
        print()

semilattice_filename = "/tmp/semilattice.txt"
digraph_filename = "/tmp/digraph.txt"
dot_filename = "/tmp/digraph.dot"
img_filename = "/tmp/digraph.png"
output_directory = "images"

count_semilattices = [0, 1, 1, 2, 5, 15, 53, 222]

def make_images(n):
    with open("semilattices/cay{}.txt".format(n), "r") as f:
        lines = f.readlines()
    i = 0
    k = 0
    s = [None] * n
    l = count_semilattices[n]
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
        cmd1 = "./semi tog {} {}".format(semilattice_filename, digraph_filename)
        call(cmd1, shell=True)
        cmd2 = "./semi todot {} {}".format(digraph_filename, dot_filename)
        call(cmd2, shell=True)
        cmd3 = "dot -Tpng {} -o {}".format(dot_filename, img_filename)
        call(cmd3, shell=True)
        # print(cmd1, cmd2, cmd3, sep="\n")
        k += 1
        shutil.copyfile(img_filename, output_directory + "/{:02}{:08}.png".format(n, k))
        printProgressBar(k, l, prefix = 'Progress:', suffix = 'Complete', length = 50)

if not os.path.exists(output_directory):
    os.makedirs(output_directory)

for arg in sys.argv[1:]:
    print("Find all images for semilattices order {}:".format(arg))
    make_images(int(arg))
    print()
