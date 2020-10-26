#include "fila.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



struct lista
{
    int info;
    struct lista *prox;
};


Lista inicializar(Lista l)
{
    l = NULL;
    return l;
}


int Vazia(Lista l)
{
    if(l == NULL);
}


Lista destruir(Lista l)
{
    Lista s;

    if(l != NULL)
    {
        s = l->prox;
        free(l);
        return destruir(s);
    }

    else
        return NULL;
}



Lista inserir(Lista l, int x)
{
    if(l == NULL)
    {
        l=(Lista) malloc(sizeof(Lista));
        l -> info = x;
        l -> prox = NULL;
        return l;
    }

    else
    {
        l->prox = inserir(l->prox, x);
        return l;
    }
}


Lista remover(Lista l)
{
    Lista a;

    if(l==NULL)
        return 0;

    else
    {
        if(l->info != NULL)
        {
            a = l;
            l = l->prox;
            free(a);
            return l;
        }

        else
            l->prox = remover(l->prox);


        return l;
    }
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


void imprimir(Lista l)
{
    if(l != NULL)
    {
        printf("%d ", l->info);
        imprimir(l->prox);
    }
}
