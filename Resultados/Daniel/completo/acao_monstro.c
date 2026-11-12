#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "acao_monstro.h"
#include "celula.h"

struct Monstro{
    char nome[MAX_TAM_NOME_MONSTRO];
    int xp;
    int forca;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo MONSTRO e guarda nela o nome (copiado), a força e a XP
 * @param nome Nome do monstro
 * @param forca Força do monstro
 * @param xp XP ganha por quem derrotar o monstro
 * @return Ponteiro para o monstro criado
 */
Monstro *criaMonstro(char *nome, int forca, int xp){
    Monstro *m = (Monstro *) malloc (sizeof(Monstro));
    m->forca = forca;
    m->xp = xp;
    strcpy (m->nome, nome);
    return m;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, a força e a XP do monstro (a palavra MONSTRO
 * já deve ter sido lida) e cria o monstro com criaMonstro.
 * @return Ponteiro para o monstro criado
 */
Monstro *leMonstro(){
    char nome[MAX_TAM_NOME_MONSTRO];
    int xp;
    int forca;

    scanf("%s %d %d\n", nome, &forca, &xp);
    Monstro *m = criaMonstro(nome, forca, xp);
    return m;
}

/**
 * @brief Converte o dado genérico para monstro e realiza o confronto. Se a força do jogador for maior
 * ou igual à força do monstro, soma a XP do monstro à XP do jogador, soma 1 aos monstros derrotados
 * pelo jogador e retorna 0. Caso contrário, não altera o jogador e retorna RECUO_CELULA (definido em
 * celula.h) para indicar que o jogador deve recuar. O monstro nunca é removido da célula.
 * @param dado Ponteiro genérico para o monstro
 * @param j Jogador que parou na célula
 * @return 0 se o jogador vencer ou RECUO_CELULA se perder
 */
int executaMonstro(void *dado, Jogador *j){
    Monstro *m = (Monstro *) dado;

    if (obtemForcaJogador(j) >= m->forca){
        adicionaXPJogador(j, m->xp);
        incrementaMonstrosDerrotadosJogador(j);
        return 0;
    }

    return RECUO_CELULA;
}

/**
 * @brief Converte o dado genérico para monstro e imprime, sem quebra de linha:
 * "MONSTRO <nome> (F:<forca> XP:<xp>)". Ex: "MONSTRO GOBLIN (F:3 XP:10)"
 * @param dado Ponteiro genérico para o monstro
 */
void imprimeMonstro(void *dado){
    Monstro *m = (Monstro *) dado;

    printf("MONSTRO %s (F:%d XP:%d)", m->nome, m->forca, m->xp);
}

/**
 * @brief Converte o dado genérico para monstro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o monstro
 */
void desalocaMonstro(void *dado){
    Monstro *m = (Monstro *) dado;
    free(m);
}