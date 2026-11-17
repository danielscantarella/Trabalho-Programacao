#include <stdlib.h>
#include <stdio.h>
#include "acao_avanca.h"

struct Avanca{
    int num;  
};

/**
 * @brief Aloca dinamicamente uma ação do tipo AVANCA e guarda nela a quantidade de casas
 * @param n Quantidade de casas que o jogador avança
 * @return Ponteiro para a ação criada
 */
Avanca *criaAvanca(int n){
    Avanca *a = (Avanca *) malloc (sizeof(Avanca));
    a->num = n;
    return a;
}

/**
 * @brief Lê da entrada padrão a quantidade de casas (a palavra AVANCA já deve ter sido lida)
 * e cria a ação com criaAvanca.
 * @return Ponteiro para a ação criada
 */
Avanca *leAvanca(){
    int n;
    scanf(" %d", &n);
    Avanca *a = criaAvanca(n);
    return a;
}

/**
 * @brief Converte o dado genérico para avanca e informa o deslocamento resultante. Não altera o
 * jogador: quem move o jogador no mapa é o módulo que conduz a partida.
 * @param dado Ponteiro genérico para a ação de avanca
 * @param j Jogador que parou na célula (não é alterado)
 * @return +n, a quantidade de casas a avançar
 */
int executaAvanca(void *dado, Jogador *j){
    (void)j;
    Avanca *a = (Avanca *) dado;
    return a->num;
}

/**
 * @brief Converte o dado genérico para avanca e imprime, sem quebra de linha:
 * "AVANCA <n>". Ex: "AVANCA 2"
 * @param dado Ponteiro genérico para a ação de avanca
 */
void imprimeAvanca(void *dado){
    Avanca *a = (Avanca *) dado;
    printf("AVANCA %d", a->num);
}

/**
 * @brief Converte o dado genérico para avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para a ação de avanca
 */
void desalocaAvanca(void *dado){
    Avanca *a = (Avanca *) dado;
    free(a);
}