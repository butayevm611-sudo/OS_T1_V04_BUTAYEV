# OS_T1_V04_BUTAYEV

Operatsion tizimlar, 1-topshiriq, 4-variant: C asoslari, kompilyatsiya va pointerlar.

## Fayllar
- `hello.c`, `hello.i`, `hello.s`, `hello.o`, `hello` - A qism (kompilyatsiya 4 bosqichi)
- `main.c` - B qism: 1-masala (Fibonachchi, iterativ va rekursiv), 2-masala (`keyingi` funksiyasi, pointerlar)

## A qism
```bash
gcc -E hello.c -o hello.i
gcc -S hello.i -o hello.s
gcc -c hello.s -o hello.o
gcc hello.o -o hello
./hello
```

## B qism
```bash
gcc -Wall -Wextra -o main main.c
./main
```
Menyu: `1` - Fibonachchi (iterativ va rekursiv, N = 0..92), `2` - dastlabki N had `keyingi()` bilan.
