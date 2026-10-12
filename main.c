#include <stdio.h>
#include <time.h>

long long fib_iter(int n) {
    if (n == 0) return 0;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long t = a + b;
        a = b;
        b = t;
    }
    return b;
}

long long fib_rec(int n) {
    if (n < 2) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}
/* Juftlikni o'z joyida yangilaydi: (a, b) -> (b, a + b) */
void keyingi(long long *a, long long *b) {
    long long t = *a + *b;
    *a = *b;
    *b = t;
}

void masala2(void) {
    int n;
    long long a = 0, b = 1;

    printf("Nechta had chiqarilsin (1..92): ");
    if (scanf("%d", &n) != 1) {
        printf("Xato: son kiriting!\n");
        return;
    }
    if (n < 1 || n > 92) {
        printf("Xato: N 1 dan 92 gacha bo'lishi kerak.\n");
        return;
    }

    printf("a o'zgaruvchisi manzili: %p\n", (void *)&a);
    printf("b o'zgaruvchisi manzili: %p\n", (void *)&b);

    for (int i = 0; i < n; i++) {
        printf("F(%d) = %lld\n", i, a);
        if (i < n - 1) keyingi(&a, &b);
    }
}

void masala1(void) {
    int n;

    printf("N ni kiriting (0..92): ");
    if (scanf("%d", &n) != 1) {
        printf("Xato: son kiriting!\n");
        return;
    }
    if (n < 0 || n > 92) {
        printf("Xato: N 0 dan 92 gacha bo'lishi kerak.\n");
        return;
    }

    clock_t t1 = clock();
    long long r1 = fib_iter(n);
    clock_t t2 = clock();
    printf("Iterativ: F(%d) = %lld, vaqt = %.6f s\n",
           n, r1, (double)(t2 - t1) / CLOCKS_PER_SEC);

    if (n > 45) {
        printf("Rekursiv: N > 45 uchun juda sekin, o'tkazib yuborildi.\n");
        return;
    }

    t1 = clock();
    long long r2 = fib_rec(n);
    t2 = clock();
    printf("Rekursiv: F(%d) = %lld, vaqt = %.6f s\n",
           n, r2, (double)(t2 - t1) / CLOCKS_PER_SEC);
}

int main(void) {
    int tanlov;

    printf("1 - Fibonachchi (iterativ va rekursiv)\n");
    printf("2 - Fibonachchi pointerlar bilan (keyingi)\n");
    printf("Tanlang: ");
    if (scanf("%d", &tanlov) != 1) {
        printf("Xato: son kiriting!\n");
        return 1;
    }

    if (tanlov == 1) masala1();
    else if (tanlov == 2) masala2();
    else printf("Xato: tanlov 1 yoki 2 bo'lishi kerak.\n");

    return 0;
}
