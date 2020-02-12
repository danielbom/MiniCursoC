#include <stdio.h>
#include "PilhaInt.h"

int teste_basico_PilhaInt() {
  PilhaInt* pilha = PilhaInt_criar();

  PilhaInt_adicionar(pilha, 10);
  PilhaInt_adicionar(pilha, 20);
  PilhaInt_adicionar(pilha, 30);
  PilhaInt_adicionar(pilha, 40);

  // PilhaInt_imprimir(pilha);
  // printf("\n");

  printf("Removendo um elemento da pilha: %d\n", PilhaInt_remover(pilha));
  printf("Valor do topo da pilha: %d\n", PilhaInt_obter(pilha));

  // PilhaInt_imprimir(pilha);
  // printf("\n");

  PilhaInt_destruir(pilha);
  return 0;
}
