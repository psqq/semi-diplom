import networkx as nx
import sys

def load_from_file(fn):
    g = nx.DiGraph()
    with open(fn, "r") as f:
        lines = f.readlines()
    for line in lines[1:]:
        ws = line.split()
        if line[0] == "l":
            v = int(ws[1])
            for u in map(int, ws[2:]):
                g.add_edge(v, u)
        elif line[0] == "p" or line[0].isdigit():
            i = 0
            if line[0] == "p":
                i = 1
            a = list(map(int, ws[i:]))
            for i in range(len(a) - 1):
                g.add_edge(a[i], a[i+1])
        else:
            print("Ошибка: ожидалось число, символ 'p' или 'l', но получено: '{}'".format(line[0]))
    return g

fn1 = sys.argv[1]
fn2 = sys.argv[2]

g1 = load_from_file(fn1)
g2 = load_from_file(fn2)

print(1 if nx.is_isomorphic(g1, g2) else 0)
