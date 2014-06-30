#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// http://br.spoj.com/problems/BALE11/

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
    int n, i;
    int dancarinas[MAX];

    //freopen("bale.txt", "r", stdin);
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &dancarinas[i]);

    printf("%d", merge_sort(dancarinas, 0, n-1));
    return 0;
}
