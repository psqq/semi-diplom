from digraph import *
from semi import *

print(load_semi_from_file("semi.txt"))

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
