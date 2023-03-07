#include <stdio.h>

typedef struct complex {
  float r;
  float i;
} complex;

complex add(complex c1, complex c2) {
  return (complex){.r = c1.r + c2.r, .i = c1.i + c2.i};
}

complex mult(complex c1, complex c2) {
  float real = c1.r*c2.r - c1.i*c2.i;
  float imag = c1.r*c2.i + c1.i*c2.r;
  return (complex){ .r = real, .i = imag };
}

int main() {
  complex c1, c2;

  printf("Enter complex 1(separate real and imaginary part with space): ");
  scanf("%f %f", &c1.r, &c1.i);

  printf("Enter complex 2(separate real and imaginary part with space): ");
  scanf("%f %f", &c2.r, &c2.i);

  complex sum = add(c1, c2), prod = mult(c1, c2);
  printf("Sum: %.2f + %.2fi\n", sum.r, sum.i);
  printf("Product: %.2f + %.2fi\n", prod.r, prod.i);

  return 0;
}
