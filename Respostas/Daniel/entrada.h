#ifndef _ENTRADA_H_
#define _ENTRADA_H_

#include "mapa.h"

/**
 * @brief Lê da entrada padrão o cadastro do mapa, desde a linha "INICIO MAPA" até a linha
 * "FIM MAPA". Cada linha entre elas descreve uma célula (VAZIA, OURO, MONSTRO, ITEM, AVANCA
 * ou VOLTA), na ordem em que aparecem na trilha. Para cada uma, cria a ação do tipo
 * correspondente e a insere no mapa com os callbacks do seu tipo. A quantidade de células
 * não é informada e é inferida durante a leitura.
 * @return Ponteiro para o mapa criado, com todas as células lidas
 */
Mapa *leMapa();

#endif