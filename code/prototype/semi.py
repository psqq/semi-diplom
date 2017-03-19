from digraph import *
import math


def to_semi(g: nx.DiGraph):
    n = g.number_of_nodes()
    return [[inf_for_digraph(g, i, j) for j in range(n)] for i in range(n)]


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


def semi_to_text(s):
    t = ""
    n = len(s)
    template = "%{}d".format(int(math.log10(n)) + 1)
    for l in s:
        t += "%s\n" % " ".join(map(lambda x: template % x, l))
    return t


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


def semilattices_is_isomorphic(s1, s2):
    g1 = to_digraph(s1)
    g2 = to_digraph(s2)
    n = g1.number_of_nodes()
    if n != g2.number_of_nodes() or g1.number_of_edges() != g2.number_of_edges():
        return False
    g1_is_tree = digraph_is_tree(g1)
    if g1_is_tree != digraph_is_tree(g2):
        return False
    if g1_is_tree:
        return tree_is_isomorphic(g1, g2)
    g1_G1, g1_G2 = find_G1_and_G2_graphs(g1)
    g2_G1, g2_G2 = find_G1_and_G2_graphs(g2)
    if not tree_is_isomorphic(g1_G1, g2_G1) or not tree_is_isomorphic(g1_G2, g2_G2):
        return False


def load_semi_from_file(filename: str):
    ws = []
    with open(filename, "r") as f:
        for line in f.readlines():
            ws += line.split()
    n = int(math.sqrt(len(ws)) + 1e-5)
    if n*n != len(ws):
        return None
    elems = list(set(ws))
    if len(elems) != n:
        return None
    ws = list(map(int, ws))
    s = [ws[i:i+n] for i in range(0, n*n, n)]
    if not is_valid_semi(s):
        print("load_semi_from_file: Semi is not valid!")
        return None
    return s
