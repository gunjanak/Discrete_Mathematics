#include <stdio.h>

int main() {
    int p, q, r,not_r,left,right,final;
    printf("p q r ¬r p->¬r q->¬r (p->¬r)∨(q->¬r)   \n");
    printf("------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <=1; q++) {
            for (r=0;r<=1;r++){
                left = !p || !r;
                right = !q || !r;
                final = left || right;
                printf("%d %d %d  %d    %d    %d    %d\n",
                       p, q, r,!r, left, right,left||right );

            }
           
        }
    }

    return 0;
}
