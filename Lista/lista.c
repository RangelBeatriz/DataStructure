#include "lista.h"
#include "pilha.h"
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


Lista inserir(Lista l, int n)
{
    if(l == NULL)
    {
        l=(Lista) malloc(sizeof(Lista));
        l -> info = n;
        l -> prox = NULL;
        return l;
    }

    else
    {
        l->prox = inserir(l->prox, n);
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
        if(l->prox == NULL)
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
