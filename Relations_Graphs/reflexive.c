//Check if a given relation is reflexive
#include <stdio.h>

typedef struct {
    int first;
    int second;
} Pair;

int isReflexive(Pair R[], int n, int set[], int set_size) {
    for (int i = 0; i < set_size; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (R[j].first == set[i] && R[j].second == set[i]) {
                found = 1;
                break;
            }
        }
        if (!found)
            return 0; // Not reflexive
    }
    return 1; // Reflexive
}

int main() {
    // Define relation R = {(1,1), (2,2), (2,3), (3,2), (3,3)}
    Pair R[] = {{1,1}, {2,2}, {2,3}, {3,2}, {3,1}};
    int n = sizeof(R)/sizeof(R[0]);

    // Define set A = {1, 2, 3}
    int set[] = {1, 2, 3};
    int set_size = sizeof(set)/sizeof(set[0]);

    if (isReflexive(R, n, set, set_size))
        printf("The relation is Reflexive.\n");
    else
        printf("The relation is NOT Reflexive.\n");

    return 0;
}
