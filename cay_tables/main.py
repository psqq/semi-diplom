import sys, os, shutil
from subprocess import call


def read_semilattices_as_string(n):
    with open("semilattices/cay{}.txt".format(n), "r") as f:
        s = ""
        for c in iter(lambda: f.read(1), ''):
            if c.isdigit():
                s += c
    return s


def write_all_semilattices_to_1_file():
    with open("semilattices_1_8.txt", "w") as f:
        for i in range(1, 9):
            f.write(ff(i) + "\n")


def semilattices_list(n):
    with open("semilattices_1_8.txt", "r") as f:
        s = f.readlines()[n-1].strip()
    nn = n * n
    return [ s[i:i+nn] for i in range(0, len(s), nn) ]


def semi(cmd, s):
    tmp_file_in = "/tmp/in.txt"
    tmp_file_out = "/tmp/out.txt"
    with open(tmp_file_in, "w") as f:
        f.write(" ".join(list(s)) + "\n")
    call("semi {} {} {}".format(cmd, tmp_file_in, tmp_file_out), shell=True)
    with open(tmp_file_out, "r") as f:
        return f.read().strip()


def inv3_for_semilattice(s):
    return semi("inv3", s)


def inv3_for_semilattice(s):
    tmp_file_in = "/tmp/s.txt"
    tmp_file_out = "/tmp/inv3.txt"
    with open(tmp_file_in, "w") as f:
        f.write(" ".join(list(s)))
    call("semi inv3 {} {}".format(tmp_file_in, tmp_file_out), shell=True)
    with open(tmp_file_out, "r") as f:
        return f.read().strip()


# print(inv3_for_semilattice(semilattices_list(2)[0]))


def find_semilattices_with_equal_inv3():
    for n in range(1, 9):
        m = dict()
        for s in semilattices_list(n):
            inv3 = inv3_for_semilattice(s)
            if inv3 not in m:
                m[inv3] = []
            m[inv3].append(s)
        maxlen = 0
        maxinv3 = ""
        for k in m:
            if len(m[k]) > maxlen:
                maxlen = len(m[k])
                maxinv3 = k
        print(n, maxlen, repr(maxinv3), m[maxinv3])


# find_semilattices_with_equal_inv3()
"""
1 1 '0, 0, 0, (0);' ['1']
2 1 '0, 0, 1, (1); 1, 1, 0, (0);' ['1112']
3 1 '0, 0, 2, (1, 1); 1, 1, 0, (0, 2); 1, 1, 0, (0, 2);' ['111121113']
4 1 '0, 0, 2, (1, 2); 1, 1, 0, (0, 3); 1, 1, 1, (1, 2); 2, 1, 0, (0, 3);' ['1111121111331134']
5 1 '0, 0, 2, (1, 3); 1, 1, 0, (0, 4); 1, 1, 1, (2, 2); 2, 1, 1, (1, 3); 3, 1, 0, (0, 4);' ['1111112111113331134411345']
6 1 '0, 0, 5, (1, 1, 1, 1, 1); 1, 1, 0, (0, 2, 2, 2, 2); 1, 1, 0, (0, 2, 2, 2, 2); 1, 1, 0, (0, 2, 2, 2, 2); 1, 1, 0, (0, 2, 2, 2, 2); 1, 1, 0, (0, 2, 2, 2, 2);' ['111111121111113111111411111151111116']
7 1 '0, 0, 2, (2, 3); 1, 1, 1, (3, 3); 1, 1, 2, (1, 2); 2, 1, 0, (0, 3); 2, 1, 1, (2, 3); 2, 2, 1, (1, 2); 3, 1, 0, (0, 3);' ['1111111121122211331331134133121155512335661233567']
8 2 '0, 0, 4, (2, 2); 1, 1, 1, (1, 3); 1, 1, 1, (1, 3); 1, 1, 1, (1, 3); 1, 1, 2, (1, 2); 2, 1, 1, (1, 2); 2, 2, 0, (0, 3); 2, 3, 0, (0, 3);' ['1111111112111112113111131114114111115555111156561114557512315658', '1111111112111112113111131114114111115555111156651114567512315558']
1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 1 3 1 1 1 4 1 1 4 1 1 1 1 1 5 5 5 5 1 1 1 1 5 6 5 6 1 1 1 4 5 5 7 5 1 2 3 1 5 6 5 8
1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 1 3 1 1 1 4 1 1 4 1 1 1 1 1 5 5 5 5 1 1 1 1 5 6 6 5 1 1 1 4 5 6 7 5 1 2 3 1 5 5 5 8
"""


