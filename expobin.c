#include <stdio.h>

long long potenciacionbinaria(long long M, long long e, long long n) {
    if (n == 1) return 0;
    int k = 0;
    long long temp = e;
    while (temp > 0) { temp >>= 1; k++; }
    long long C = M % n;
    for (int i = k - 2; i >= 0; i--) {
        C = (C * C) % n;
        if ((e >> i) & 1) C = (C * M) % n;
    }
    return C;
}

int main() {
    long long base, exponente, modulo;
    // Leemos los tres valores de golpe (como los envía el bot)
    if (scanf("%lld %lld %lld", &base, &exponente, &modulo) == 3) {
        long long resultado = potenciacionbinaria(base, exponente, modulo);
        // Imprimimos SOLO el número resultante
        printf("%lld\n", resultado);
    }
    return 0;
}
