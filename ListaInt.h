#ifndef LISTA_INT
#define LISTA_INT
#include <stdio.h>
#include <stdlib.h>

/*
 * Descrição:
 * - TAD da estrutura de dados lista, para inteiros. Estrutura de propósito geral,
 *  podendo ser usado como pilha ou fila também.
 * 
 * Exemplos práticos:
 * - Usado normalmente para trabalhar com conjunto de elementos de tamanho desconhecido.
 * - Sua operação de inserção e remoção no começo e no fim é ótima, mas seu mecanismo
 *  de busca é muito ruim comparado com vetores. Portanto, existe uma forte relação
 *  entre listas e vetores, e a conversão entre eles sempre é uma boa maneira de manter
 *  a eficiencia do programa. 
 * 
 * Observação:
 * - Deve se ter em mente que estruturas em C não se responsabilizam sobre a má utilização
 *  de suas estruturas de dados, e que cada programador deve ser responsável por verificar
 *  se a estrutura esta nas condições certas para realizar cada operação.
 */

typedef struct NoListaInt {
  int valor;
  struct NoListaInt* proximo;
  struct NoListaInt* anterior;
} NoListaInt;

typedef struct ListaInt {
  NoListaInt* comeco;
  NoListaInt* fim;
} ListaInt;

int ListaInt_vazia(ListaInt* lista);
int ListaInt_remover_do_comeco(ListaInt* lista);

/*
 * Cria uma nova lista de inteiros.
 * 
 * @return Retorna uma lista de inteiro vazia.
 */
ListaInt* ListaInt_criar() {
  ListaInt* lista = malloc(sizeof(ListaInt));
  lista->comeco = NULL;
  lista->fim = NULL;
  return lista;
}

/*
 * Remove todos os elementos da lista e a destrói uma lista de inteiros.
 * 
 * @param lista: Lista que deve ser destruída.
 */
void ListaInt_destruir(ListaInt* lista) {
  while (!ListaInt_vazia(lista)) {
    ListaInt_remover_do_comeco(lista);
  }

  free(lista);
}

/*
 * Adiciona um novo elemento inteiro no começo da lista.
 * 
 * @param lista: Lista que receberá o novo elemento.
 * @param valor: Valor que será adicionado a lista.
 */
void ListaInt_adicionar_no_comeco(ListaInt* lista, int valor) {
  NoListaInt* novo = malloc(sizeof(NoListaInt));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;
  
  if (lista->comeco == NULL) {
    lista->comeco = novo;
    lista->fim = novo;
  } else {
    lista->comeco->proximo = novo;
    novo->anterior = lista->comeco;
    lista->comeco = novo;
  }
}

/*
 * Remove e obtém o elemento do começo da lista.
 * 
 * @param lista: Lista que sofrerá com a remoção do elemento que está no começo.
 * @return Retorna o valor removido.
 */
int ListaInt_remover_do_comeco(ListaInt* lista) {
  int valor = lista->comeco->valor;
  NoListaInt* comeco = lista->comeco;

  if (lista->comeco == lista->fim) {
    lista->comeco = NULL;
    lista->fim = NULL;
  } else {
    lista->comeco = lista->comeco->anterior;
  }

  free(comeco);
  return valor;
}

/*
 * Obtém o elemento do começo da lista, sem removê-lo.
 * 
 * @param lista: Lista que desejo conhecer o valor que está no começo.
 * @return Retorna o valor que se encontra no começo da lista.
 */
int ListaInt_obter_do_comeco(ListaInt* lista) {
  return lista->comeco->valor;
}

/*
 * Adiciona um novo elemento inteiro no fim da lista.
 * 
 * @param lista: Lista que receberá o novo elemento.
 * @param valor: Valor que será adicionado a lista.
 */
