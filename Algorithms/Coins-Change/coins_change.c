#include <stdio.h>

/*
    Given a value N, if we want to make change for N cents,
    and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
    how many ways can we make the change? The order of coins doesn’t matter.

    For example, for N = 4 and S = {1,2,3}, there are 4 solutions:
    {1,1,1,1},{1,1,2},{2,2} and {1,3}.
*/

int count(int S[], int m, int n) {
    int i, j, x, y;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for(i = 0; i < m; i++) table[0][i] = 1;

    // Fill rest of the table enteries in bottom up manner
    for(i = 1; i < n+1; i++) {
        for(j = 0; j < m; j++) {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }

    return table[n][m-1];
}

int main() {
    int coins[] = {1, 2, 3};
    int n = 4;
    int m = sizeof(coins)/sizeof(coins[0]);

    printf("%d ", count(coins, m, n));

    return 0;
}
