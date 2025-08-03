//program to generate permutations
#include <stdio.h>

// Swap function
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations
void permute(char set[], int l, int n, int r, char data[], int used[]) {
    if (l == r) {
        // Print one permutation
        for (int i = 0; i < r; i++) {
            printf("%c ", data[i]);
        }
        printf("\n");
        return;
    }
   for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            data[l] = set[i];
            permute(set, l + 1, n, r, data, used);
            used[i] = 0; // backtrack
        }
    }
}

int main() {
    int n, r;
    printf("Enter the number of elements in the set (n): ");
    scanf("%d", &n);
    printf("Enter the size of each permutation (r): ");
    scanf("%d", &r);
    if (r > n || n <= 0 || r <= 0) {
        printf("Invalid input. Ensure that 0 < r <= n.\n");
        return 1;
    }
    char set[n];
    printf("Enter %d characters separated by spaces (e.g., a b c d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &set[i]);
    }
    char data[r];     // Stores current permutation
    int used[n];      // Tracks used elements
    for (int i = 0; i < n; i++) used[i] = 0;

    printf("Permutations of %d elements from the given set:\n", r);
    permute(set, 0, n, r, data, used);

    return 0;
}
