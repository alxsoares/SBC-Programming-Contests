#include <stdio.h>

typedef long long LL;

LL karatsuba(LL x, LL y, LL n) {
    LL x0, x1, y0, y1, z0, z1, z2;

    x1 = x >> 16;
    y1 = y >> 16;
    x0 = x & 0xFFFF;
    y0 = y & 0xFFFF;

    z2 = x1 * y1;
    z0 = x0 * y0;
    z1 = ( x0 + x1 ) * ( y0 + y1 ) - z0 - z2;

    return ( z2 << 32 ) + ( z1 << 16 ) + z0;
}

int main() {
    int i;
    LL x = 0;

    printf("%lld\n", karatsuba(1234, 5678, 1));
    return 0;
}
