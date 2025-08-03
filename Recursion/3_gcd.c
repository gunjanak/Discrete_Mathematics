#include <stdio.h>
// Recursive function to compute GCD using Euclid's algorithm
unsigned int gcd(unsigned int a, unsigned int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    unsigned int a, b;
    printf("Enter two nonnegative integers: ");
    scanf("%u %u", &a, &b);
    printf("GCD of %u and %u is %u\n", a, b, gcd(a, b));
    return 0;
}
