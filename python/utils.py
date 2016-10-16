import re

def read(fn, lines=False):
  with open(fn, "r", encoding="utf8") as f:
    if lines:
      return f.readlines()
    return f.read()

def write(fn, s):
  with open(fn, "w", encoding="utf8") as f:
    f.write(s)

def itemize(fn):
  s = read(fn, lines=True)
  res = ''
  q = 0
  for line in s:
    if re.match(r"\\begin\{itemize\}", line):
      q = 1
      res += line
      continue
    elif re.match(r"\\end\{itemize\}", line):
      q = 0
      res += line
      continue
    if q > 0:
      res += '\item ' + line
    else:
      res += line
  write(fn, res)


def remove_all__displaystyle_s(fn):
  s = read(fn)

  res = ''
  resi = 0

  iter = re.finditer(r"\{\\displaystyle", s)

  for m in iter:
    sp = m.span()
    res += s[resi:sp[0]]
    i = sp[1]
    o = 0
    while True:
      if s[i] == '{':
        o += 1
      elif s[i] == '}':
        if o == 0:
          i += 1
          break
        else:
          o -= 1
      i += 1
    resi = i

  res += s[resi:]
  write(fn, res)
