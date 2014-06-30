#include <stdio.h>
#define HEAP_SIZE 20

/* Heap sort is slower in practice than quicksort,
   but it has the advantage in worst case O(n log n).
*/

typedef struct {
    int q[HEAP_SIZE+1];
    int n;
} my_heap;

heap_parent(int n) {
    return n/2;
}

left_child(int n) {
    return n*2;
}

right_child(int n) {
    return n*2 + 1;
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

heap_init(my_heap *q) {
    q->n = 0;
}

void heap_up(my_heap *h, int p) {
    // The root
    if(heap_parent(p) == 0) return;

    // According to binary tree, parent must be
    // less than your children. Furthermore:
    if(h->q[heap_parent(p)] > h->q[p]) {
        swap(&h->q[p], &h->q[heap_parent(p)]);
        heap_up(h, heap_parent(p));
    }
}

void insert(my_heap *h, int x) {
    // Updating the next position, inserting the value into this position
    // and swaap values in relation to its parent, if necessary.
    h->n = h-> n+1;
    h->q[h->n] = x;
    heap_up(h, h->n);
}

int get_smallest(my_heap *h) {
    // Getting the smallest element into the heap.
    // q[0] will be the root, and q[1] will be the first left children.
    return h->q[1];
}

void heap_down(my_heap *h, int p) {
    int left = left_child(p), mn = p;

    // Verifying left children
    if(left <= h->n && h->q[mn] > h->q[left]) mn = left;

    // Verifying right children
    if(left+1 <= h->n && h->q[mn] > h->q[left+1]) mn = left+1;

    if(mn != p) {
        swap(&h->q[p], &h->q[mn]);
        heap_down(h, mn);
    }
}

int remove_value(my_heap *h) {
    int r = get_smallest(h);

    h->q[1] = h->q[h->n];
    h->n = h->n - 1;
    heap_down(h, 1);

    return r;
}

int main() {
    int i;
    int x[20];
    my_heap h;

    for(i = 0; i < 20; i++) x[i] = rand();

    printf("Before:\n");
    for(i = 0; i < 20; i++) printf("%d ", x[i]);

    heap_init(&h);
    for(i = 0; i < 20; i++) insert(&h, x[i]);

    printf( "\n\nHeap:\n");
    for(i = 0; i < 20; i++) printf("%d ", h.q[i]);

    for(i = 0; i < 20; i++) x[i] = remove_value(&h);

    printf( "\n\nAfter:\n" );
    for(i = 0; i < 20; i++ ) printf( "%d ", x[i]);

    return 0;
}
