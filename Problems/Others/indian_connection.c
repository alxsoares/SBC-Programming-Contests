#include <stdio.h>

/*
    http://www.spoj.com/problems/DCEPC504/

    n = 1 represents the 1st generation, whose child will always be male.
    n = 2 represent the 2nd generation, whose child is female.
    n = 1 and n = 2 are known, because we already have these two situations.

    If we have more than 2 generations, we will use the Thue-Morse Series. For example:

    We start with 0.
    The bitwise negation of 0 is 1.
    Combining these, the first 2 elements are 01.
    The bitwise negation of 01 is 10.
    Combining these, the first 4 elements are 0110.
    The bitwise negation of 0110 is 1001.
    Combining these, the first 8 elements are 01101001.
    And so on.

    T0 = 0.
    T1 = 01.
    T2 = 0110.
    T3 = 01101001.
    T4 = 0110100110010110.
    T5 = 01101001100101101001011001101001.

    And so on. For T0, T1 and T2 we already have who will be the child.

*/

int main() {
    freopen("indian_connection.txt", "r", stdin);

    int t, count_bits;
    long long int k, n;

    scanf("%d",&t);

    while(t--) {
        count_bits = 0;
        scanf("%lld %lld", &k, &n);

        if(n == 1) printf("Male\n");
        else if(n == 2) printf("Female\n");
        else {
            while(--n > 1) {
                if(n % 2 != 0) count_bits++;
                n = n/2;
            }

            if(count_bits % 2 == 0) printf("Female\n");
            else printf("Male\n");
        }

        printf("\n");
    }

    return 0;
}
