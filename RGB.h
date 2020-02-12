#ifndef RGB_H
#define RGB_H
#include <stdio.h>

struct RGB {
  unsigned char red, green, blue;
};

void RGB_print(struct RGB cor) {
  printf("rgb(%u,%u,%u)\n", cor.red, cor.green, cor.blue);
}

#endif