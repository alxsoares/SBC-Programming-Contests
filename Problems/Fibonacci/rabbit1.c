#include <stdio.h>

typedef long long LL;

void power(LL F[2][2], int n) {
    if(n == 0 || n == 1) return;
    LL M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0) multiply(F, M);
}

void multiply(LL F[2][2], LL M[2][2]) {
    LL x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    LL y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    LL z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    LL w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

LL fib(n) {
    if (n == 0) return 0;

    LL F[2][2] = {{1,1},{1,0}};
    power(F, n-1);

    return F[0][0];
}

int exp(int a, int b) {
    int i = b, j = a, r = 1;

    while(i > 0) {
        if((i & 1) == 1) r = r * j;
        j = j * j;
        i = i >> 1;
    }

    return r;
}

int main() {
    int c, n, m;

    scanf("%d", &c);

    while(c--) {
        scanf("%d %d", &n, &m);
        printf("%d", fib(n+1) % (2*m));
    }

    return 0;
}
