#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto *criar_vetor(int capacidade);

Produto *aumentar_vetor(Produto *pro, int quantidade);

void cadastrar_produto(Produto *pro, int posicao, int id);

void listar_produtos(Produto *pro, int total, int posicao);

int buscar_produto(Produto *pro, int id, int total);

void ordenar_por_preco(Produto *pro, int total);

float valor_total_estoque(Produto *pro, int total);

#endif