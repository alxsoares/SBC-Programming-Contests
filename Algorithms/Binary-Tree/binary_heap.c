#include <stdio.h>
#include <stdlib.h>

#define HEAPCOUNT 100

int count = 0;

/*
* find the smallest among the left(data[pos])  and
* right child(data[pos + 1]).  Check whether the smallest
* among them is lesser than their parent.  If so, swap
* parent and the node with smallest value.  Continue the
* above processing from index "low" to "count"
*         40
*        /   \
*       10   30
*  10 is smaller tha 30. 10 is comapared with its parent
*  and it is smaller(10 < 40).  So, swap parent and 10.
*         10
*       /    \
*      40    30
*/
void insert_heap(int *data, int low, int count) {
    int pos = (2 * low) + 1, current = data[low];

    while (pos <= count) {
        if (pos < count && data[pos] > data[pos + 1]) pos++;
        if (current <= data[pos]) break;
        else {
            data[low] = data[pos];
            low = pos;
            pos = (2 * low) + 1;
        }
    }

    data[low] = current;
    return;
}

/*
* To construct a heap we always consider the
* nodes which are present above the leaf.  Here,
* nodes present after data[n/2 - 1] are leaf nodes
* insertHeap() - used for restoring the heap
* data - holds node values & n - node count
*/
void build_heap(int *data, int n) {
    int low;

    for (low = n/2 - 1; low >= 0; low--)
        insert_heap(data, low, n-1);

    return;
}

void build_up(int *data, int index) {
    int val = data[index];
    /* if parent of the current node has value
     * greater than its child, then swap parent
     * and child nodes.  Traverse up the tree
     * until u hit a condition where parent node
     * is having lesser value than children
     */

    while (data[(index - 1) / 2] >= val) {
        data[index] = data[(index - 1) / 2];
        if (!index) break;
        index = (index - 1) / 2;
    }

    data[index] = val;
    return;
}

/* adding new node to the binary heap */
void add_node(int *data, int val, int n) {
    data[n] = val;
    build_up(data, n);
    return;
}

/* delete a node from binary heap */
void delete_node(int *data, int n) {
    int val = data[0];
    data[0] = data[n];
    insert_heap(data, 0, n - 1);
    printf("%d is deleted from the heap\n", val);
    return;
}

/* replacing root node with value val */
void replaceNode(int *data, int val, int n) {
    int i;

    data[0] =  val;

    for (i = n/2 - 1; i >= 0; i--)
        insert_heap(data, i, n - 1);

    return;
}

void display(int *data, int n) {
    int i;

    printf("\nData in Binary Heap:\n");
    for (i = 0; i <= n; i++) printf("%d ", data[i]);
    printf("\n\n");
}

void sort_heap(int *data, int n) {
    // swap root and current last node, then perform
    // restore heap to get data in sorted order. Basically,
    // we are performing insort operation.
    int i, temp;

    for (i = n - 1; i > 0; i--) {
        temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        insert_heap(data, 0, i - 1);
    }

    printf("Sorted Data:\n");
    for (i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");
}

int main() {
    int n, i, *data, temp, ch, val;
    data = (int *)malloc(sizeof(int) * HEAPCOUNT);
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        count++;
    }

    build_heap(data, n);

    /* Adding a new node - number 12*/
    add_node(data, 12, n++);

    /*
    delete_node(data, n -1);
    n--;
    */

    /* Replacing a node */
    replaceNode(data, 17, n);

    /* Show values*/
    display(data, n - 1);

    sort_heap(data, n);
    return 0;
}
