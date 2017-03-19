from digraph import *
from semi import *

n = 10
vs = []
k = 0
for i in range(n):
    l = []
    for j in range(n):
        l.append(k)
        k += 1
    vs.append(l)
# print(vs)

g = nx.DiGraph()
for i in range(n):
    for j in range(n):
        if i < n - 1:
            g.add_edge(vs[i][j], vs[i + 1][j])
        if j < n - 1:
            g.add_edge(vs[i][j], vs[i][j + 1])

# print(g.nodes(), g.edges(), sep='\n')
s = to_semi(g)
# print(is_valid_semi(s))
s_text = semi_to_text(s)
# print(semi_to_text(s))
with open("sqsemi.txt", "w") as f:
    f.write(s_text)

# print(load_semi_from_file("semi.txt"))

# g = load_digraph_from_file('1.dig')
# s = to_semi(g)
# G1, G2 = find_G1_and_G2_graphs(g)
#
# print("is_valid_semi", is_valid_semi(s))
# print(semi_to_text(s), end="")
# print("branches", find_branches_of_digraph(g))
# print("G1", G1.nodes(), G1.edges())
# print("G2", G2.nodes(), G2.edges())
#
# g2 = to_digraph(s)
# print("nx.is_isomorphic(g, g2) ==", nx.is_isomorphic(g, g2))

# print(inf_for_digraph(g, 10, 8))
# print(g.number_of_nodes())
# print(g.edges())
# print(find_root(g))
