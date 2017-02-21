import sys

if len(sys.argv) < 2:
    print("Error: too few arguments.")
    sys.exit(1)

dx1, dy1 = -3, 1
dx2, dy2 = 2, 2
dx3, dy3 = 1, 5.1

x, y = 20, 0
scale = 0.35

res = []

for i in range(3):
    for j in range(2):
        for k in range(3):
            res.append((x + i*dx3 + j*dx2 + k*dx1, y + i*dy3 + j*dy2 + k*dy1))

poss = []

for i, (x, y) in enumerate(res):
    x *= scale
    y *= scale
    poss.append('{} [ pos = "{:.2f},{:.2f}!" ]'.format(i, x, y))

poss = "\n".join(poss)
# print(poss)

res = """digraph {
/*
node [ shape=circle, fixedsize=true, width=0.37 ]
*/
node [ shape=circle ]
edge [ arrowhead=none ]
0 -> {1; 3; 6;}
1 -> {2; 4; 7;}
2 -> {5; 8;}
3 -> {4; 9;}
4 -> {5; 10;}
5 -> 11
6 -> {7; 9; 12;}
7 -> {8; 10; 13;}
8 -> {14; 11;}
9 -> {10; 15;}
10 -> {11; 16;}
11 -> 17
12 -> {13; 15}
13 -> {14; 16}
14 -> 17
15 -> 16
16 -> 17
%s
}
""" % poss

# print(res)

with open(sys.argv[1], "w") as f:
    f.write(res)
