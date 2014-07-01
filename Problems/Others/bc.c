#include <stdio.h>
#include <math.h>

/*

http://www.spoj.com/problems/BC/

b: We can break the chocolate bar in 2 pieces. Consequently, each piece can be
   cut off in more 2 pieces. So, the minimum number of steps for this case is:

   log2(n) + log2(m) + log2(k) = ln(n) + ln(m) + ln(k)

   Furthermore, we need to round values, because we just have integer steps.
*/

int main() {
    long long a;
    int t, b, c = 1;
    double n, m, k;

    //freopen("bc.txt", "r", stdin);
    scanf("%d", &t);

    while(t--) {
        b = 0;
        scanf("%lf %lf %lf", &n, &m, &k);

        a = (n * m * k) - 1;
        b = (int)(ceil(log(n)/log(2.0)) + ceil(log(m)/log(2.0)) + ceil(log(k)/log(2.0)));

        printf("Case #%d: %lld %d\n", c++, a, b);
    }

    return 0;
}
