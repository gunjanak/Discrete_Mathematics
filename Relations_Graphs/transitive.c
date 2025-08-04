//Check if a relation is transitive
#include <stdio.h>

typedef struct {
    int first;
    int second;
} Pair;

int pairExists(Pair R[], int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        if (R[i].first == a && R[i].second == b)
            return 1;
    }
    return 0;
}

int isTransitive(Pair R[], int n) {
    for (int i = 0; i < n; i++) {
        int a = R[i].first;
        int b = R[i].second;
        for (int j = 0; j < n; j++) {
            if (R[j].first == b) {
                int c = R[j].second;
                if (!pairExists(R, n, a, c))
                    return 0; // Not transitive
            }
        }
    }
    return 1; // Transitive
}

int main() {
    // Define relation R = {(1,1), (2,2), (2,3), (3,2), (3,3)}
    Pair R[] = {{1,1}, {2,3}, {3,2}, {3,3}};
    int n = sizeof(R)/sizeof(R[0]);

    if (isTransitive(R, n))
        printf("The relation is Transitive.\n");
    else
        printf("The relation is NOT Transitive.\n");

    return 0;
}
