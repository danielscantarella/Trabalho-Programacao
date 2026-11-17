#ifndef _ACAO_OURO_H_
#define _ACAO_OURO_H_

#include "jogador.h"

typedef struct Ouro Ouro;

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade de ouro
 * @param quantidade Quantidade de ouro coletada por quem parar na célula
 * @return Ponteiro para a ação criada
 */
Ouro *criaOuro(int quantidade);

/**
 * @brief Lê da entrada padrão a quantidade de ouro (a palavra OURO já deve ter sido lida)
 * e cria a ação com criaOuro.
 * @return Ponteiro para a ação criada
 */
Ouro *leOuro();

/**
 * @brief Converte o dado genérico para ouro e soma a quantidade ao ouro do jogador.
 * Não altera mais nada no jogador e não remove o ouro da célula, que é permanente.
 * @param dado Ponteiro genérico para a ação de ouro
 * @param j Jogador que parou na célula
 * @return 0 (não há deslocamento)
 */
int executaOuro(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para ouro e imprime, sem quebra de linha:
 * "OURO <quantidade>". Ex: "OURO 10"
 * @param dado Ponteiro genérico para a ação de ouro
 */
void imprimeOuro(void *dado);

/**
 * @brief Converte o dado genérico para ouro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para a ação de ouro
 */
void desalocaOuro(void *dado);

#endif // _ACAO_OURO_H_