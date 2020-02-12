#include "ListaInt.h"

int teste_basico_ListaInt() {
  ListaInt* lista = ListaInt_criar();

  ListaInt_adicionar_no_comeco(lista, 10);
  ListaInt_adicionar_no_comeco(lista, 20);
  ListaInt_adicionar_no_comeco(lista, 30);
  ListaInt_adicionar_no_comeco(lista, 40);

  ListaInt_imprimir(lista);
  printf("\n");

  ListaInt_adicionar_no_fim(lista, 10);
  ListaInt_adicionar_no_fim(lista, 20);
  ListaInt_adicionar_no_fim(lista, 30);
  ListaInt_adicionar_no_fim(lista, 40);

  ListaInt_imprimir(lista);
  printf("\n");

  int *vetor, tamanho;
  vetor = ListaInt_para_vetor(lista, &tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  free(vetor);
  ListaInt_destruir(lista);
  return 0;
}