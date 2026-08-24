#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

Produto *criar_vetor(int capacidade)
{
    return malloc(capacidade * sizeof(Produto));
}

Produto *aumentar_vetor(Produto *pro, int quantidade)
{
    return realloc(pro, (quantidade+1) * sizeof(Produto));
}

void cadastrar_produto(Produto *pro, int total, int id)
{
    pro[total].id = id;

    printf("Nome do produto: ");
    scanf(" %49[^\n]", pro[total].nome);

    printf("Preco do produto: ");
    scanf(" %f", &pro[total].preco);

    printf("Quantidade do produto: ");
    scanf(" %d", &pro[total].quantidade);
}

int buscar_produto( Produto *pro, int id, int total)
{
    if (total <= 0) {
        return -1;
    }
    int i=total-1;
    if(pro[i].id == id){
    return i;
   }
    return buscar_produto(pro, id, total-1);
}

void ordenar_por_preco(Produto *pro, int total){
    for (int i = 0; i < total - 1; i++) {

        for (int j = i + 1; j < total; j++) {

            if (pro[i].preco > pro[j].preco) {

                Produto temp = pro[i];

                pro[i] = pro[j];

                pro[j] = temp;
            }
        }
    }
}

float valor_total_estoque(Produto *pro, int total)
{
    float soma_estoque = 0;

    for (int i = 0; i < total; i++) {

        soma_estoque= soma_estoque + (pro[i].preco * pro[i].quantidade);
    }

    return soma_estoque;
}
void listar_produtos(Produto *pro, int total, int posicao)
{
    if (posicao >= total)
        return;

    printf("ID: %d\n", pro[posicao].id);
    printf("Nome: %s\n", pro[posicao].nome);
    printf("Preco: %.2f\n\n", pro[posicao].preco);

    listar_produtos(pro, total, posicao + 1);
}