#include<stdio.h>
#define NMAX 51

int d[NMAX][NMAX];

int main() {
  int t, x, c = 1;
  short n, r, i, j, k;

  for(scanf("%d", &t); t > 0; t--) {
    scanf("%hd", &n);

    for(i = 1; i <= n; i++ )
    for(j = 1; j <= n; j++ ) scanf("%d", &d[i][j]);

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) {
              x = d[i][k] + d[k][j];
              if( d[i][j] > x ) d[i][j] = x;
            }

    scanf("%hd", &r);

    for(i = x = 0; i < r; i++) {
       scanf("%hd %hd", &j, &k);
       x += d[j][k];
    }

    printf( "Case #%d: %d\n", c++, x );
  }

  return 0;
}
