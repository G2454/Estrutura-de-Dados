#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int valor;
    struct lista *prox;
} Lista;

int main()
{
    Lista *ref;
    ref = (Lista *)malloc(sizeof(Lista));
    ref->valor = 10;

    ref->prox = (Lista *)malloc(sizeof(Lista));
    ref->prox->valor = 20;

    ref->prox->prox = (Lista *)malloc(sizeof(Lista));
    ref->prox->prox->valor = 30;

    ref->prox->prox->prox = NULL;

    printf("%d ", ref->valor);
    printf("%d ", ref->prox->valor);
    printf("%d", ref->prox->prox->valor);
    return 0;
}