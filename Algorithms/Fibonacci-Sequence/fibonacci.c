#include <stdio.h>

typedef long long LL;

void power(LL F[2][2], int n) {
    if(n == 0 || n == 1) return;
    LL M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0) multiply(F, M);
}

/* multiply = identity matrix */
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

// fib2 complexity: O(log(n))
LL fib2(n) {
    if (n == 0) return 0;

    LL F[2][2] = {{1,1},{1,0}};
    power(F, n-1);

    return F[0][0];
}

// fib1 complexity: O(n)
LL fib1(n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fib1(n - 1) + fib1(n - 2);
}

int main() {
    int n;

    printf("Entre com n: ");
    scanf("%d", &n);
    printf("%lld\n", fib2(n));

    return 0;
}
