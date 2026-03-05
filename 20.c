#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void closestToZero(int arr[], int n)
{
    int l = 0;
    int r = n - 1;

    int min_sum = arr[l] + arr[r];
    int min_l = l;
    int min_r = r;

    // sort array
    qsort(arr, n, sizeof(int), compare);

    while (l < r)
    {
        int sum = arr[l] + arr[r];

        if (abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }

        if (sum < 0)
            l++;
        else
            r--;
    }

    printf("Two elements whose sum is closest to zero are: %d and %d\n",
           arr[min_l], arr[min_r]);
}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    closestToZero(arr, n);

    return 0;
}