void ListaInt_adicionar_no_fim(ListaInt* lista, int valor) {
  NoListaInt* novo = malloc(sizeof(NoListaInt));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;
  
  if (lista->comeco == NULL) {
    lista->comeco = novo;
    lista->fim = novo;
  } else {
    lista->fim->anterior = novo;
    novo->proximo = lista->fim;
    lista->fim = novo;
  }
}

/*
 * Remove e obtém o elemento do fim da lista.
 * 
 * @param lista: Lista que sofrerá com a remoção do elemento que está no fim.
 * @return Retorna o valor removido.
 */
int ListaInt_remover_do_fim(ListaInt* lista) {
  int valor = lista->fim->valor;
  NoListaInt* fim = lista->fim;

  if (lista->comeco == lista->fim) {
    lista->comeco = NULL;
    lista->fim = NULL;
  } else {
    lista->fim = lista->fim->proximo;
  }

  free(fim);
  return valor;
}

/*
 * Obtém o elemento do fim da lista, sem removê-lo.
 * 
 * @param lista: Lista que desejo conhecer o valor que está no fim.
 * @return Retorna o valor que se encontra no fim da lista.
 */
int ListaInt_obter_do_fim(ListaInt* lista) {
  return lista->fim->valor;
}

/*
 * Obtém o tamanho da lista.
 * !! Operação custosa !!
 * 
 * @param lista: Lista que desejo conhecer o seu tamanho.
 * @return Retorna o valor que se encontra no fim da lista.
 */
int ListaInt_tamanho(ListaInt* lista) {
  int tamanho = 0;

  NoListaInt* auxiliar = lista->comeco;
  while (auxiliar != NULL) {
    tamanho++;
    auxiliar = auxiliar->anterior;
  }

  return tamanho;
}

/*
 * Verifica se uma lista esta vazia.
 * 
 * @param lista: Lista que desejo saber se esta vazia ou não.
 * @return Retorna 1 caso a lista esteja vazia. Caso contrário, retorna 0.
 */
int ListaInt_vazia(ListaInt* lista) {
  if (lista->comeco == NULL) 
    return 1;
  return 0;
}

/*
 * Imprime todos os elementos da lista.
 *
 * @param lista: Lista de inteiros a ser impressa.
 */
void ListaInt_imprimir(ListaInt* lista) {
  NoListaInt* auxiliar = lista->comeco;

  printf("ListaInt(");
  while (auxiliar != NULL && auxiliar->anterior != NULL) {
    printf("%d, ", auxiliar->valor);
    auxiliar = auxiliar->anterior;
  }
  if (auxiliar != NULL) {
    printf("%d)", auxiliar->valor);
  }
}

/*
 * Converte uma lista em um vetor.
 * 
 * @param lista: Lista de inteiros a ser convertida para um vetor.
 * @param saida_tamanho: Ponteiro de um inteiro que conterá o tamanho do vetor ao final da operação.
 * @return Retorna o vetor com os elementos da lista.
 */
int* ListaInt_para_vetor(ListaInt* lista, int* saida_tamanho) {
  int tamanho = ListaInt_tamanho(lista);
  int *vetor = calloc(tamanho, sizeof(int));

  int indice = 0;
  NoListaInt* auxiliar = lista->comeco;
  while (auxiliar != NULL) {
    vetor[indice] = ListaInt_remover_do_comeco(lista);
    indice++;
    auxiliar = auxiliar->anterior;
  }

  *saida_tamanho = tamanho;
  return vetor;
}

/*
 * Converte um vetor em uma lista.
 * 
 * @param vetor: Vetor de inteiros a ser convertido para lista.
 * @param tamanho: Tamanho do vetor.
 * @return Retorna a lista com os elementos do vetor.
 */
ListaInt* ListaInt_de_vetor(int* vetor, int tamanho) {
  ListaInt* lista = ListaInt_criar();

  int indice;
  for (indice = 0; indice < tamanho; indice++ ) {
    ListaInt_adicionar_no_fim(lista, vetor[indice]);
  }

  return lista;
}

#endif
