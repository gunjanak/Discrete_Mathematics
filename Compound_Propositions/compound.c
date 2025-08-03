#include <stdio.h>

int main() {
    int p, q, r;
    printf("p q r ¬q p∧¬q p∧¬q∨r ¬p ¬p∨r →\n");
    printf("------------------------------\n");

    for (p = 1; p >= 0; p--) {
        for (q = 1; q >= 0; q--) {
            for (r = 1; r >= 0; r--) {
                int not_q = !q;
                int not_p = !p;
                int left = (p && not_q) || r;
                int right = not_p || r;
                int implies = (!left) || right;

                printf("%d %d %d  %d    %d      %d       %d    %d     %d\n",
                       p, q, r, not_q, p && not_q, left, not_p, right, implies);
            }
        }
    }

    return 0;
}
