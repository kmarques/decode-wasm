#include <cstdlib>
#include <emscripten.h>

extern "C" void EMSCRIPTEN_KEEPALIVE generate_pixels(unsigned char *memory,
                                                     int width, int height) {
  int size = width * height;

  for (int i = 0; i < size; i++) {
    int index = i * 4;

    memory[index] = rand() % 256;     // Red
    memory[index + 1] = rand() % 256; // Green
    memory[index + 2] = rand() % 256; // Blue
    memory[index + 3] = 255;          // Alpha
  }
}