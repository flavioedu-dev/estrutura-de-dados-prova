#include <stdio.h>
#include "agenda.h"

int main(){

    Agenda *a = NULL;

    a = inserir_inicio(a, "Flavio", 40028922, "gmail.com");
    a = inserir_inicio(a, "Flavio", 40028923, "gmail.com");
    a = inserir_inicio(a, "Flavio", 40028924, "gmail.com");
    a = inserir_inicio(a, "Flavio", 40028925, "gmail.com");
    imprimir(a);

    remover_contato(a, 40028923);
    imprimir(a);

    return 0;
}