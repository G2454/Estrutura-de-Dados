#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct lista *prox;

} Lista;

Lista *deslocaMaior(Lista *aux)
{
    Lista *auxMaior;
    Lista *auxMenor;
    auxMaior = NULL;
    auxMenor = NULL;

    while (aux != NULL)
    {

        if (auxMaior->valor < aux->valor)
        {
            auxMenor = auxMaior;
            auxMaior = aux->valor;
        }
        auxMenor = aux;
        aux = aux->prox;
    }
    auxMenor->prox = auxMaior->prox;
    auxMaior->prox = aux;
    return auxMaior;
}

void imprime(Lista *HP)
{
    Lista *L;
    L = HP;
    while (L != NULL)
    {
        printf(" %d ", L->valor);
        L = L->prox;
    }
    printf("\n");
}

int main()
{
    Lista *rep;

    rep = (Lista *)malloc(sizeof(Lista));

    // CRIACAO DOS LISTA

    rep->valor = 10;
    rep->prox = (Lista *)malloc(sizeof(Lista));
    rep->prox->valor = 20;
    rep->prox->prox = (Lista *)malloc(sizeof(Lista));
    rep->prox->prox->valor = 30;
    rep->prox->prox->prox = (Lista *)malloc(sizeof(Lista));
    rep->prox->prox->prox->valor = 40;
    rep->prox->prox->prox->prox = NULL;

    // funcao printf
    imprime(rep);

    // DESLOCAO MAIOR PARA O COMECO DA LISTA
    rep = deslocaMaior(rep);

    // Verificacao se deu certo
    imprime(rep);

    return 0;
}
