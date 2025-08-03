#include <stdio.h>
// Recursive function to compute a^n
double power(double a, unsigned int n) {
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}
int main() {
    double a;
    unsigned int n;
    printf("Enter the base (a): ");
    scanf("%lf", &a);
    printf("Enter the exponent (nonnegative integer n): ");
    scanf("%u", &n);
    printf("%.2lf raised to the power %u is %.2lf\n", a, n, power(a, n));
    return 0;
}
