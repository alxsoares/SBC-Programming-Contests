#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXV 100

int flg[MAXV+1], pai[MAXV+1], discovered[MAXV+1];

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

initialize_search(grafo *g) {
    int i;

    for(i = 1; i <= g->nvertices; i++) {
        flg[i] = 0;
        pai[i] = -1;
    }
}

insert_edge(grafo *g, int x, int y) {
    edgenode *p; /* temporary pointer */

    p = malloc(sizeof(edgenode));

    //p->weight = NULL;
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; /* insert at head of list */
    g->degree[x]++;

    //if(directed == false) insert_edge(g, y, x, true);
    //else g->nedges++;
    g->nedges++;
}

dfs(grafo *g, int v) {
    edgenode *p; /* temporary pointer */
    int y;
    /* successor vertex */
    discovered[v] = true;

    for(p = g->edges[v]; p != NULL; p = p->next) {
        y = p->y;

        if(discovered[y] == false) {
            pai[y] = v;
            dfs(g, y);
        }
    }
}

find_path(int ini, int end) {
    if((ini == end) || (end == -1))
        printf( "\n%d", ini );
    else {
        find_path(ini, pai[end]);
        printf(" %d", end);
    }
}

int main() {
    int i, m, x, y;
    grafo g;

    scanf("%d %d", &(g.nvertices), &m);

    for(i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(&g, x, y);
    }

    initialize_search(&g);
    //dfs(&g, 0);

    return 0;
}
