#ifndef _ACAO_MONSTRO_H_
#define _ACAO_MONSTRO_H_

#include "jogador.h"

#define MAX_TAM_NOME_MONSTRO 21

typedef struct Monstro Monstro;

/**
 * @brief Aloca dinamicamente uma ação do tipo MONSTRO e guarda nela o nome (copiado), a força e a XP
 * @param nome Nome do monstro
 * @param forca Força do monstro
 * @param xp XP ganha por quem derrotar o monstro
 * @return Ponteiro para o monstro criado
 */
Monstro *criaMonstro(char *nome, int forca, int xp);

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, a força e a XP do monstro (a palavra MONSTRO
 * já deve ter sido lida) e cria o monstro com criaMonstro.
 * @return Ponteiro para o monstro criado
 */
Monstro *leMonstro();

/**
 * @brief Converte o dado genérico para monstro e realiza o confronto. Se a força do jogador for maior
 * ou igual à força do monstro, soma a XP do monstro à XP do jogador, soma 1 aos monstros derrotados
 * pelo jogador e retorna 0. Caso contrário, não altera o jogador e retorna RECUO_CELULA (definido em
 * celula.h) para indicar que o jogador deve recuar. O monstro nunca é removido da célula.
 * @param dado Ponteiro genérico para o monstro
 * @param j Jogador que parou na célula
 * @return 0 se o jogador vencer ou RECUO_CELULA se perder
 */
int executaMonstro(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para monstro e imprime, sem quebra de linha:
 * "MONSTRO <nome> (F:<forca> XP:<xp>)". Ex: "MONSTRO GOBLIN (F:3 XP:10)"
 * @param dado Ponteiro genérico para o monstro
 */
void imprimeMonstro(void *dado);

/**
 * @brief Converte o dado genérico para monstro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o monstro
 */
void desalocaMonstro(void *dado);

#endif // _ACAO_MONSTRO_H_
