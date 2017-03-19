
# Проверка времени компиляции

Что будет если я удалю все файлы *.gch из текущей директории? Изменится ли время компиляции?

```
$ time make -B
rm -f ./.depend
g++ --std=c++14 -g -pipe  -pg -MM main.cpp digraph.cpp exceptions.cpp semiiso.cpp semilattice.cpp matrix.cpp digraphiso.cpp inv3.cpp > ./.depend;
g++ --std=c++14 -g -pipe  -pg -c main.cpp -o main.o
g++ --std=c++14 -g -pipe  -pg -c digraph.cpp -o digraph.o
g++ --std=c++14 -g -pipe  -pg -c exceptions.cpp -o exceptions.o
g++ --std=c++14 -g -pipe  -pg -c semiiso.cpp -o semiiso.o
g++ --std=c++14 -g -pipe  -pg -c semilattice.cpp -o semilattice.o
g++ --std=c++14 -g -pipe  -pg -c matrix.cpp -o matrix.o
g++ --std=c++14 -g -pipe  -pg -c digraphiso.cpp -o digraphiso.o
g++ --std=c++14 -g -pipe  -pg -c inv3.cpp -o inv3.o
g++ -pipe -pg -o semi main.o digraph.o exceptions.o semiiso.o semilattice.o matrix.o digraphiso.o inv3.o

real	0m21.925s
user	0m20.732s
sys	0m1.668s
```

Компилирую еще раз для фиксации времени компиляции:

```
```