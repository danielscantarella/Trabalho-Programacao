#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "acao_item.h"

struct Item{
    char nome[MAX_TAM_NOME_ITEM];
    int preco, bonus; 
};

/**
 * @brief Aloca dinamicamente uma ação do tipo ITEM e guarda nela o nome (copiado), o preço e o bônus
 * @param nome Nome do item
 * @param preco Preço do item, em ouro
 * @param bonus Bônus de força concedido a quem comprar o item
 * @return Ponteiro para o item criado
 */
Item *criaItem(char *nome, int preco, int bonus){
    Item *i = (Item *) malloc (sizeof(Item));
    strcpy(i->nome, nome);
    i->bonus = bonus;
    i->preco = preco;
    return i;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, o nome, o preço e o bônus do item (a palavra ITEM
 * já deve ter sido lida) e cria o item com criaItem.
 * @return Ponteiro para o item criado
 */
Item *leItem(){
    char nome[MAX_TAM_NOME_ITEM];
    int preco, bonus; 
    scanf(" %s %d %d\n", nome, &preco, &bonus);
    Item *i = criaItem (nome, preco, bonus);
    return i;
}

/**
 * @brief Converte o dado genérico para item e tenta a compra. Se o jogador tiver ouro suficiente
 * (ouro >= preço), desconta o preço do ouro do jogador e soma o bônus à força dele. Caso contrário,
 * não altera o jogador. A compra é automática (não há opção de recusar) e o item nunca é removido
 * da célula.
 * @param dado Ponteiro genérico para o item
 * @param j Jogador que parou na célula
 * @return 0 (não há deslocamento, haja compra ou não)
 */
int executaItem(void *dado, Jogador *j){
    Item *i = (Item *) dado;
    if (obtemOuroJogador(j) >= i->preco){
        adicionaOuroJogador(j, -i->preco);
        adicionaForcaJogador(j, i->bonus);
    }
    return 0;
}

/**
 * @brief Converte o dado genérico para item e imprime, sem quebra de linha:
 * "ITEM <nome> (P:<preco> F:+<bonus>)". Ex: "ITEM ESPADA (P:10 F:+2)"
 * @param dado Ponteiro genérico para o item
 */
void imprimeItem(void *dado){
    Item *i = (Item *) dado;
    printf("ITEM %s (P:%d F:+%d)", i->nome, i->preco, i->bonus);
}

/**
 * @brief Converte o dado genérico para item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o item
 */
void desalocaItem(void *dado){
    Item *i = (Item *) dado;
    free(i);
}