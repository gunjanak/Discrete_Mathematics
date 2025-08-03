#include <stdio.h>

int main() {
    int p, q,biconditional;

    printf("p q p<->q  \n");
    printf("------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <=1; q++) {

            biconditional = (p==q);
            printf("%d %d   %d \n", p, q,biconditional);
        }
    }

    return 0;
}
