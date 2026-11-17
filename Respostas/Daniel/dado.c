#include "dado.h"

#define FACES_DADO 4

// Gerador congruente linear com semente fixa: a sequência é sempre a mesma
static unsigned int semente = 2026;

int RolaDado() {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % FACES_DADO) + 1;
}