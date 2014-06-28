#include <stdio.h>
#include <stdlib.h>

/* Complexity: O(nlog(n))*/


void quick_sort( int y[], int m) {
    int p, q, r;
    int i, j;
    int t[m];
    int b;

    b = y[m/2];

    for(p = q = r = i = 0; i < m; i++)
        if(y[i] < b)
            y[p++] = y[i];
        else if(y[i] > b)
            t[q++] = y[i];
        else r++;

    if(p > 1) quick_sort(y, p);
    if(q > 1) quick_sort(t, q);

    for(j = 0, i = p; j < r; j++, i++)
        y[i] = b;
    for(j = 0; j < q; j++, i++)
        y[i] = t[j];
}

int main() {
    int i, vec[500];
    int vec_length = sizeof(vec)/sizeof(int);

    for( i = 0; i < 500; i++ ) vec[i] = rand();

    printf("Before: ");

    for(i = 0; i < vec_length; i++)
        printf("%d ", vec[i]);

    printf("\n\nAfter:  ");

    quick_sort(vec, vec_length);

    for(i = 0; i < vec_length; i++)
        printf("%d ", vec[i]);
}
