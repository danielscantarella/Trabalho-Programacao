#ifndef _ACAO_AVANCA_H_
#define _ACAO_AVANCA_H_

#include "jogador.h"

typedef struct Avanca Avanca;

/**
 * @brief Aloca dinamicamente uma ação do tipo AVANCA e guarda nela a quantidade de casas
 * @param n Quantidade de casas que o jogador avança
 * @return Ponteiro para a ação criada
 */
Avanca *criaAvanca(int n);

/**
 * @brief Lê da entrada padrão a quantidade de casas (a palavra AVANCA já deve ter sido lida)
 * e cria a ação com criaAvanca.
 * @return Ponteiro para a ação criada
 */
Avanca *leAvanca();

/**
 * @brief Converte o dado genérico para avanca e informa o deslocamento resultante. Não altera o
 * jogador: quem move o jogador no mapa é o módulo que conduz a partida.
 * @param dado Ponteiro genérico para a ação de avanca
 * @param j Jogador que parou na célula (não é alterado)
 * @return +n, a quantidade de casas a avançar
 */
int executaAvanca(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para avanca e imprime, sem quebra de linha:
 * "AVANCA <n>". Ex: "AVANCA 2"
 * @param dado Ponteiro genérico para a ação de avanca
 */
void imprimeAvanca(void *dado);

/**
 * @brief Converte o dado genérico para avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para a ação de avanca
 */
void desalocaAvanca(void *dado);

#endif // _ACAO_AVANCA_H_