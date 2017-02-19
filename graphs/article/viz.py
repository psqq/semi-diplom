from networkx.drawing.nx_pydot import read_dot
import sys
import collections
from PIL import Image, ImageDraw

in_ = sys.argv[1]
g = read_dot(in_)

print(g.nodes())
print(g.edges())
print(g.node)
print(g.graph)
print(dir(g))

im = Image.new("RGB", (320,320), (255,255,255))
d = ImageDraw.Draw(im)

for n in g.nodes():
    x, y = list(map(int, g.node[n]['pospx'][1:-1].split()))
    d.ellipse((x, y, x + 30, y + 30), outline=(0,0,0), width=3)

del d
im.save("test.png", "PNG")
