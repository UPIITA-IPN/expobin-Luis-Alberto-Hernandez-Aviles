#include <stdio.h>

// Función potenciacion binaria
long long potenciacionbinaria(long long M, long long e, long long n) {
    if (n == 1) return 0; // Cualquier número mod 1 es 0

    // 1. Hallar el bit más significativo (k-1)
    int k = 0;
    long long temp = e;
    while (temp > 0) {
        temp >>= 1;
        k++;
    }
    // 2. Inicialización: If c_{k-1} = 1 Then C = M else C = 1
    // (Como el exponente > 0, el bit c_{k-1} siempre será 1)
    long long C = M % n;

    // 3. Ciclo principal: For i = k-2 down to 0
    for (int i = k - 2; i >= 0; i--) {
        //a)PASO1 C = C^2 mod n
        C = (C * C) % n;

        //b)PASO2 If c_i == 1 Then C = C * M mod n
        if ((e >> i) & 1) {
            C = (C * M) % n;
        }
    }
    return C;
}

int main() {
    long long base, exponente, modulo;

    printf("Calculadora de Exponenciacion Binaria - Practica 2\n\n");
    printf("Introduce el valor de la base (M): ");
    scanf("%lld", &base);
    printf("Introduce el valor del exponente (e): ");
    scanf("%lld", &exponente);
    printf("Introduce el valor del modulo (n): ");
    scanf("%lld", &modulo);

    long long resultado = potenciacionbinaria(base, exponente, modulo);

    printf("\nResultado de la exponenciacion binaria es: %lld^%lld mod %lld = %lld\n", base, exponente, modulo, resultado);

    return 0;
}
