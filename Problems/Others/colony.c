#include <stdio.h>

/*
    http://www.spoj.com/problems/COLONY/

    Year 0: R
    Year 1: BR
    Year 2: RBBR
    Year 3: BRRBRBBR
    Year 4: RBBRBRRBBRRBRBBR

    We revert the process to understand what is the original index.
    If we analyse the years, we can see that the first 'R in "Year 0" will
    increase its index in 2*n. So, if we revert the process, we will have
    index divided by 2.

    When we go back to the first year, we can define which of them will be
    the odd and even indexes. In this case, we decided that the even number will be red.

*/

typedef long long LL;

int get_index(LL y, LL p) {
    if(y == 0) return 0;
    else if(p % 2 == 0) return get_index(y-1, p/2) + 1;
    else return get_index(y-1, p/2);
}

int main() {
    int index;
    LL y, p;

    scanf("%lld", &y);
    scanf("%lld", &p);

    if(get_index(y, p) % 2 == 0) printf("red\n");
    else printf("blue\n");

    return 0;
}
