import sys

import networkx as nx
from networkx.drawing.nx_pydot import write_dot


default_graph = {
    'node': {
        'shape': 'circle'
    },
    'edge': {
        'arrowhead': 'none'
    },
    'graph': {
        'rankdir': 'BT'
    }
}


def load_from_file(fn):
    g = nx.DiGraph(**default_graph)
    with open(fn, "r") as f:
        lines = f.readlines()
    for line in lines:
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
                g.add_edge(a[i], a[i + 1])
        else:
            print("Ошибка: ожидалось число, символ 'p' или 'l', но получено: '{}'".format(
                line[0]))
    return g


g = load_from_file("a.txt")

for n in g.nodes():
    g.node[n]['label'] = ''

write_dot(g, "a.dot")
