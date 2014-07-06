#include <stdio.h>
typedef long long LL;

// http://www.spoj.com/problems/UJ/

LL karatsuba(LL x, LL y, LL n) {
    LL x0, x1, y0, y1, z0, z1, z2;
    x1 = x >> 16; y1 = y >> 16;x0 = x & 0xFFFF;y0 = y & 0xFFFF;z2 = x1 * y1;z0 = x0 * y0;z1 = ( x0 + x1 ) * ( y0 + y1 ) - z0 - z2;
    return ( z2 << 32 ) + ( z1 << 16 ) + z0;
}

int main() {
    int n, d, i;

    scanf("%d %d", &n, &d);

    while(n > 0 & d > 0) {
        // answer = n^d
        LL ways = 0;

        for(i = 0; i < d-1; i++) {
            if(ways == 0) ways = karatsuba(n, n, 1);
            else ways = karatsuba(ways, n, 1);
        }

        printf("%lld\n", ways);
        scanf("%d %d", &n, &d);
    }

    return 0;
}
