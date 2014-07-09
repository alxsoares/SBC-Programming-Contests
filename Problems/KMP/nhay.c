#include <stdio.h>
#define NMAX 1000001
#define MMAX 1000001

//http://www.spoj.com/problems/NHAY/

char W[MMAX], S[NMAX], T[MMAX];
int m = 0;

void kmp_search(char W[], char S[]) {
    int i = 0;

    while((S[m+i] != 0) && (W[i] != 0 ))
        if(S[m+i] == W[i]) i++;
        else {
            m += i - T[i];
            if(i > 0) i = T[i];
        }

    if(W[i] == 0) {
        printf("%d\n", m);
        m++;

        kmp_search(W, S);
    }
}

void kmp_table(char W[]) {
    int i = 2;
    int j = 0;

    T[0] = -1;
    T[1] =  0;

    while(W[i] != 0)
        if(W[i-1] == W[j])
            T[i++] = ++j;
        else
            if(j > 0) j = T[j];
        else
            T[i++] = j = 0;

    return;
}

int main() {
    int n;

    while(scanf("%d\n", &n) != EOF) {
        m = 0;

        gets(W);
        kmp_table(W);

        gets(S);
        kmp_search(W, S);

        printf("\n");
    }

    return 0;
}
