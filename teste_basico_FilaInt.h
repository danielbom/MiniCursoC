#include <stdio.h>
#include "FilaInt.h"

int teste_basico_FilaInt() {
  FilaInt* fila = FilaInt_criar();

  FilaInt_adicionar(fila, 10);
  FilaInt_adicionar(fila, 20);
  FilaInt_adicionar(fila, 30);
  FilaInt_adicionar(fila, 40);

  // FilaInt_imprimir(fila);
  // printf("\n");

  printf("Removendo um elemento da fila: %d\n", FilaInt_remover(fila));
  printf("Valor na frente da fila: %d\n", FilaInt_obter(fila));

  // FilaInt_imprimir(fila);
  // printf("\n");

  FilaInt_destruir(fila);
  return 0;
}
