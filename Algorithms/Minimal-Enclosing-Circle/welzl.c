#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

#define EPSILON 1e-06
#define MAXPOINTS 100

// Problem: Find the smallest circle containing the points P[1]..P[n]

typedef struct point *PointPtr;

typedef struct point {
    double x, y;
} Point;

typedef struct {
    double x, y, r;
} Circle;

typedef struct {
    PointPtr* array;
} PointArray;

/* Performance measures */
int callsCircle3;
int callsMinFix2;
int callsMinFix1;

/* Variables */
int useRandomized;

int PointInsideCircle (Point *p, Circle *c) {
    double dx, dy;

    dx = p->x - c->x;
    dy = p->y - c->y;
    return (dx*dx + dy*dy) <= (c->r*c->r);
}

void Circle1 (Point *p, Circle *c) {
    c->x = p->x;
    c->y = p->y;
    c->r = 0;
}

void Circle2 (Point *p1, Point *p2, Circle *c) {
    double dx, dy;

    c->x = 0.5*(p1->x + p2->x);
    c->y = 0.5*(p1->y + p2->y);
    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    c->r = 0.5*sqrt(dx*dx + dy*dy);
}

void Circle3 (Point *p1, Point *p2, Point *p3, Circle *c) {
    Point e10, e20;
    double A[2][2];
    double b[2], x[2];
    double det;

    callsCircle3++;    /* Performance measure, can be removed */

    e10.x = p2->x - p1->x;
    e10.y = p2->y - p1->y;

    e20.x = p3->x - p1->x;
    e20.y = p3->y - p1->y;

    A[0][0] = e10.x;   A[0][1] = e10.y;
    A[1][0] = e20.x;   A[1][1] = e20.y;

    b[0] = 0.5f*(e10.x*e10.x + e10.y*e10.y);
    b[1] = 0.5f*(e20.x*e20.x + e20.y*e20.y);

    det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

    if (fabs(det) > EPSILON) {
        x[0] = (A[1][1]*b[0] - A[0][1]*b[1])/det;
        x[1] = (A[0][0]*b[1] - A[1][0]*b[0])/det;

        c->x = p1->x + x[0];
        c->y = p1->y + x[1];
        c->r = sqrt(x[0]*x[0] + x[1]*x[1]);
    } else {
        c->x = DBL_MAX;
        c->y = DBL_MAX;
        c->r = DBL_MAX;
    }
}

void MinFix2 (int n, PointArray *perm, Point *fixed1, Point *fixed2, Circle *c) {
    int i;

    callsMinFix2++;    /* Performance measure, can be removed */

    Circle2(fixed1, fixed2, c);

    for (i = 0; i < n; i++)
        if (!PointInsideCircle(perm->array[i], c))
            Circle3(perm->array[i], fixed1, fixed2, c);
}

void MinFix1 (int n, PointArray *perm, Point *fixed, Circle *c) {
    int i;

    callsMinFix1++;    /* Performance measure, can be removed */

    Circle1(fixed, c);

    for (i = 0; i < n; i++)
        if(!PointInsideCircle(perm->array[i], c))
            MinFix2(i, perm, perm->array[i], fixed, c);
}


/*
 * Preserves the ordering of the original set of points, just in
 * case. Note that the contents of Circle *c at the end will be
 * that of the minimal circle.
 */
void MinimalCircle (int n, PointArray *p, Circle *c) {
    PointArray perm;
    int i, j;
    PointPtr temp;

    /* assert: n >= 1 */

    if(n >= 2) {
        /* create identity permutation (0,1,...,n-1) */
        perm.array = (PointPtr *) malloc (n * sizeof (PointPtr));

        for(i = 0; i < n; i++)
          perm.array[i] = p->array[i];

        if(useRandomized) {
            /* generate random permutation */
            for(i = n-1; i > 0; i--) {
                j = rand() % (i+1);

                if(j != i) {
                  temp = perm.array[i];
                  perm.array[i] = perm.array[j];
                  perm.array[j] = temp;
                }
            }
        }

        Circle1(perm.array[0], c);

        for(i = 1; i < n; i++)
            if(!PointInsideCircle(perm.array[i], c))
                MinFix1(i, &perm, perm.array[i], c);

        free(perm.array);
    } else Circle1(p->array[0], c); /* n == 1 */
}

int main() {
    freopen("welzl.txt", "r", stdin);

    double x, y;
    int count = 0, i, n;

    PointPtr temp;
    PointArray ourArray;
    Circle result;

    /* Create the array to hold the points */
    ourArray.array = (PointPtr *) malloc (MAXPOINTS * sizeof(PointPtr));

    for(i = 0; i < MAXPOINTS; i++)
        ourArray.array[i] = (Point *) malloc (sizeof (Point));

    //scanf("%d", &n);

    while(scanf("%lf %lf", &x, &y) != EOF) {
        temp = ourArray.array[count++];
        temp->x = x;
        temp->y = y;
    }

    if(count > 0) MinimalCircle(count, &ourArray, &result);

    printf("(%4.2f, %4.2f) r = %4.2f\n", result.x, result.y, result.r);

    for(i = 0; i < MAXPOINTS; i++)
        free(ourArray.array[i]);

    free(ourArray.array);

    return 0;
}
