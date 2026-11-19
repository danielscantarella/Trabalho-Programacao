#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "acao_avanca.h"
#include "acao_item.h"
#include "acao_monstro.h"
#include "acao_ouro.h"
#include "acao_vazia.h"
#include "acao_volta.h"

/**
 * @brief Lê da entrada padrão o cadastro do mapa, desde a linha "INICIO MAPA" até a linha
 * "FIM MAPA". Cada linha entre elas descreve uma célula (VAZIA, OURO, MONSTRO, ITEM, AVANCA
 * ou VOLTA), na ordem em que aparecem na trilha. Para cada uma, cria a ação do tipo
 * correspondente e a insere no mapa com os callbacks do seu tipo. A quantidade de células
 * não é informada e é inferida durante a leitura.
 * @return Ponteiro para o mapa criado, com todas as células lidas
 */
Mapa *leMapa(){
    char palavra[20];
    Mapa *m = criaMapa();

    scanf(" %[^\n]\n", palavra);   // lê "INICIO MAPA"

    while (1){
        scanf(" %s", palavra);

        if (strcmp(palavra, "FIM") == 0){
            scanf(" %s", palavra);   // lê "MAPA" do "FIM MAPA"
            break;
        }

        if (strcmp(palavra, "VAZIA") == 0){
            void *vazia = NULL;
            insereCelulaMapa(m, vazia, executaVazia, imprimeVazia, desalocaVazia);
        }
        
        if (strcmp(palavra, "OURO") == 0){
            Ouro *ouro = leOuro();
            insereCelulaMapa(m, ouro, executaOuro, imprimeOuro, desalocaOuro);
        }

        if (strcmp(palavra, "MONSTRO") == 0){
            Monstro *monstro = leMonstro();
            insereCelulaMapa(m, monstro, executaMonstro, imprimeMonstro, desalocaMonstro);
        }

        if (strcmp(palavra, "ITEM") == 0){
            Item *item = leItem();
            insereCelulaMapa(m, item, executaItem, imprimeItem, desalocaItem);
        }

        if (strcmp(palavra, "AVANCA") == 0){
            Avanca *avanca = leAvanca();
            insereCelulaMapa(m, avanca, executaAvanca, imprimeAvanca, desalocaAvanca);
        }

        if (strcmp(palavra, "VOLTA") == 0){
            Volta *volta = leVolta();
            insereCelulaMapa(m, volta, executaVolta, imprimeVolta, desalocaVolta);
        }

    }
    
    return m;
}

