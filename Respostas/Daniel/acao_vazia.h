#ifndef _ACAO_VAZIA_H_
#define _ACAO_VAZIA_H_

#include "jogador.h"

/**
 * @brief Executa a ação de uma célula VAZIA: nada acontece com o jogador.
 * @param dado Ponteiro genérico para a ação (não utilizado, pode ser NULL)
 * @param j Jogador que parou na célula
 * @return 0 (não há deslocamento)
 */
int executaVazia(void *dado, Jogador *j);

/**
 * @brief Imprime, sem quebra de linha: "VAZIA"
 * @param dado Ponteiro genérico para a ação (não utilizado, pode ser NULL)
 */
void imprimeVazia(void *dado);

/**
 * @brief Não há nada a liberar numa ação VAZIA. Existe apenas para ser passada
 * como callback de desalocação da célula.
 * @param dado Ponteiro genérico para a ação (não utilizado, pode ser NULL)
 */
void desalocaVazia(void *dado);

#endif 