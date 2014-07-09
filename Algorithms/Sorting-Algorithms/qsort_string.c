#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *p[150];
char s[150][32];

/*---------------------------------------------------------------*/

int comp(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

/*---------------------------------------------------------------*/

int main() {
  int n;
  int i;

#ifndef ONLINE_JUDGE
  //freopen(  "in.txt", "r", stdin  );
  //freopen( "out.txt", "w", stdout );
#endif

  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%s", p[i] = s[i]);

  printf("\nAfter:\n");
  for( i = 0; i < n; i++ ) printf("%s\n", p[i]);

  qsort( p, n, sizeof( char *), comp);

  printf("\nBefore:\n");
  for( i = 0; i < n; i++ ) printf( "%s\n", p[i]);

  return 0;
}
