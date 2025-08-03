#include <stdio.h>

// Function to compute (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

// Fermat primality test for a given p
int is_probably_prime(int p) {
    int test_bases[] = {2, 3, 5, 7}; // You can add more bases for higher confidence
    int num_tests = sizeof(test_bases) / sizeof(test_bases[0]);

    if (p <= 1) return 0;
    if (p == 2) return 1;

    for (int i = 0; i < num_tests; i++) {
        int a = test_bases[i];
        if (a >= p)
            continue;
        if (mod_pow(a, p - 1, p) != 1)
            return 0; // definitely not prime
    }

    return 1; // probably prime
}

int main() {
    int p;
    printf("Enter a number p: ");
    scanf("%d", &p);

    if (is_probably_prime(p))
        printf("%d is probably prime (based on Fermat's Little Theorem).\n", p);
    else
        printf("%d is composite (fails Fermat's test).\n", p);

    return 0;
}
