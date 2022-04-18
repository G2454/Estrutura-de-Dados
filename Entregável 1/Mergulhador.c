#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// FAZER UMA FUNCAO PARA ENTRAR OS NUMEROS DE FORMA AUTOMATICA (1-10)
// FAZER A FUNCAO PARA REMOVER OS NUMEROS DESSA LISTA
// FAZER UM VERIFICADOR DE CASO NENHUM NUMERO FOI REMOVIDO

// PRIMEIRA LINHA DO PRINTF -> NUMERO DE MERGULHADORES
// SEGUNDA LINHA DO PRINTF -> QUANTOS RETORNARAM
// SEGUNDA LINHA DO PRINTF -> * (TODOS RETORNARAM)

typedef struct lista
{
    int valor;
    struct lista *prox;
} Lista;

void imprime(Lista *HP)
{
    while (HP != NULL)
    {
        printf(" %d ", HP->valor);
        HP = HP->prox;
    }
}

Lista *removeLista(Lista *L, int info)
{
    Lista *aux = L;
    Lista *ant = NULL;

    // Procure pelo valor na lista
    while (aux != NULL && aux->valor != info)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    { // Nao achou o elemento
        L = "*";
        return L;
    }
    else if (ant == NULL)
    {                  // Remove do inicio
        L = aux->prox; // Atualiza para segunda posicao
        free(aux);
    }
    else
    {
        ant->prox = aux->prox;
        free(aux);
    }

    return L;
}

// Funcao que insere os mergulhadores automaticamente
Lista *insereIni(Lista *tempRef, int v)
{
    Lista *pNovo = (Lista *)malloc(sizeof(Lista));
    pNovo->valor = v + 1;
    pNovo->prox = tempRef;

    return pNovo;
}

int main()
{
    int total;
    int contador;
    int voltaram;

    Lista *Mergulhadores; // lista que vai guardar os mergulhadores
    Lista *MergulhadoresVoltaram;
    Mergulhadores = NULL;
    contador = 0;

    // Entrada do numero de mergulhadores que foram
    printf("Quantos mergulhadores foram: [0,10] ");
    scanf("%d", &total);

    printf("\n");

    // Cria de forma automatica a lista
    while (contador < total)
    {
        Mergulhadores = insereIni(Mergulhadores, contador);
        contador = contador + 1;
    }
    contador = 0;

    // Entrada do numero de mergulhadores que voltaram
    printf("Quantos mergulhadores voltaram: [0,10] ");
    scanf("%d", &voltaram);

    // criacao de uma segunda lista para armazenar os que voltaram
    if (voltaram != 0)
    {
        contador = voltaram;
        printf("Quais voltaram: ");
        while (contador != 0)
        {
            int auxiliar;
            scanf("%d", &auxiliar);
            MergulhadoresVoltaram = insereIni(MergulhadoresVoltaram, auxiliar);
        }
    }

    imprime(Mergulhadores);

    printf("\n");

    imprime(MergulhadoresVoltaram);

    // Mergulhadores = removeLista(Mergulhadores, 3);

    printf("\n");

    return 0;
}