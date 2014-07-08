#include <stdio.h>

int main() {
    unsigned long long n, t, i, sum;

    scanf("%llu", &t);

    while(t--) {
        scanf("%llu", &n);
        sum = 0;
        for(i = 3; i < n; i += 3) sum += i;
        for(i = 5; i < n; i += 5) if(i %3 != 0) sum += i;
        printf("%llu\n", sum);
    }

    return 0;
}
