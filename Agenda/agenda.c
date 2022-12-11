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

    if(a == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        a = novo;
    }else{
        novo->prox = a;
        novo->ant = NULL;
        a = novo;
    }

    return novo;
}

Agenda remover_contato(Agenda *a, long numero){
    Agenda *aux = a;

    do{
        if(aux->numero == numero){
            break;
        }
        aux = aux->prox;
    }while(aux);

    printf("teste");
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);

}

void imprimir(Agenda *a){
    Agenda *aux = a;
    
    printf("--- Agenda ---\n");
    do{
        printf("Nome: %s, ", aux->nome);
        printf("Numero: %d, ", aux->numero);
        printf("Email: %s.", aux->email);
        printf("\n");
        aux = aux->prox;
    }
    while (aux != NULL);
}