#include "produto.h" 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Produto *pro;

    int capacidade;
    int total = 0;
    int proximoId = 1;
    int opcao;
    int posicao=0;
    int id;

    printf("qual a quantidade inicial de produtos que voce deseja em seu estoque: ");
    scanf("%d", &capacidade);

    pro= criar_vetor(capacidade);
    if (pro == NULL) {
        printf("erro ao criar vetor");
        return 1;
    } else{
    do {
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Remover produto por ID\n");
        printf("5 - Ordenar produtos por preco\n");
        printf("6 - ver valor total do estoque\n");
        printf("0 - fechar programa\n");
        scanf(" %d", &opcao);
        
         if (opcao == 1) {

            if (capacidade == total) {
                Produto *test_pro = aumentar_vetor(pro, capacidade);

                if (test_pro == NULL) {
                    printf("Erro ao aumentar o vetor de produtos.\n");
                } else {
                    capacidade = capacidade +1;
                    pro = test_pro;
                }
            }
            cadastrar_produto(pro, total, proximoId);
                 total++;
                 proximoId++;
        } else if (opcao == 2) {
            listar_produtos(pro, total, posicao);
        } else if (opcao == 3) {
            printf("Digite o ID do produto que deseja buscar: ");
            scanf(" %d", &id);
            if(id>capacidade||id<=0){
                printf("id invalido\n");
            } else{
                int encontrar = buscar_produto(pro, id, total);
                if(encontrar == -1){
                    printf("id invalido");
                } else {
                printf("Nome: %s\n", pro[encontrar].nome);
                printf("Preco: %.2f\n", pro[encontrar].preco);
                printf("Quantidade: %d\n", pro[encontrar].quantidade);
                }
                }
        } else if (opcao == 4) {
                printf("Digite o ID do produto que deseja remover: ");
                scanf(" %d", &id);
                if(id>capacidade||id<=0){
                printf("id invalido");
            } else{
                int encontrar = buscar_produto(pro, id, total);
                if(encontrar == -1){
                    printf("id invalido\n");
                } else {
                for ( int i = encontrar; i < total-1; i++){
                pro[i] = pro[i + 1];
                }
                if (total == 1){
                pro = NULL;
                total = 0;
                } else{
                 Produto *teste = realloc(pro, (total - 1) * sizeof(Produto));
                    if (teste == NULL){
                     printf("Erro ao reduzir o vetor de produtos.\n");
                     } else {
                     pro = teste;
                     total--;
                    }
                printf("Produto removido com sucesso.\n");
                } 
            }
        }
    }
            if (opcao == 5) {
            ordenar_por_preco(pro, total);
                 for (int i = 0; i < total; i++) {
                printf("ID: %d\n", pro[i].id);
                printf("Nome: %s\n", pro[i].nome);
                printf("Preco: %.2f\n\n", pro[i].preco);
                 }
            }
            if(opcao == 6){ 
            float estoquetotal= valor_total_estoque(pro, total);
            printf("valor total de estoque e: %.2f\n", estoquetotal);
            }
        } while (opcao != 0); 
    }          
return 0;
}