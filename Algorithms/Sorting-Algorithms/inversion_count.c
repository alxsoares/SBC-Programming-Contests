#include <stdio.h>
#include <stdlib.h>

int merge_sort(int x[], int start, int end) {
    int middle;

    if(start >= end) return 0;
    middle = (start + end) / 2;

    return merge_sort(x, start, middle) + merge_sort(x, middle+1, end)
    + interpolate(x, start, middle, end);
}

int interpolate(int x[], int start, int middle, int end) {
    int i, j, k;
    int c, b[end+1];

    for(i = start; i <= middle; i++) b[i] = x[i];
    for(j = end; i <= end; i++, j--) b[i] = x[j];

    for(c = 0, j = end, i = k = start; k <= end; k++)
        if(b[i] <= b[j]) x[k] = b[i++];
        else {
          x[k] = b[j--];
          c = c + (middle - i + 1);
        }

    return c;
}

int main() {
    int i, j;
    int x[500];

    for(i = 0; i < 100; i++) x[i] = rand();

    printf("Before:\n");
    for(i = 0; i < 100; i++) printf("%6d ", x[i]);

    j = merge_sort(x, 0, 99);

    printf("\n\nAfter:\n");
    for(i = 0; i < 100; i++) printf("%6d ", x[i]);

    printf("\n\nQuantity of inversions: %d\n", j);
    return 0;
}
