dx1, dy1 = -3, 1
dx2, dy2 = 2, 2
dx3, dy3 = 1, 5.1

x, y = 20, 0
scale = 0.3

res = []

for i in range(3):
    for j in range(2):
        for k in range(3):
            res.append((x + i*dx3 + j*dx2 + k*dx1, y + i*dy3 + j*dy2 + k*dy1))

for i, (x, y) in enumerate(res):
    x *= scale
    y *= scale
    print('{} [ pos = "{:.2f},{:.2f}!" ]'.format(i, x, y))
