#include "RGB.h"

struct RGB RGB_from_int(int i_rgb) {
  struct RGB rgb;

  rgb.blue = i_rgb % 256;
  i_rgb >>= 8;

  rgb.green = i_rgb % 256;
  i_rgb >>= 8;

  rgb.red = i_rgb % 256;

  return rgb;
}

void desafio_RGB() {
  RGB_print(RGB_from_int(0x00ff00));
  RGB_print(RGB_from_int(0b11111111));
  RGB_print(RGB_from_int(16711680));
}