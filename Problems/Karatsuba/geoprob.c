#include <stdio.h>

typedef long long LL;

// http://www.spoj.com/problems/GEOPROB/

LL karatsuba(LL x, LL y, LL n) {
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
    int t;
    LL a, b, c, d;

    scanf("%d", &t);

    while(t--) {
        // a = c*2 - b - d
        scanf("%lld %lld %lld", &b, &c, &d);

        if(b > c) a = 0;
        else if(d > c) a = 0;
        else a = karatsuba(c, 2, 1) - b - d;
        printf("%lld\n", a);
    }

    return 0;
}
