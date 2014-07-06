#include <stdio.h>
#include <math.h>

#define MAX_RANGE 1000
#define MAX_N 301
#define MAX_ITER 40

// http://www.spoj.com/problems/QCJ4/

//  n (<301) the number of points in the plane
int n, x[MAX_N], y[MAX_N];

double get_radius(double X, double Y) {
    int i;
    double ret = 0;

    for(i = 0; i < n; i++)
        if((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]) > ret)
            ret = (X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]);

    return ret;
}

double searchY(double X) {
    double lo = 0, hi = MAX_RANGE;
    int i;

    for(i = 0; i < MAX_ITER; i++) {
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;

        double ra = get_radius(X, a);
        double rb = get_radius(X, b);

        if(ra < rb) hi = b;
        else lo = a;
    }

    return get_radius(X, lo);
}

double searchX() {
    double lo = 0, hi = MAX_RANGE;
    int i;

    for(i = 0; i < MAX_ITER; i++) {
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;

        double ra = searchY(a);
        double rb = searchY(b);

        if(ra < rb) hi = b;
        else lo = a;
    }

    return searchY(lo);
}

int main(){
    freopen("min_diameter.txt", "r", stdin);

    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    printf("%.2f\n", sqrt(searchX()) * 2);

    return 0;
}
