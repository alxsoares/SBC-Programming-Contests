#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// http://www.spoj.com/problems/GNY07B/

int main() {
    int n, i;
    float value;
    char *unit = malloc(2);

    freopen("conversions.txt", "r", stdin);
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%f %s", &value, unit);

        if(strcmp(unit, "kg") == 0)
            printf("%d %.4f lb\n", i+1, value*2.2046);
        else if(strcmp(unit, "lb") == 0)
            printf("%d %.4lf kg\n", i+1, value*0.4536);
        else if(strcmp(unit, "l") == 0)
            printf("%d %.4lf g\n", i+1, value*0.2642);
        else if(strcmp(unit, "g") == 0)
            printf("%d %.4f l\n", i+1, value*3.7854);
    }

    return 0;
}
