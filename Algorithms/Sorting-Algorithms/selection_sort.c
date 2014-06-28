#include <stdio.h>

/* Complexity: O(n^2) for comparison and O(n) in swap values for worst cases.*/

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int d[], int d_length) {
    int i, j, p;

    for(i = 0; i < d_length-1; i++) {
        p = i;

        for(j = i+1; j < d_length; j++)
            if(d[j] < d[p]) p = j;

        swap(&d[i], &d[p]);
    }
}

int main() {
    int i, d[] = {55, 99, 33, 22, 77, 66, 11, 88, 44};
    int d_length = sizeof(d)/sizeof(int);

    printf("Before: ");

    for(i = 0; i < d_length; i++)
        printf("%d ", d[i]);

    printf("\nAfter:  ");

    selection_sort(d, d_length);

    for(i = 0; i < d_length; i++)
        printf("%d ", d[i]);
}
