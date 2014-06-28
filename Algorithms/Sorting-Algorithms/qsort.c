#include <stdio.h>
#include <stdlib.h>

/*
    Complexity: O(Nlog(n))

    qsort(void *v, int n, size_t s, int compare(const void *, const void *))
    n = number of items
    s = number of bytes needed
    compare = function that will compare items

    In relation to compare function:

    a == b --> 0
    a > b  --> -1 (for ascending order)
    a < b  --> 1 (for descending order)

*/

int compare_asc(const void *a, const void *b) {
    if((int *) a == (int *) b) return 0;
    else if((int *) a > (int *) b) return -1;
    else return 1;
}

int compare_desc(const void *a, const void *b) {
    if(*(int *) a == *(int *) b) return 0;
    else if(*(int *) a > *(int *) b) return -1;
    else return 1;
}

int main() {
    int i, vec[50];
    int vec_length = sizeof(vec)/sizeof(int);

    for( i = 0; i < 50; i++ ) vec[i] = rand();

    printf("Before:\n");

    for(i = 0; i < vec_length; i++)
        printf("%d ", vec[i]);

    printf("\n\nAscending Order:\n");

    qsort(vec, vec_length, sizeof(int), compare_asc);

    for(i = 0; i < vec_length; i++)
        printf("%d ", vec[i]);

    printf("\n\nDescending Order:\n");

    qsort(vec, vec_length, sizeof(int), compare_desc);

    for(i = 0; i < vec_length; i++)
        printf("%d ", vec[i]);

    return 0;
}
