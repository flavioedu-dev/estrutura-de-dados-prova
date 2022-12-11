#include <stdio.h>
#include "agenda.h"


int main(){

    Agenda *a = NULL;
 
    a = inserir_inicio(a, "Pedro", 40028923, "teste1gmail.com");
    a = inserir_inicio(a, "Tiago", 50028924, "teste2gmail.com");
    a = inserir_inicio(a, "Joao", 60028925, "teste3gmail.com");
    imprimir(a);

    a = inserir_inicio(a, "Lucas", 70028926, "teste5gmail.com");
    a = inserir_inicio(a, "Jonas", 80028927, "teste6gmail.com");
    a = inserir_inicio(a, "Alex", 90028928, "teste7gmail.com");
    imprimir(a);

    a = remover_contato(a, 40028923);
    a = remover_contato(a, 40028927);
    imprimir(a);
    
    return 0;
}