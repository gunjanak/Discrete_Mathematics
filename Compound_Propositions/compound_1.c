#include <stdio.h>

int main() {
    int p, q;
    int not_p,not_q;
    

    printf("p q ¬p ¬q p∧q p∨q p->q\n");
    printf("------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <=1; q++) {
            not_p = !p;
            not_q = !q;

            printf("%d %d %d  %d  %d    %d    %d\n",
                       p, q, not_p, not_q, p&&q, p||q, not_p||q);
        }
    }

    return 0;
}
