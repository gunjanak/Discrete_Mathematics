#include <stdio.h>
#include <stdlib.h>

// Function to generate combinations
void combine(char set[], char data[], int start, int end, int index, int r) {
    if (index == r) {
        // Print current combination
        for (int j = 0; j < r; j++) {
            printf("%c ", data[j]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = set[i];
        combine(set, data, i + 1, end, index + 1, r);
    }
}

int main() {
    int n, r;
    printf("Enter the number of elements in the set (n): ");
    scanf("%d", &n);
    printf("Enter the size of each combination (r): ");
    scanf("%d", &r);
    if (r > n || n <= 0 || r <= 0) {
        printf("Invalid input. Ensure that 0 < r <= n.\n");
        return 1;
    }
    char set[n];
    printf("Enter %d characters separated by spaces (e.g., a b c d):\n", n);
    // Read characters with spaces
    for (int i = 0; i < n; i++) {
        scanf(" %c", &set[i]);  // Note the space before %c to skip whitespace
    }
    char data[r];  // Temporary array to hold current combination
    printf("Combinations of %d elements from the given set:\n", r);
    combine(set, data, 0, n - 1, 0, r);
    return 0;
}
