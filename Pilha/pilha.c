#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"
#include <string.h>


struct lista
{
    int info;
    struct lista *prox;
};


int Vazia(Lista l)
{
    if(l == NULL);
}


int conta(Lista l)
{
        int he=0;
        if(!Vazia(l))
            return 0;

        else
        {
            he = 1+ conta(l->prox);
        }
    return he;
}


int Cheia(Lista l)
{
    int h;
    h = conta(l);
    if(h == 5)
    {
        printf(" A fila esta cheia");
        return 1;
    }
    else
        return 0;
}


void imprimir(Lista l)
{
    if(l != NULL)
    {
        printf("%d ", l->info);
        imprimir(l->prox);
    }
}
