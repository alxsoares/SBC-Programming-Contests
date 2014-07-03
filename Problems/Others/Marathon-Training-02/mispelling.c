#include <stdio.h>
#define MAX 100

// http://www.spoj.pl/problems/GNY07A/

int main() {
    int n, pos, i;
    char word[MAX];

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d %s", &pos, &word);
		word[pos-1] = '\0';
		printf("%d %s%s\n", i + 1, word, word + pos);
	}

	return 0;
}
