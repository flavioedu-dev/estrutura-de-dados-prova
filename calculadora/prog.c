#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

void esvaziar(Calc *c){
    No *aux;
    aux = c->prim;

    while(aux != NULL){
        c->prim = aux->prox;
        free(aux);
        aux = c->prim;
    }
}

void inverter(Calc *c, Calc *p){
    No *aux = NULL;
    float a;
    for(aux = c->prim; aux != NULL; aux = aux->prox){
        if(aux->info == '+' || aux->info == '-' || aux->info == '*' || aux->info == '/'){
            operador(p,aux->info);
        }else{
            operando(p,aux->info);
        }

    }
    esvaziar(c);
}


float calcul(float n1, float n2, char op){
    float resultado;
    if(op == '+'){
        resultado = n1+n2;
    }else if(op == '-'){
        resultado = n1-n2;
    }else if(op == '*'){
        resultado = n1*n2;
    }else if(op == '/'){
        resultado = n1/n2;
    }else{
        return 0;
    }
    return resultado;
}

void resolucao(Calc *p){
     No *aux = NULL;
     Calc *c = cria_calc();
     Calc *e = cria_calc();
     int v = 0;
    float a,b,d, resultado;
    for(aux = p->prim; aux != NULL; aux = aux->prox){
        if(aux->info == '+' || aux->info == '-' || aux->info == '*' || aux->info == '/'){
            a = pop(p);
            b = pop(p);
            resultado = calcul(a,b,aux->info);
            d = pop(p);
            inverter(p,c);
            operando(c,resultado);
            esvaziar(p);
            inverter(c,p);
            esvaziar(c);
            aux = p->prim;
        }
    }
   
}

int main() {
    Calc *c = cria_calc();
    Calc *p = cria_calc();
    operando(c,1);
    operando(c,2);
    operador(c,'-');
    operando(c,4);
    operando(c,5);
    operador(c,'+');
    operador(c,'*');
    inverter(c,p); //Não mexa nesse, só para mudar as variáveis
    esvaziar(c);    //Não mexa nesse, só para mudar as variáveis
    resolucao(p);   //Não mexa nesse, só para mudar as variáveis
    inverter(p,c);  //Não mexa nesse, só para mudar as variáveis
    resolucao(c);   //Não mexa nesse, só para mudar as variáveis
    imprimir(c);    //Não mexa nesse, só para mudar as variáveis

    return 0;
    
}