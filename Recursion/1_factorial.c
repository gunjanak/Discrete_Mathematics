#include <stdio.h>

// Recursive function to compute factorial
unsigned long long factorial(unsigned int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    unsigned int n;
    printf("Enter a nonnegative integer: ");
    scanf("%u", &n);

    printf("Factorial of %u is %llu\n", n, factorial(n));
    return 0;
}
