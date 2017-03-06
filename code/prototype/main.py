import networkx as nx
import math


def load_digraph_from_file(fn) -> nx.DiGraph:
    g = nx.DiGraph()
    with open(fn, "r") as f:
        lines = f.readlines()
    line_number = 1
    for line in lines[1:]:
        line_number += 1
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
            print("Ошибка ({}:{}): ожидалось число, символ 'p' или 'l', но получено: '{}'"
                  .format(fn, line_number, line[0]))
    return g


def find_root(g: nx.DiGraph):
    if g.number_of_nodes() == 0:
        return None
    root = g.nodes()[0]
    while True:
        p = g.predecessors(root)
        if len(p) == 0:
            return root
        root = p[0]


def inf_for_digraph(g: nx.DiGraph, u, v):
    root = find_root(g)
    du = nx.shortest_path_length(g, root, u)
    dv = nx.shortest_path_length(g, root, v)
    us, vs = {u}, {v}
    flag = False
    while True:
        while len(us) > 0 and (flag or du > dv):
            new_us = set()
            for x in us:
                new_us.update(g.predecessors(x))
            us = new_us
            du -= 1
            flag = False
        while len(vs) > 0 and dv > du:
            new_vs = set()
            for x in vs:
                new_vs.update(g.predecessors(x))
            vs = new_vs
            dv -= 1
        if len(vs) == 0 or len(us) == 0:
            print("Error: inf_for_digraph: len(vs) == 0 or len(us) == 0")
            return None
        uv_intersection = us.intersection(vs)
        if len(uv_intersection) > 1:
            print("Error: inf_for_digraph: len(uv) > 1")
            return None
        elif len(uv_intersection) == 1:
            return next(iter(uv_intersection))
        else:
            flag = True


def to_semi(g: nx.DiGraph):
    n = g.number_of_nodes()
    return [[inf_for_digraph(g, i, j) for j in range(n)] for i in range(n)]


def semi_to_text(s):
    t = ""
    n = len(s)
    template = "%{}d".format(int(math.log10(n)) + 1)
    for l in s:
        t += "%s\n" % " ".join(map(lambda x: template % x, l))
    return t


def is_associative(s):
    n = len(s)
    for x in range(n):
        for y in range(n):
            for z in range(n):
                if s[s[x][y]][z] != s[x][s[y][z]]:
                    return False
    return True


def is_commutativity(s):
    n = len(s)
    for x in range(n):
        for y in range(n):
            if s[x][y] != s[y][x]:
                return False
    return True


def is_idempotence(s):
    n = len(s)
    for x in range(n):
        if s[x][x] != x:
            return False
    return True


def is_valid_semi(s):
    return is_associative(s) and is_commutativity(s) and is_idempotence(s)


def to_digraph(s) -> nx.DiGraph:
    n = len(s)
    root = 0
    g = nx.DiGraph()
    for i in range(n):
        g.add_node(i)
        root = s[root][i]
    level = {root}
    while len(level) > 0:
        new_level = set()
        for x in level:
            for y in range(n):
                if y != x and s[x][y] == x:
                    flag = True
                    for z in range(n):
                        if z != x and z != y and x == s[x][z] and z == s[z][y]:
                            flag = False
                            break
                    if flag:
                        g.add_edge(x, y)
                        new_level.add(y)
        level = new_level
    return g


def digraph_is_tree(g: nx.DiGraph):
    return g.number_of_nodes() - 1 == g.number_of_edges()


def encode_tree(g: nx.DiGraph):
    root = find_root(g)
    def go(v):
        s = "0"
        for u in g.successors(v):
            s += go(u)
        return s + "1"
    return go(root)


def tree_is_isomorphic(t1, t2):
    return encode_tree(t1) == encode_tree(t2)


# TODO: !!!
def find_branches_of_digraph(g: nx.DiGraph):
    branches = []
    root = find_root(g)
    def vertexes_of_subgraph_with_root(v):
        t = {v}
        for u in g.successors(v):
            t.update(vertexes_of_subgraph_with_root(u))
        return t
    for v in g.successors(root):
        t = vertexes_of_subgraph_with_root(v)
        for
    return branches


def semilattices_is_isomorphic(s1, s2):
    g1 = to_digraph(s1)
    g2 = to_digraph(s2)
    n = g1.number_of_nodes()
    if n != g2.number_of_nodes() or g1.number_of_edges() != g2.number_of_edges():
        return False
    if digraph_is_tree(g1) and digraph_is_tree(g2):
        return tree_is_isomorphic(g1, g2)
    g1_branches = []


g = load_digraph_from_file('3.dig')
s = to_semi(g)
# print(s)
print(is_valid_semi(s))
print(semi_to_text(s))

g2 = to_digraph(s)
print("nx.is_isomorphic(g, g2) ==", nx.is_isomorphic(g, g2))

# print(inf_for_digraph(g, 10, 8))
# print(g.number_of_nodes())
# print(g.edges())
# print(find_root(g))
