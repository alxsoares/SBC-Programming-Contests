#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
// http://www.spoj.com/problems/WPC4E/

int* z;

// Function f without dynamic programming
int f(int n) {
    if(n == 0) return 1;
    return f(n/2) + f(n/5) + f(n/7);
}

// Using dynamic programming
int fd(int n) {
    if(n == 0) return 1;
    else if(z[n] == -1)
        z[n] = fd(n/2) + fd(n/5) + fd(n/7);
    return z[n];
}

int main() {
    int t, n, i;
    scanf("%d", &t);

    z = malloc(MAX * sizeof(int));
    for(i = 0; i <= MAX; i++) z[i] = -1;

    while(t--) {
        scanf("%d", &n);
        //printf("%d\n", f(n));
        printf("%d\n", fd(n));
    }

    return 0;
}
