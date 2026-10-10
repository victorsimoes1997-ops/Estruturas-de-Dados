#pragma once

struct NoFila
{
    int dado;
    NoFila* proximo;
};

void enfileirar(NoFila*& cabeca, int valor);
void desenfileirar(NoFila*& cabeca);
NoFila* olharCabeca(NoFila* cabeca);
void destruirFila(NoFila*& cabeca);
void imprimirFila(NoFila* cabeca);