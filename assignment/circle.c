#include <stdio.h>

void calculate(float r, float *circum, float *area) {
  const float pi = 3.14159;

  *area = pi * r * r;
  *circum = 2 * pi * r;
}

int main() {
  float rad, circum, area;

  while (1) {
    printf("Enter radius of circle: ");
    scanf("%f", &rad);

    if(rad < 0) {
      printf("Radius cannot be less than 0 units.\n\n");
      continue;
    }

    calculate(rad, &circum, &area);
    printf("Area is %f and circumference is %f.\n", area, circum);
    break;
  }

  return 0;
}
