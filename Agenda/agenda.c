#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

Agenda* novo_contato(){
    Agenda *novo = (Agenda*) malloc(sizeof(Agenda));
    
    return novo;
}

Agenda *inserir_inicio(Agenda *a, char *nome, long numero, char *email){
    Agenda *novo = novo_contato();
    novo->nome = nome;
    novo->numero = numero;
    novo->email = email;
    novo->prox = a;
    novo->ant = NULL;

    if(a != NULL){
        a->ant = novo;
    }

    return novo;
}

Agenda* busca(Agenda *a, long numero){
    Agenda *aux = a;

    while(aux){
        if(aux->numero == numero){
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

Agenda *remover_contato(Agenda *a, long numero){
    Agenda *aux = busca(a, numero);
    
    if(aux == NULL){
        return a;
    }
    if(aux == a){
        a = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    if(aux->prox != NULL){
        aux->prox->ant = aux->ant;
    }

    free(aux);
    return a;
}

void imprimir(Agenda *a){
    Agenda *aux = a;
    
    if(aux){
        printf("\n--- Agenda ---\n");
        do{
            printf("Nome: %s, ", aux->nome);
            printf("Numero: %d, ", aux->numero);
            printf("Email: %s.", aux->email);
            printf("\n");
            aux = aux->prox;
        }
        while (aux != NULL);
        
    }else{
        printf("\n--- Agenda Vazia ---\n");
    }
}