#include <stdio.h>
#include <math.h>
#define LIMIT 10000

// Sieve of Eratosthenes
// Complexity: O(n log log n)

int p[LIMIT], primo[LIMIT];
void sieve() {
    long long i, n, k, j = sqrt(LIMIT);

    for(i = 2; i <= LIMIT; i++) p[i] = 1;

    for(n = 0, i = 2; i <= j; i++) {
        if(p[i] == 1) {
            for( k = i * i; k <= LIMIT; k = k + i) p[k] = 0;
            primo[n++] = i;
        }
    }
}

int is_prime(n) {
    long long i, j = sqrt(n);
    for(i = 0; primo[i] <= j; i++)
        if(primo[i] != 0 && n % primo[i] == 0 ) return 0;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    sieve();

    if(is_prime(n) == 1) printf("Is prime!");
    else printf("Not prime.");

    return 0;
}