def count_trees():
    for n in range(1, 9):
        c = 0
        for s in semilattices_list(n):
            if semi("istree", s) == "1":
                c += 1
        print(n, c)

# count_trees()

"""
1 1
2 1
3 2
4 4
5 9
6 20
7 48
8 115
"""

def find_semilattices_with_equal_ccode():
    for n in range(1, 9):
        m = dict()
        for s in semilattices_list(n):
            # print(s)
            inv3 = semi("ccode", s)
            if inv3 not in m:
                m[inv3] = []
            m[inv3].append(" ".join(list(s)))
        maxlen = 0
        maxinv3 = ""
        for k in m:
            if len(m[k]) > maxlen:
                maxlen = len(m[k])
                maxinv3 = k
        print(n, maxlen, repr(maxinv3), m[maxinv3])

# find_semilattices_with_equal_ccode()

"""
1 1 '01' ['1']
2 1 '0011' ['1 1 1 2']
3 1 '001011' ['1 1 1 1 2 1 1 1 3']
4 1 '00010111' ['1 1 1 1 1 2 2 2 1 2 3 2 1 2 2 4']
5 1 '00011001100111' ['1 1 1 1 1 1 2 1 1 2 1 1 3 1 3 1 1 1 4 4 1 2 3 4 5']
6 2 '0001011001100111' ['1 1 1 1 1 1 1 2 1 1 1 2 1 1 3 1 1 3 1 1 1 4 4 4 1 1 1 4 5 4 1 2 3 4 4 6', '1 1 1 1 1 1 1 2 1 1 1 2 1 1 3 1 3 1 1 1 1 4 4 4 1 1 3 4 5 4 1 2 1 4 4 6']
7 3 '000011011001100111' ['1 1 1 1 1 1 1 1 2 1 1 1 1 2 1 1 3 1 1 1 3 1 1 1 4 4 4 4 1 1 1 4 5 4 4 1 1 1 4 4 6 6 1 2 3 4 4 6 7', '1 1 1 1 1 1 1 1 2 1 1 1 1 2 1 1 3 1 1 1 3 1 1 1 4 4 4 4 1 1 1 4 5 5 4 1 1 1 4 5 6 4 1 2 3 4 4 4 7', '1 1 1 1 1 1 1 1 2 1 1 1 1 2 1 1 3 1 1 3 1 1 1 1 4 4 4 4 1 1 1 4 5 4 5 1 1 3 4 4 6 4 1 2 1 4 5 4 7']
8 6 '00001101100101100111' ['1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 3 3 1 1 1 4 4 4 1 4 1 1 1 4 5 4 1 4 1 1 1 4 4 6 1 6 1 1 3 1 1 1 7 3 1 2 3 4 4 6 3 8', '1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 3 3 1 1 1 4 4 4 1 4 1 1 1 4 5 5 1 4 1 1 1 4 5 6 1 4 1 1 3 1 1 1 7 3 1 2 3 4 4 4 3 8', '1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 3 3 1 1 1 4 4 4 4 1 1 1 1 4 5 4 4 1 1 1 1 4 4 6 6 1 1 1 3 4 4 6 7 3 1 2 3 1 1 1 3 8', '1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 1 3 3 1 1 1 4 4 4 4 1 1 1 1 4 5 5 4 1 1 1 1 4 5 6 4 1 1 1 3 4 4 4 7 3 1 2 3 1 1 1 3 8', '1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 3 3 1 1 1 1 4 4 1 4 4 1 1 1 4 5 1 4 5 1 1 3 1 1 6 3 1 1 1 3 4 4 3 7 4 1 2 1 4 5 1 4 8', '1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 2 1 1 3 1 1 3 3 1 1 1 1 4 4 1 4 4 1 1 1 4 5 1 5 4 1 1 3 1 1 6 3 1 1 1 3 4 5 3 7 4 1 2 1 4 4 1 4 8']
"""

def find_semilattices_with_equal_ccode_and_inv3():
    for n in range(1, 9):
        m = dict()
        for s in semilattices_list(n):
            # print(s)
            ccode = semi("ccode", s)
            inv3 = semi("inv3", s)
            p = (ccode, inv3)
            if inv3 not in m:
                m[p] = []
            m[p].append(" ".join(list(s)))
        maxlen = 0
        maxkey = ""
        for k in m:
            if len(m[k]) > maxlen:
                maxlen = len(m[k])
                maxkey = k
        print(n, maxlen, repr(maxkey), m[maxkey])

find_semilattices_with_equal_ccode_and_inv3()

"""
"""
