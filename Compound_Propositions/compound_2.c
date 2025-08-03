#include <stdio.h>

int main() {
    int p, q;
    int not_p,not_q,left,right,not_left;
    int compound;
    printf("p q ¬q p∨¬q p∧q (p∨¬q)->(p∧q) \n");
    printf("------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <=1; q++) {
            not_p = !p;
            not_q = !q;
            left = p||not_q;
            right = p&&q;
            not_left = !left;
            printf("%d %d %d  %d      %d    %d\n",
                       p, q, not_q, left, right,not_left||right );
        }
    }

    return 0;
}
