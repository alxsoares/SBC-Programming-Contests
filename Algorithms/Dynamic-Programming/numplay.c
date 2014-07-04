#include <stdio.h>
#define MAX 100000

// http://www.spoj.com/problems/NUMPLAY/

typedef long long LL;
LL f1(int);
LL f3(int);
LL f5(int);
LL f7(int);

int z1[MAX], z3[MAX], z5[MAX], z7[MAX];

int main() {
/*
    Without dynamic programming
    int t, n;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", f1(n) + f3(n) + f5(n) + f7(n));
    }
*/
    int t, i, n;

    for(i = 0; i <= MAX; i++)
        z1[i] = z3[i] = z5[i] = z7[i] = -1;

    scanf("%d", &t);

    while(t--) {
        scanf("%ld", &n);
        printf("%lld\n", f1(n) + f3(n) + f5(n) + f7(n));
    }

    return 0;

}


LL f1(int n) {
    if(z1[n] = -1)
        if(n == 1) z1[n] = 1;
        else z1[n] = f3(n - 1);

    return z1[n];
}

LL f3(int n) {
    if(z3[n] = -1)
        if(n == 1) z3[n] = 1;
        else z3[n] = f1(n-1) + f5(n-1);

    return z3[n];
}

LL f5(int n) {
    if(z5[n] = -1)
        if(n == 1) z5[n] = 1;
        else z5[n] = f7(n-1);

    return z5[n];
}

LL f7(int n) {
    if(z7[n] == -1)
        if(n == 1) z7[n] = 1;
        else z7[n] = f5(n-1) + f3(n-1);

    return z7[n];
}

/*
LL f1(int n) {
    LL r;

    if(n == 1) r = 1;
    else r = f3(n - 1);

    return r;
}


LL f3(int n) {
    LL r;

    if(n == 1) r = 1;
    else r = f1(n - 1) + f5(n - 1);

    return r;
}

LL f5(int n) {
    LL r;

    if(n == 1) r = 1;
    else r = f7(n - 1);

    return r;
}

LL f7(int n) {
    LL r;

    if(n == 1) r = 1;
    else r = f5(n - 1) + f3(n - 1);

    return r;
}
*/
