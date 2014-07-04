#include <stdio.h>

// http://www.spoj.com/problems/WACHOVIA/

void knapsack(int w[], int p[], int r[], int k, int n) {
    int i, j;

    for(i = 0; i < n; i++)
        for(j = k - w[i]; j >= 0; j--)
            if(r[j+w[i]] <= r[j] + p[i])
                r[j+w[i]] = r[j] + p[i];
}

int main() {
    /*
        k = max weight
        n = amount of bags
        r[1001] (8 ≤K ≤1000)
    */

    //freopen("warchovia.txt", "r", stdin);
    int t, i, j, k, n;
    int r[1001], weights[50], values[50];
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &k, &n);

        for(i = 0; i <= k; i++) r[i] = 0;
        for(i = 0; i < n; i++) scanf("%d %d", &weights[i], &values[i]);

        knapsack(weights, values, r, k, n);

        for(i = j = 0; i <= k ; i++)
            if(r[i] > r[j]) j = i;

        printf("Hey stupid robber, you can get %d.\n", r[j]);
    }

    return 0;
}
