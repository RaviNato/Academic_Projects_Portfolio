#ifndef FILA
#define FILA

#include "meustipos.h"

typedef void* ElementoDeFila;

typedef struct { 
    ElementoDeFila* vetor; // Elemento vetor [];
    U32 capacidade_inicial, capacidade, qtd_atual, inicio, final;
} Fila;

boolean nova_fila (Fila* f, U32 capacidade);
boolean guarde_na_fila (Fila* f, ElementoDeFila e);
boolean recupere_da_fila (Fila f, ElementoDeFila* e);
boolean remova_elemento_da_fila (Fila* f);
boolean fila_cheia (Fila f);
boolean fila_vazia (Fila f);
boolean free_fila (Fila* f);

#endif // FILA