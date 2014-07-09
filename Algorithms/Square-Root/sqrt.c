#include <stdio.h>

int isqrt(int n) {
  int a, b, m;

  a = 0;
  b = 65537;

  do {
    m = (a + b) / 2;
    if(m * m <= n) a = m;
    else b = m;
  } while(b - a > 1);

  return a;
}

int main() {
  int n;

  for(n = 0; n < 10; n++) printf("%d: %d\n", n, isqrt(n));

  return 0;
}
