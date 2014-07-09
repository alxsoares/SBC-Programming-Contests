#include <stdio.h>
#include <string.h>

#define NMAX 100001
#define MMAX 10001

char W[MMAX];
char S[NMAX];
char T[MMAX];

int kmp_search(char W[], char S[]) {

  int m = 0;
  int i = 0;

  while((S[m+i] != 0) && (W[i] != 0))
      if(S[m+i] == W[i]) i++;
      else {
        m += i - T[i];
        if(i > 0) i = T[i];
      }

  if(W[i] == 0) return m;
  else return m + i;

}

void kmp_table(char W[]) {
  int i = 2;
  int j = 0;

  T[0] = -1;
  T[1] =  0;

  while(W[i] != 0)
      if(W[i-1] == W[j]) T[i++] = ++j;
      else if(j > 0) j = T[j];
      else T[i++] = j = 0;

  return;
}

int main() {
  int i,j;

  printf("KMP Testing\n");

  printf("Needle: ");
  gets(W);

  kmp_table(W);

  printf("Haystack: ");
  gets(S);

  i = kmp_search(W, S);
  if(S[i] == 0) printf("Not found.\n");
  else printf("Index: %d\n", i);

  return 0;
}
