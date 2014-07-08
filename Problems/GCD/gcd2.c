#include<stdio.h>
#include<string.h>

// http://www.spoj.com/problems/GCD2/

char b[252];

int gcd_bin(int u, int v) {
    int t, k;

    u = u < 0 ? -u : u; /* abs(u) */
    v = v < 0 ? -v : v;

    if (u < v) {
        t = u;
        u = v;
        v = t;
    }

    if (v == 0) return u;
    k = 1;

    while (u & 1 == 0 && v & 1 == 0) { /* u, v - even */
        u >>= 1; v >>= 1;
        k <<= 1;
    }

    t = (u & 1) ? -v : u;

    while (t) {
        while (t & 1 == 0) t >>= 1;

        if (t > 0) u = t;
        else v = -t;

        t = u - v;
    }

    return u * k;
}

int main() {
	int t, a, mod, i, l;

    scanf("%d", &t);

	while(t--) {
		mod = 0;
		scanf("%d %d", &a, &b);

		if(!a){
			printf("%s\n",b);
			continue;
		}

		l = strlen(b);

		for(i = 0; i < l; i++)
			mod = (mod*10 + b[i] - '0')%a;

		printf("%d\n", gcd_bin(mod,a));
	}

	return 0;
}
