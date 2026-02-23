#include <stdio.h>

int main() {
    int n, i, j, sum = 0;
    
    printf("Enter size of square matrix: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Calculate primary diagonal sum
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    
    printf("Sum of primary diagonal = %d", sum);
    
    return 0;
}