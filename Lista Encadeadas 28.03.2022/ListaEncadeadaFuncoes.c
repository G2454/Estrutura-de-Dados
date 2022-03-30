// O programa se trata de uma lista encadeada com funcoes

// O programa vai substituir valores negativos

#include <stdio.h>
#include <string.h>

typedef struct lista
{
    int valor;
    struct lista *prox;
} Lista;

// Funcao imprimir
void imprime(Lista *HP)
{
    while (HP != NULL)
    {
        printf(" %d ", HP->valor);
        HP = HP->prox;
    }
}

// Funcao que insere um numero no inicio InsereIni()

Lista *insereIni(Lista *carro, int numero)
{
    Lista *L = (Lista *)malloc(sizeof(Lista));
    L->valor = numero;
    L->prox = carro;
    return L;
}

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

    // Chamanado InsereInicio()

    ref = insereIni(ref, 69);

    // Funcao print - antes da substituicao dos numeros negativos

    imprime(ref);

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

    // Funcao print - apos substituicao dos numeros negativos
    imprime(ref);

    return 0;
}