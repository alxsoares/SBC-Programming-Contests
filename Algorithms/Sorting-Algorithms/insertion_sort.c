#include <stdio.h>

/* Complexity: O(n^2) in comparsions and swap values.
               O(n) for small dataset.
*/

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int d[], int d_length) {
    int i, j;

    for(i = 1; i < d_length; i++)
        for(j = i; (j > 0) && (d[j] < d[j-1]); j--)
            swap(&d[j], &d[j-1]);
}

int main() {
    int i, d[] = {55, 99, 33, 22, 77, 66, 11, 88, 44};
    int d_length = sizeof(d)/sizeof(int);

    printf("Before: ");

    for(i = 0; i < d_length; i++)
        printf("%d ", d[i]);

    printf("\nAfter:  ");

    insertion_sort(d, d_length);

    for(i = 0; i < d_length; i++)
        printf("%d ", d[i]);

    return 0;
}
