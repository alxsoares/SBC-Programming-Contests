#include <stdio.h>

// http://br.spoj.com/problems/OBITETRI/

struct campeonato {
    char nome[15];
    int pontuacao[12];
    int total;
};

int comparar(const void *a, const void *b) {
    struct campeonato *i = (struct campeonato *) a;
    struct campeonato *j = (struct campeonato *) b;

    if(i->total == j->total) {
        if((int) i->nome[0] > (int)j->nome[0]) return 1;
        else return 0;
    }
    else if(i->total > j->total) return -1;
    else return 1;
}

void quick_sort( int y[], int m) {
    int p, q, r;
    int i, j;
    int t[m];
    int b;

    b = y[m/2];

    for(p = q = r = i = 0; i < m; i++)
        if(y[i] < b)
            y[p++] = y[i];
        else if(y[i] > b)
            t[q++] = y[i];
        else r++;

    if(p > 1) quick_sort(y, p);
    if(q > 1) quick_sort(t, q);

    for(j = 0, i = p; j < r; j++, i++)
        y[i] = b;
    for(j = 0; j < q; j++, i++)
        y[i] = t[j];
}

int main() {
    int i, j, k, teste = 1, pos;

    //freopen("obitetri.txt","r",stdin);

    scanf("%d", &j);

    while(j > 0) {
        pos = 1;
        struct campeonato c[j];

        for(i = 0; i < j; i++) {
            scanf("%s", c[i].nome);

            c[i].total = 0;

            for(k = 0; k < 12; k++) {
                scanf("%d", &c[i].pontuacao[k]);
                c[i].total += c[i].pontuacao[k];
            }

            quick_sort(c[i].pontuacao, 12);
            c[i].total -= c[i].pontuacao[0] + c[i].pontuacao[11];
        }

        qsort(c, j, sizeof(struct campeonato), comparar);

        printf("Teste %d\n", teste++);

        for(i = 0; i < j; i++) {
            if(c[i].total == c[i-1].total && i != 0) {
                printf("%d %d %s\n", pos-1, c[i].total, c[i].nome);
                pos++;
            }
            else printf("%d %d %s\n", pos++, c[i].total, c[i].nome);
        }

        printf("\n");
        scanf("%d", &j);
    }

    return 0;
}
