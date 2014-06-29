#include <stdio.h>
#include<stdlib.h>
#define MAX_ALUNOS 1000

// http://br.spoj.com/problems/ESTAGIO/

struct lista {
    int codigo, media;
} alunos[MAX_ALUNOS];

int comparar(const void *a, const void *b) {
    struct lista *i = (struct lista *) a;
    struct lista *j = (struct lista *) b;

    if(i->media == j->media) return 0;
    else if(i->media > j->media) return -1;
    else return 1;
}

int main() {
    int i, maior_media, n;
    int turma = 1;

    scanf("%d", &n);

    while (n > 0) {
        for (i = 0; i < n; i++)
         scanf("%d %d", &alunos[i].codigo, &alunos[i].media);

        qsort(alunos, n, sizeof(struct lista), comparar);

        printf("Turma %d\n", turma++);
        maior_media = alunos[0].media;

        for (i = 0; i < n; i++)
            if(alunos[i].media == maior_media)
                printf("%d ", alunos[i].codigo);
            else break;

        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
