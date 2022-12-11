struct agenda{
    char *nome;
    long numero;
    char *email;
    struct agenda *ant;
    struct agenda *prox;
};

typedef struct agenda Agenda;

Agenda* novo_contato();

Agenda *inserir_inicio(Agenda *a, char *nome, long numero, char *email);

Agenda* busca(Agenda *a, long numero);

Agenda *remover_contato(Agenda *a, long numero);

void imprimir(Agenda *a);