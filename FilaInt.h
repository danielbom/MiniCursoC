#ifndef FILA_INT
#define FILA_INT
#include <stdio.h>
#include <stdlib.h>

/*
 * Descrição:
 * - TAD da estrutura de dados fila, para inteiros. Simula o enfileiramento de valores.
 * 
 * Exemplos práticos:
 * - Controle de documentos para impressão.
 * - Controle de tarefas dependêntes.
 * - Troca de mensagem entre computadore em uma rede.
 * 
 * Observação:
 * - Deve se ter em mente que estruturas em C não se responsabilizam sobre a má utilização
 *  de suas estruturas de dados, e que cada programador deve ser responsável por verificar
 *  se a estrutura esta nas condições certas para realizar cada operação.
 */
 
typedef struct NoFilaInt {
  int valor;
  struct NoFilaInt *anterior;
} NoFilaInt;

typedef struct FilaInt {
  NoFilaInt* primeiro;
  NoFilaInt* ultimo;
} FilaInt;

int FilaInt_vazia(FilaInt* fila);
int FilaInt_remover(FilaInt* fila);

/*
 * Cria uma nova fila de inteiros.
 * 
 * @return Retorna uma fila de inteiro vazia.
 */
FilaInt* FilaInt_criar() {
  FilaInt* fila = malloc(sizeof(FilaInt));
  fila->primeiro = NULL;
  fila->ultimo = NULL;
  return fila;
}

/*
 * Remove todos os elementos da lista e a destrói uma lista de inteiros.
 * 
 * @param lista: Lista que deve ser destruída.
 */
void FilaInt_destruir(FilaInt* fila) {
  while (!FilaInt_vazia(fila)) {
    FilaInt_remover(fila);
  }

  free(fila);
}

/*
 * Adiciona um novo elemento inteiro a fila.
 * 
 * @param fila: Fila que receberá o novo elemento.
 * @param valor: Valor que será adicionado a fila.
 */
void FilaInt_adicionar(FilaInt* fila, int valor) {
  NoFilaInt* novo = malloc(sizeof(NoFilaInt));
  novo->valor = valor;
  novo->anterior = NULL;

  if (fila->primeiro == NULL) {
    fila->primeiro = novo;
    fila->ultimo = novo;
  } else {
    fila->ultimo->anterior = novo;
    fila->ultimo = novo;
  }
}

/*
 * Remove e obtem o primeiro elemento da fila.
 * 
 * @param fila: Fila que sofrerá com a remoção do primeiro elemento.
 * @return Retorna o valor removido.
 */
int FilaInt_remover(FilaInt* fila) {
  int valor = fila->primeiro->valor;
  NoFilaInt* primeiro = fila->primeiro;

  if (fila->primeiro == fila->ultimo) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
  } else {
    fila->primeiro = primeiro->anterior;
  }

  free(primeiro);
  return valor;
}

/*
 * Obtem o primeiro elemento da fila, sem removê-lo.
 * 
 * @param fila: Fila que desejo conhecer o valor que está no topo.
 * @return Retorna o valor que se encontra no topo da fila.
 */
int FilaInt_obter(FilaInt* fila) {
  return fila->primeiro->valor;
}

/*
 * Verifica se uma fila esta vazia.
 * 
 * @param fila: Fila que desejo saber se esta vazia ou não.
 * @return Retorna 1 caso a fila esteja vazia. Caso contrário, retorna 0.
 */
int FilaInt_vazia(FilaInt* fila) {
  if (fila->primeiro == NULL)
    return 1;
  return 0;
}

/*
 * Imprime todos os elementos da fila, começando pelo primeiro.
 *
 * @param fila: Fila de inteiros a ser impressa.
 */
void FilaInt_imprimir(FilaInt* fila) {
  NoFilaInt* auxiliar = fila->primeiro;

  printf("FilaInt(");
  while (auxiliar != NULL && auxiliar->anterior != NULL) {
    printf("%d, ", auxiliar->valor);
    auxiliar = auxiliar->anterior;
  }
  if (auxiliar != NULL) {
    printf("%d)", auxiliar->valor);
  }
}

#endif
