#include <stdio.h>
#include <stdlib.h>
#include "acao_ouro.h"

struct Ouro{
    int quantidade;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade de ouro
 * @param quantidade Quantidade de ouro coletada por quem parar na célula
 * @return Ponteiro para a ação criada
 */
Ouro *criaOuro(int quantidade){
    Ouro *o = (Ouro *) malloc (sizeof(Ouro));
    if (o == NULL){
        return NULL;
    }
    o->quantidade = quantidade;
    return o;
}

/**
 * @brief Lê da entrada padrão a quantidade de ouro (a palavra OURO já deve ter sido lida)
 * e cria a ação com criaOuro.
 * @return Ponteiro para a ação criada
 */
Ouro *leOuro(){
    int quantidade;
    scanf(" %d", &quantidade);
    Ouro *o = criaOuro(quantidade);
    return o;
}

/**
 * @brief Converte o dado genérico para ouro e soma a quantidade ao ouro do jogador.
 * Não altera mais nada no jogador e não remove o ouro da célula, que é permanente.
 * @param dado Ponteiro genérico para a ação de ouro
 * @param j Jogador que parou na célula
 * @return 0 (não há deslocamento)
 */
int executaOuro(void *dado, Jogador *j){
    Ouro *o = (Ouro *) dado;
    adicionaOuroJogador(j, o->quantidade);
    return 0;
}

/**
 * @brief Converte o dado genérico para ouro e imprime, sem quebra de linha:
 * "OURO <quantidade>". Ex: "OURO 10"
 * @param dado Ponteiro genérico para a ação de ouro
 */
void imprimeOuro(void *dado){
    Ouro *o = (Ouro *) dado;
    printf("OURO %d", o->quantidade);
}

/**
 * @brief Converte o dado genérico para ouro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para a ação de ouro
 */
void desalocaOuro(void *dado){
    Ouro *o = (Ouro *) dado;
    free(o);
}