#include<stdio.h>

#define NPRI 31622
#define NMAX 1000
#define PMAX 3401

char f[NPRI];
int  p[PMAX]= { 2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,
 43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,
103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
173, 179};

int fa[10], pa[10], nf;

void sieve() {
    int i, j, k;

    for(i = 0; i < 41; i++)
        for(k = p[i], j = k * k; j < NPRI; j += k) f[j] = 1;
        for(j = 181; j < NPRI; j += 2) if( f[j] == 0) p[i++] = j;
}

void fatora(int x) {
    int i;

    for(i = 0; i < 10; i++) pa[i] = fa[i] = 1;

    for(nf = i = 0; (x > 1) && (i < PMAX);)
        if((x % p[i]) == 0) {
            if(fa[nf] == p[i]) pa[nf]++;
            else fa[++nf] = p[i];
            x /= p[i];
        } else i++;

    if(x > 1) fa[0] = x;
}

int main() {
    int n, i;

    sieve();

    scanf("%d", &n);
    fatora(n);

    for(i = 0; i <= nf; i++) printf("%d^%d . ", fa[i], pa[i]);
    printf("\n");

    return 0;
}
