//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

//Input:
//- First line: integer n (array size)
//- Second line: n space-separated integers
//- Third line: integer k (key to search)

#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    // Input array size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }

    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
