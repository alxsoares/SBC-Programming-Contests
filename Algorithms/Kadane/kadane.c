#include <stdio.h>

int start = 0, end = 0, sum = 0;

void kadane(int a[], int size_a) {
    int limit = 0, i, f, n;

    for(f = 0; f < 7; f++ ) {
        if( limit + a[f] < 0 ) {
            i = f + 1;
            limit = 0;
        } else limit = limit + a[f];

        if( limit > sum ) {
            sum = limit;
            start = i;
            end = f;
        }
    }
}

int main() {
    int a[] = {31, -41, 59, 26, -53, 58, 97};

    kadane(a, sizeof(a)/sizeof(a[0]));
    printf("Start: %d\nEnd: %d\nSum: %d", start, end, sum);

    return 0;
}
