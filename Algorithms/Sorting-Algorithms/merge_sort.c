#include <stdio.h>
#include <stdlib.h>

void merge_sort(int x[], int start, int end) {
    int middle;

    if(start >= end) return 0;
    middle = (start + end) / 2;

    merge_sort(x, start, middle);
    merge_sort(x, middle+1, end);
    interpolate(x, start, middle, end);
}

void interpolate(int x[], int start, int middle, int end) {
    int i, j, k;
    int b[end+1];

    for(i = start; i <= middle; i++) b[i] = x[i];
    for(j = end; i <= end; i++, j--) b[i] = x[j];

    for(j = end, i = k = start; k <= end; k++)
        if(b[i] <= b[j]) x[k] = b[i++];
        else x[k] = b[j--];
}

int main() {
    int i;
    int x[500];

    for(i = 0; i < 100; i++) x[i] = rand();

    printf("Before:\n");
    for(i = 0; i < 100; i++) printf("%6d ", x[i]);

    merge_sort(x, 0, 99);

    printf("\n\nAfter:\n");
    for(i = 0; i < 100; i++) printf("%6d ", x[i]);

    return 0;
}
