#include <stdio.h>
#include <stdlib.h>
#include "acao_volta.h"

struct Volta{
    int num;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo VOLTA e guarda nela a quantidade de casas
 * @param n Quantidade de casas que o jogador volta (valor positivo)
 * @return Ponteiro para a ação criada
 */
Volta *criaVolta(int n){
    Volta *v = (Volta *) malloc (sizeof(Volta));
    v->num = n;
    return v;
}

/**
 * @brief Lê da entrada padrão a quantidade de casas (a palavra VOLTA já deve ter sido lida)
 * e cria a ação com criaVolta.
 * @return Ponteiro para a ação criada
 */
Volta *leVolta(){
    int n;
    scanf(" %d\n", &n);
    Volta *v = criaVolta(n);
    return v;
}

/**
 * @brief Converte o dado genérico para volta e informa o deslocamento resultante. Não altera o
 * jogador: quem move o jogador no mapa é o módulo que conduz a partida.
 * @param dado Ponteiro genérico para a ação de volta
 * @param j Jogador que parou na célula (não é alterado)
 * @return -n, a quantidade de casas a voltar (valor negativo)
 */
int executaVolta(void *dado, Jogador *j){
    Volta *v = (Volta *) dado;
    (void)j;
    return -v->num;
}

/**
 * @brief Converte o dado genérico para volta e imprime, sem quebra de linha:
 * "VOLTA <n>". Ex: "VOLTA 3"
 * @param dado Ponteiro genérico para a ação de volta
 */
void imprimeVolta(void *dado){
    Volta *v = (Volta *) dado;
    printf("VOLTA %d", v->num);
}

/**
 * @brief Converte o dado genérico para volta e libera a memória alocada para ele
 * @param dado Ponteiro genérico para a ação de volta
 */
void desalocaVolta(void *dado){
    Volta *v = (Volta *) dado;
    free(v);
}