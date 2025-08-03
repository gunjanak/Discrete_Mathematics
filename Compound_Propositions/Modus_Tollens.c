#include <stdio.h>

int main() {
    int p, q;
    printf("p q  p→q  ¬q  ¬p  (p→q ∧ ¬q) ⇒ ¬p\n");
    printf("-------------------------------\n");

    for (p = 1; p >= 0; p--) {
        for (q = 1; q >= 0; q--) {
            int implication = (!p) || q;     // p → q
            int not_q = !q;                  // ¬q
            int not_p = !p;                  // ¬p
            int premises = implication && not_q;  // p → q ∧ ¬q
            int conclusion_valid = (!premises) || not_p; // (premises) → (¬p)

            printf("%d %d   %d    %d   %d       %d\n",
                   p, q, implication, not_q, not_p, conclusion_valid);
        }
    }

    return 0;
}
