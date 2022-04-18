#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct lista *prox;
    struct lista *ante;
} Lista;

int main()
{

    Lista *Rep = (Lista *)malloc(sizeof(Lista));
    Rep->valor = 10;
    Rep->ante = NULL;

    Rep->prox = (Lista *)malloc(sizeof(Lista));
    Rep->prox->valor = 20;
    Rep->prox->ante = Rep;

    Rep->prox->prox = (Lista *)malloc(sizeof(Lista));
    Rep->prox->prox->valor = 30;
    Rep->prox->prox->ante = Rep->prox;
    Rep->prox->prox->prox = NULL;

    return 0;
}