#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partida.h"

/**
 * Estado de uma partida do Jogo da Void: guarda o mapa, os jogadores cadastrados (na ordem de
 * cadastro), de quem é a vez, o vencedor e os contadores usados no relatório.
 */
struct Partida{
    Mapa *mapa;
    Jogador **jogadores;
    int qtdJogadores;
};

/**
 * @brief Aloca dinamicamente uma partida sem jogadores, que passa a ser dona do mapa informado.
 * A partida começa em andamento, sem vencedor, com todos os contadores zerados e a vez do
 * primeiro jogador cadastrado.
 * @param mapa Mapa já lido (a partida assume a responsabilidade de liberá-lo)
 * @return Ponteiro para a partida criada
 */
Partida *criaPartida(Mapa *mapa){
    Partida *p = (Partida *) malloc (sizeof(Partida));
    p->jogadores = NULL;
    p->mapa = mapa;
    p->qtdJogadores = 0;
    return p;
}

/**
 * @brief Cadastra um jogador no final da lista de jogadores (ordem de cadastro). Se já existir
 * um jogador com o mesmo nome, o cadastro é ignorado e o jogador recebido é desalocado. Caso
 * contrário, a partida passa a ser dona do jogador. O jogador começa no Início (casa 0).
 * @param p Partida
 * @param j Jogador recém-criado (por exemplo, com leJogador)
 * @return 1 se o jogador foi cadastrado, 0 se foi ignorado por nome repetido
 */
int cadastraJogadorPartida(Partida *p, Jogador *j){
    for (int i=0; i<p->qtdJogadores; i++){
        if (comparaNomeJogador(j, obtemNomeJogador(p->jogadores[i]))){
            desalocaJogador(j);
            return 0;
        }
    }
    p->jogadores = (Jogador **) realloc (p->jogadores, (p->qtdJogadores+1) *  sizeof(Jogador*));
    p->jogadores[p->qtdJogadores] = j;
    p->qtdJogadores++;
    return 1;
}

/**
 * @brief Desaloca todos os jogadores cadastrados, o vetor de jogadores, o mapa e a própria partida
 * @param p Partida
 */
void desalocaPartida(Partida *p){
    desalocaMapa(p->mapa);
    for (int i=0; i<p->qtdJogadores; i++){
        desalocaJogador(p->jogadores[i]);
    }
    free(p->jogadores);
    free(p);
}