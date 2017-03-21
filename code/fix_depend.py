import re

with open(".depend", "r") as f:
    lines = []
    for line in f.readlines():
        lines.append(re.sub(r'(\w*)\.o', r'obj/\1.o', line))

# print("".join(lines))

with open(".depend", "w") as f:
    f.write("".join(lines))
