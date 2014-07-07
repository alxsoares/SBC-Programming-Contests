#include <stdio.h>

// http://www.spoj.com/problems/KNAPSACK/

void knapsack(int w[], int p[], int r[], int k, int n) {
    int i, j;

    for(i = 0; i < n; i++)
        for(j = k - w[i]; j >= 0; j--)
            if(r[j+w[i]] <= r[j] + p[i])
                r[j+w[i]] = r[j] + p[i];
}

int main() {
    int s, n, i, j;
    int r[2001], weights[2001], values[2001];

    scanf("%d %d", &s, &n);

    for(i = 0; i <= s; i++) r[i] = 0;
    for(i = 0; i < n; i++) scanf("%d %d", &weights[i], &values[i]);

    knapsack(weights, values, r, s, n);

    for(i = j = 0; i <= s; i++)
        if(r[i] > r[j]) j = i;

    printf("%d\n", r[j]);

    return 0;
}
