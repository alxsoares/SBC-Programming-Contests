#include <stdio.h>
#include <string.h>

// http://www.spoj.com/problems/ABCD/

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    /*
        rows[0] = first row
        rows[1] = second row
        100005 = max "n" value = 50000 * 2 + 5
    */

    char rows[2][100005];
    int i, j, n, letters[4] = {0};

    scanf("%d", &n);
    scanf("%s", rows[0]);

    for(i = 0; i < 2*n; i += 2) {
        /*
            Instead of changing characters, we can change its decimal values
            according to the ASCII table to improve the performance.

            This means that, in the next two lines of code, if we have letters CB:

            letters = [1, 1, 1, 1]

            letters['C' - 'A] = letters['B' - 'A'] = 0
            letters[67 - 65] = letters[66 - 65] = 0
            letters[2] = letters[1] = 0

            letters = [1, 0, 0, 1]
        */

        letters[0] = letters[1] = letters[2] = letters[3] = 1;
        letters[rows[0][i] - 'A'] = letters[rows[0][i+1] - 'A'] = 0;

        // 4 letters: A, B, C and D.
        // 65 = 'A' in ASCII
        for(j = 0; j < 4; j++)
            if(letters[j]) {
                letters[j] = 0;
                rows[1][i] = j+65;
                break;
            }

        for(j = 0; j < 4; j++)
            if(letters[j]) {
                letters[j] = 0;
                rows[1][i+1] = j+65;
                break;
            }

        // Verifying adjacent cells
        if(rows[1][i] == rows[1][i-1])
            swap(&rows[1][i], &rows[1][i+1]);
    }

    printf("%s", rows[1]);
    return 0;
}
