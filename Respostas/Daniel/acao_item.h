#ifndef _ACAO_ITEM_H_
#define _ACAO_ITEM_H_

#include "jogador.h"

#define MAX_TAM_NOME_ITEM 21

typedef struct Item Item;

/**
 * @brief Aloca dinamicamente uma ação do tipo ITEM e guarda nela o nome (copiado), o preço e o bônus
 * @param nome Nome do item
 * @param preco Preço do item, em ouro
 * @param bonus Bônus de força concedido a quem comprar o item
 * @return Ponteiro para o item criado
 */
Item *criaItem(char *nome, int preco, int bonus);

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, o preço e o bônus do item (a palavra ITEM
 * já deve ter sido lida) e cria o item com criaItem.
 * @return Ponteiro para o item criado
 */
Item *leItem();

/**
 * @brief Converte o dado genérico para item e tenta a compra. Se o jogador tiver ouro suficiente
 * (ouro >= preço), desconta o preço do ouro do jogador e soma o bônus à força dele. Caso contrário,
 * não altera o jogador. A compra é automática (não há opção de recusar) e o item nunca é removido
 * da célula.
 * @param dado Ponteiro genérico para o item
 * @param j Jogador que parou na célula
 * @return 0 (não há deslocamento, haja compra ou não)
 */
int executaItem(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para item e imprime, sem quebra de linha:
 * "ITEM <nome> (P:<preco> F:+<bonus>)". Ex: "ITEM ESPADA (P:10 F:+2)"
 * @param dado Ponteiro genérico para o item
 */
void imprimeItem(void *dado);

/**
 * @brief Converte o dado genérico para item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o item
 */
void desalocaItem(void *dado);

#endif 