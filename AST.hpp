#pragma once

// Para saber se a caixinha guarda um número ou um símbolo matemático
enum TipoAST { OPERANDO, OPERADOR };

struct NoAST
{
    TipoAST tipo;
    
    int valor;        // Preenchido APENAS se tipo == OPERANDO
    char operacao;    // Preenchido APENAS se tipo == OPERADOR ('+', '-', '*', '/')
    
    NoAST* esquerda;
    NoAST* direita;
};

NoAST* criarNoOperando(int numero);
NoAST* criarNoOperador(char op, NoAST* esq, NoAST* dir);
int avaliarAST(NoAST* raiz);
void imprimirEquacao(NoAST* raiz);
void destruirAST(NoAST*& raiz);