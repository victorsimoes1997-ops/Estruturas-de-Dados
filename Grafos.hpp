#pragma once

struct  Grafo
{
    bool eh_ponderado;
    int nro_vert;
    int Gmax;
    int* arestas;
    float* pesos;
    int* grau;
};

Grafo* criarGrafo(int nro_vert, int Gmax, bool eh_ponderado);
void destruirGrafo(Grafo* gr);
int inserirArestas(Grafo* gr, int origem, int dest, int digrafo, int peso);
int removerArestas(Grafo* gr, int origem, int dest, int digrafo);