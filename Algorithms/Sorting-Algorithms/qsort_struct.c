#include <stdio.h>
#include <stdlib.h>

struct teste {
  int x;
  int y;
};

int comp(const void *a, const void *b) {
  struct teste *i = (struct teste *) a;
  struct teste *j = (struct teste *) b;

  if( i->y > j->y ) return 1;
  else if( i->y < j->y ) return -1;
  else return 0;
}

int main() {
  int i;
  struct teste z[50];

  for( i = 0; i < 50; i++ ) {
    z[i].x = rand();
    z[i].y = rand();
  }

  printf("Before:\n" );
  for( i = 0; i < 50; i++ ) printf( "[%6d: %6d]", z[i].x, z[i].y );

  qsort( z, 50, sizeof( struct teste ), comp );

  printf( "\n\nAfter:\n" );
  for( i = 0; i < 50; i++ ) printf( "[%6d: %6d]", z[i].x, z[i].y );

  printf("\n");
  return 0;
}
