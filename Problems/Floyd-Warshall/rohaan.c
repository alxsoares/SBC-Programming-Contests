#include <stdio.h>
#define MAXN 51

// http://www.spoj.com/problems/ROHAAN/

int main() {
    /* Quantidade de distâncias, de ordem 51 x 51.*/
    int d[MAXN][MAXN];
    int T, r, n, i, j, k, x = 0;
    short c = 1;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);

        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                scanf("%d", &d[i][j]);

        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for(j = 1; j <= n; j++) {
                    x = d[i][k] + d[k][j];

                    if(d[i][j] > x)
                        d[i][j] = x;
                }


        scanf("%d", &r);

        for(i = 0; i < r; i++) {
            scanf("%d %d", &j, &k);
            x += d[j][k];
        }

        printf("Case #%d: %d\n", c++, x);
    }

    return 0;
}

