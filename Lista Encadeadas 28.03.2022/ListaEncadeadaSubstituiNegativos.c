//O programa vai substituir valores negativos


#include <stdio.h>
#include <string.h>

typedef struct lista
{
    int valor;
    struct lista *prox;
} Lista;

int main()
{
    Lista *ref;
    Lista *temp;

    ref = (Lista *)malloc(sizeof(Lista));
    ref->valor = 10;

    ref->prox = (Lista *)malloc(sizeof(Lista));
    ref->prox->valor = -1;

    ref->prox->prox = (Lista *)malloc(sizeof(Lista));
    ref->prox->prox->valor = 30;

    ref->prox->prox->prox = NULL;

    // print dos valores antes da substituicao

    printf("%d ", ref->valor);
    printf(" %d ", ref->prox->valor);
    printf(" %d ", ref->prox->prox->valor);

    // Substituicao dos numeros negativos
    temp = ref;

    while (temp != NULL)
    {
        if (temp->valor < 0)
        {
            temp->valor = 1;
        }
        temp = temp->prox;
    }

    // print dos valores apos a substituicao
    printf("\n \n");
    printf("%d ", ref->valor);
    printf(" %d ", ref->prox->valor);
    printf(" %d", ref->prox->prox->valor);

    return 0;
}