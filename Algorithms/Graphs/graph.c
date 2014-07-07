#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXV 1000

typedef struct {
    int y; /* adjacency info */
    int weight; /* edge weight, if any next edge in list */
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1]; /* adjacency info */
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nvertices; /* number of vertices in graph */
    int nedges; /* number of edges in graph */
    bool directed; /* is the graph directed? */
} grafo;

initialize_graph(grafo *g, bool directed) {
    int i;

    g->nvertices = g->nedges = 0;
    g->directed = directed;

    for(i = 0; i <= MAXV; i++) g->degree[i] = 0;
    for(i = 0; i <= MAXV; i++) g->edges[i] = NULL;
}

insert_edge(grafo *g, int x, int y, bool directed) {
    edgenode *p; /* temporary pointer */

    p = malloc(sizeof(edgenode));

    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; /* insert at head of list */
    g->degree[x]++;

    if(directed == false) insert_edge(g, y, x, true);
    else g->nedges++;
}

read_graph(grafo *g, bool directed) {
    int i;
    int m; /* number of edges */
    int x, y; /* vertices in edge (x,y) */

    initialize_graph(g, directed);
    scanf("%d %d", &(g->nvertices), &m);

    for(i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

int main() {
    grafo g;
    edgenode e;

    read_graph(&g, true);
    return 0;
}
