#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// http://www.spoj.com/problems/MERGSORT/

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
    int i, n, values[MAX];

    //freopen("mergesort.txt", "r", stdin);

    while(scanf("%d", &values[n]) != EOF) n++;
    merge_sort(values, 0, n-1);

    for(i = 0; i < n; i++) printf("%d ", values[i]);

    return 0;
}
