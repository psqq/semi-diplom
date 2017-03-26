import networkx as nx
from networkx.drawing.nx_pydot import read_dot
import sys

g = read_dot("a.dot")
print("nodes", g.nodes())
print("edges", g.edges())
print("graph", g.graph)
print("node", g.node)
