// export function generate_pixels(width: i32, height: i32): void {
//   const size: i32 = width * height;
//   for (let i: i32 = 0; i < size; i++) {
//     const addressPixel = i * 4;
//     const redValue = i32(Math.random() * 255);
//     const greenValue = i32(Math.random() * 255);
//     const blueValue = i32(Math.random() * 255);
//     const alphaValue = 255;
//
//     store<u8>(addressPixel, redValue);
//     store<u8>(addressPixel + 1, greenValue);
//     store<u8>(addressPixel + 2, blueValue);
//     store<u8>(addressPixel + 3, alphaValue);
//   }
// }

extern "C" float seed();

extern "C" void generate_pixels(unsigned char *memory, int width, int height) {
  int size = width * height;

  for (int i = 0; i < size; i++) {
    int index = i * 4;

    memory[index] = (int)(seed() * 255.0);     // Red
    memory[index + 1] = (int)(seed() * 255.0); // Green
    memory[index + 2] = (int)(seed() * 255.0); // Blue
    memory[index + 3] = 255;                   // Alpha
  }
}