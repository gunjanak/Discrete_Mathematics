#include <stdio.h>

// Recursive function for linear search
int linearSearchRecursive(int arr[], int size, int target, int index) {
    if (index >= size)
        return -1; // base case: not found

    if (arr[index] == target)
        return index; // base case: found

    return linearSearchRecursive(arr, size, target, index + 1); // recursive step
}

int main() {
    int arr[100], n, target;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = linearSearchRecursive(arr, n, target, 0);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}
