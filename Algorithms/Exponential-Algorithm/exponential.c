#include <stdio.h>

/*
    For a^n, if n has "k" bits, we'll have 2*(k-1) multiplications.
    Complexity: O(log(n)).
*/

int main() {
    int a, b, i, j, r;

    printf("Enter the value of a and b (a^b): ");
    scanf("%d %d", &a, &b);
    i = b;
    j = a;
    r = 1;

    while(i > 0) {
        /* If the least significant bit (LSB) of "i" is 1,
           we'll multiply by a^n. */
        if((i & 1) == 1)
            r = r * j;
        j = j * j;

        /* Moving the bits of "i" to the right.*/
        i = i >> 1;
    }

    printf("%d ^ %d = %d.\n", a, b, r);

    return 0;
}
