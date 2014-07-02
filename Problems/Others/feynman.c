#include <stdio.h>

// http://www.spoj.com/problems/SAMER08F/

int main() {
    int n, i;

    scanf("%d", &n);

    while (n > 0) {
        int sum_squares = 0;

        for(i = 1; i <= n; i++)
            sum_squares += i*i;

        printf("%d\n", sum_squares);
        scanf("%d", &n);
    }

    return 0;
}
