#include <time.h>

static clock_t __tempo_inicial;
static clock_t __tempo_final;

void inicializar_o_contador() {
  __tempo_inicial = clock();
}

void finalizar_o_contador() {
  __tempo_final = clock();

  double tempo_total = (__tempo_final - __tempo_inicial) / CLOCKS_PER_SEC;
  printf("Tempo: %.15lf s\n", tempo_total);
}