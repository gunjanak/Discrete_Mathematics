//check if a given relation is symmetric
#include <stdio.h>

typedef struct {
    int first;
    int second;
} Pair;

int isSymmetric(Pair R[], int n) {
    for (int i = 0; i < n; i++) {
        int a = R[i].first;
        int b = R[i].second;
        int found = 0;

        // Look for (b, a) in R
        for (int j = 0; j < n; j++) {
            if (R[j].first == b && R[j].second == a) {
                found = 1;
                break;
            }
        }

        if (!found)
            return 0; // Not symmetric
    }
    return 1; // Symmetric
}

int main() {
    // Define relation R = {(1,1), (2,2), (2,3), (3,2), (3,3)}
    Pair R[] = {{1,1}, {2,2}, {2,3}, {3,1}, {3,3}};
    int n = sizeof(R)/sizeof(R[0]);

    if (isSymmetric(R, n))
        printf("The relation is Symmetric.\n");
    else
        printf("The relation is NOT Symmetric.\n");

    return 0;
}
