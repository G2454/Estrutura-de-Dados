#include <stdio.h>

typedef struct
{
    char nome[100];
    int RA;
    float media;
} Aluno;

int main()
{
    Aluno *aluno;
    aluno = (Aluno *)malloc(sizeof(Aluno));

    strcpy(aluno->nome, "Joao");
    aluno->RA = 2312062;
    aluno->media = 2.0;

    printf("Nome: %s\n RA: %d\n Media: %.1f", aluno->nome, aluno->RA, aluno->media);

    return 0;
}