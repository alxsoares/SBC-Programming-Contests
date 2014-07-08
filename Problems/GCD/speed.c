#include <stdio.h>
#define abs(a) (a>0?a:-a)

// http://www.spoj.com/problems/SPEED/

int gcd(n, m) {
  if (n % m == 0) return m;
  return gcd(m, n % m);
}


int main() {
    int t, a, b, ans, gcc;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &a, &b);

        gcc = gcd(abs(a),abs(b));

        a = a/gcc;
        b = b/gcc;

        if(a-b < 0) ans = b-a;
        else ans = a-b;

        printf("%d\n", ans);
    }
    return 0;
}
