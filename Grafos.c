/*Beatriz Rangel
Ruan Almeida*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct lista
{
    int destino;
    float custo;
    struct lista *prox;
} Lista;


Lista *inserirLista(Lista *l, int d, float c)
{
    Lista *no = (Lista *) malloc(sizeof(Lista));

    no->destino = d;
    no->custo = c;
    no->prox = l;

    return no;
}


void inserir(Lista **g, int origem, int destino, float custo)
{
    g[origem] = inserirLista(g[origem], destino, custo);
}


int removerLista(Lista *l, int d)
{
    if(l != NULL)
    {
        if(l->destino == d)
        {
            Lista *r = l;

            l=l->prox;
            free(r);

            return l;
        }

        else
            return removerLista(l->prox, d);
    }
}

void remover(Lista **g, int origem, int destino)
{
    g[origem] = removerLista(g[origem], destino);
}


int calcularGrauSaida(Lista *l, int origem)
{
    int cont = 0;

    if(l != NULL)
    {
        cont = 1+calcularGrauSaida(l->prox, origem);
    }

    return cont;
}

int calcularGrauEntrada(Lista *l, int destino, int n)
{
    int e;

    if(l != NULL)
    {
        if(l->destino == destino)
            e = 1+calcularGrauEntrada(l->prox, destino, n);

        else
            e = calcularGrauEntrada(l->prox, destino, n);
    }

    return e;
}

void calcularGrau(Lista **g, int vertice, int n)
{
    int i, r, e=0, s = calcularGrauSaida(g[vertice], vertice), grau;

    for(i=1; i<=n; i++)
    {
        r = calcularGrauEntrada(g[i], vertice, n);
        e = e + r;
    }

    grau = s + e;

    printf("\nO grau do vertice %d e: %d", vertice, grau);

}


void imprimirLista(Lista *l)
{
    Lista *p = l;

    while(p != NULL)
    {
        printf(" %d - %.2f |", p->destino, p->custo);
        p = p->prox;
    }
}

void imprimir(Lista **g, int n)
{
    int i;

    for(i=0; i<= n; i++)
    {
        printf("\n%d: ", i);
        imprimirLista(g[i]);
    }
}


int verificarEsparso(Lista **g, int n)
{
    int i, p, s, v=0;

    p = n*(n-1)*0.30;

    for(i=1; i<=n; i++)
    {
        s = calcularGrauSaida(g[i], i);
        v = v + s;
    }

    if(p>v)
        return 1;

    else
        return 0;

}


void destruirLista(Lista *g)
{

    if(g != NULL)
    {
        while(g != NULL)
        {
            Lista *aux = g;
            g = g->prox;
            free(aux);
        }
    }
}

void destruir(Lista **g, int n)
{

    int i;

    for(i=0; i<n; i++)
        destruirLista(g[i]);
    printf("Grafo destruido.");
    free(g);
}


int menu()
{
    int opc;

    printf("\nMenu de opcoes:\n");
    printf("(1) Inserir aresta.\n");
    printf("(2) Remover uma aresta.\n");
    printf("(3) Imprimir.\n");
    printf("(4) Grau do vertice.\n");
    printf("(5) Verificar se e esparso.\n");
    printf("(6) Sair.\n\n");
    scanf("%d", &opc);
    fflush(stdin);

    return opc;
}


int main(void)
{
    Lista **g;
    int n, o, d, c, i=0, opcao=0, v, verif;

    scanf("%d", &n);
    g = (Lista **) malloc((n+1)*sizeof(Lista*));

    for(i=0; i<= n; i++)
        g[i] = NULL;


    while(opcao!=7)
    {
        system("cls");
        opcao = menu();
        switch(opcao)
        {

        case 1:
            printf("Origem: ");
            scanf("%d", &o);
            printf("Destino: ");
            scanf("%d", &d);
            printf("Custo: ");
            scanf("%d", &c);
            inserir(g,o,d,c);
            break;

        case 2:
            printf("Origem: ");
            scanf("%d", &o);
            printf("Destino: ");
            scanf("%d", &d);
            remover(g,o,d);
            break;

        case 3:
            imprimir(g,n);
            break;

        case 4:
            printf("Digite o numero do vertice: ");
            scanf("%d", &v);
            calcularGrau(g,v,n);
            break;

        case 5:
            verif = verificarEsparso(g, n);
            if(verif == 1)
                printf("\nEle e esparso");
            else
                printf("\nNao e esparso");
            break;

        case 6:
            destruir(g,n);
            opcao = 7;
            break;
        }

        printf("\n");
        system("pause");
    }

    return 0;
}
