struct no{
    int num;
    struct no *prox;
};
typedef struct no No;

struct fila{
    No *ini;
    No *fim;
};
typedef struct fila Fila;

Fila *iniciar();

No *inserir_fim(No *f, int valor);

void fim(Fila *fila, int valor);

void imprimir(Fila *f);

int percorrer(Fila *f);

int decBin(Fila *f, int valor);