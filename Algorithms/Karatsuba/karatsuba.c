#include <stdio.h>

typedef long long LL;

LL karatsuba(x, y, n) {
    if(n == 1) return x * y;

    LL m, i, k = n / 2;
    LL x0, x1, y0, y1;
    LL z0, z1, z2;

    for(m = i = 0; i < k; i++) m = (m << 1) + 1;

    x0 = x & m; x1 = x >> k;
    y0 = y & m; y1 = y >> k;

    z0 = karatsuba(x0, y0, k);
    z2 = karatsuba(x1, y1, k);
    z1 = karatsuba(x0 + x1, y0 + y1, k) - z0 - z2;

    return (z2 << n) + (z1 << k) + z0;
}

int main() {
    printf("%lld\n", karatsuba(1234, 5678, 1));

    return 0;
}
