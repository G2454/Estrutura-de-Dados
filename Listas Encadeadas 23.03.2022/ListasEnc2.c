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
    Lista *rep;
    Lista *temp;

    temp = (Lista *)malloc(sizeof(Lista));
    rep = (Lista *)malloc(sizeof(Lista));

    rep->valor = 10;
    rep->prox = (Lista *)malloc(sizeof(Lista));

    rep->prox->valor = 20;
    rep->prox->prox = (Lista *)malloc(sizeof(Lista));

    rep->prox->prox->valor = 30;
    rep->prox->prox->prox = NULL;

    temp->valor = 40;
    temp->prox = rep->prox->valor;

    return 0;
}