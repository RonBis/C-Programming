#include <stdio.h>

void calculateBackwardDifference(int n, float x[], float y[][n]) {
  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }
  }
}

float backwardInterpolation(int n, float x[], float y[][n], float xi) {
  float result = y[n - 1][0];
  float term = 1;
  float u = (xi - x[n - 1]) / (x[1] - x[0]);

  for (int i = 1; i < n; i++) {
    term = term * (u + i - 1) / i;
    result = result + term * y[n - 1][i];
  }
  return result;
}

int main() {
  int n;
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  float x[n], y[n][n];

  printf("Enter the data points (x, y):\n");
  for (int i = 0; i < n; i++) {
    scanf("%f %f", &x[i], &y[i][0]);
  }

  calculateBackwardDifference(n, x, y);

  // Interpolation point
  float xi;
  printf("Enter the interpolation point: ");
  scanf("%f", &xi);

  // Interpolation
  float res = backwardInterpolation(n, x, y, xi);
  printf("Interpolated value at x = %.2f is %.4f\n", xi, res);

  return 0;
}
