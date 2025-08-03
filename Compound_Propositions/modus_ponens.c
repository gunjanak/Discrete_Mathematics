#include <stdio.h>

int main() {
    int p, q;
    printf("p q  p→q    (p ∧ p→q) ⇒ q\n");
    printf("-------------------------------\n");

    for (p = 1; p >= 0; p--) {
        for (q = 1; q >= 0; q--) {
            int implication = (!p) || q;     // p → q
            int premises = p && implication;  // p ∧ (p → q) 
            int conclusion_valid = (!premises) || q; // (premises) → (q)

            printf("%d %d      %d       %d\n",
                   p, q, implication, conclusion_valid);
        }
    }

    return 0;
}
