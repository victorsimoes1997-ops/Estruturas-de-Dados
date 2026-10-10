#pragma once

struct NoPilha
{
    int dado;
    NoPilha* proximo;
};

void empilhar(NoPilha*& topo, int valor);
void desempilhar(NoPilha*& topo);
int olharTopo(NoPilha* topo);
bool estaVazia(NoPilha* topo);
void destruirPilha(NoPilha*& topo);
void imprimirPilha(NoPilha* topo);