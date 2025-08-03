#include <stdio.h>
// Recursive function to compute (b^n) % m
unsigned long long mpower(unsigned long long b, unsigned int n, unsigned int m) {
    if (n == 0)
        return 1;
    unsigned long long half = mpower(b, n / 2, m);
    unsigned long long result = (half * half) % m;
    if (n % 2 == 0)
        return result;
    else
        return (result * (b % m)) % m;
}
int main() {
    unsigned long long b;
    unsigned int n, m;
    printf("Enter base b (>0): ");
    scanf("%llu", &b);
    printf("Enter exponent n (>=0): ");
    scanf("%u", &n);
    printf("Enter modulus m (>=2): ");
    scanf("%u", &m);
    if (b == 0 || m < 2) {
        printf("Invalid input. Ensure b > 0 and m >= 2.\n");
        return 1;
    }
    unsigned long long result = mpower(b, n, m);
    printf("Result: (%llu^%u) mod %u = %llu\n", b, n, m, result);

    return 0;
}
