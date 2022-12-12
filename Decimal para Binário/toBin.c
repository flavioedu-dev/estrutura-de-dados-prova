#include <stdio.h>
#include <stdlib.h>
#include "toBin.h"

Fila *iniciar(){
    Fila *fila = (Fila*) malloc (sizeof(Fila));

    fila->ini = NULL;
    fila->fim = NULL;

    return fila;
}

No *inserir_fim(No *f, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->num = valor;
    novo->prox = NULL;

    if(f != NULL){
        f->prox = novo;
    }

    return novo;
}

void fim(Fila *fila, int valor){
    fila->fim = inserir_fim(fila->fim, valor);

    if(fila->ini == NULL){
        fila->ini = fila->fim;
    }
}

void imprimir(Fila *f){
    No *aux = f->ini;

    while(aux){
        printf("aux: %d\n", aux->num);
        aux = aux->prox;
    }
}

int percorrer(Fila *f){
    No *aux = f->ini;

    int mult = 1;
    int res = 0;

    while(aux){
        res = res + (aux->num*mult); 
        mult *= 10;
        aux = aux->prox;
    }
    return res;
}


int decBin(Fila *f, int valor){
    if(valor>1){
        while(valor >= 1){
            int res = valor % 2;
            fim(f, res);
            valor = valor / 2;
        }

        return percorrer(f);
    }
}