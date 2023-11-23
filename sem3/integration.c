#include <stdio.h>

double fx(double x) {
  return 4*x - 3*x*x;
}

double trapezoidal(double low, double high, int interval) {
  double h = (high - low) / interval;
  
  double t = fx(high) + fx(low);
  for(double i=low+h; i <= high-h; i+=h) {
    t = t + 2*fx(i);
  }

  t *= h/2;
  return t;
}

double simpsons(double low, double high, int interval) {
  double h = (high - low) / interval;
  
  double t = fx(high) + fx(low);
  double term = low+h;
  
  int multiplicant;
  for(int i=1; term <= high-h; i++, term+=h) {
    if(i%2 == 0)
      multiplicant = 2;
    else
      multiplicant = 4;

    t = t + fx(term) * multiplicant;
  }
  
  t *= h/3;
  return t;
}

int main() {
  double low, high;
  printf("Enter lower and upper limits (separated by space): ");
  scanf("%lf %lf", &low, &high);

  int interval;
  printf("Enter interval: ");
  scanf("%d", &interval);

  printf("Trapezoidal method result: %lf\n", trapezoidal(low, high, interval));
  printf("Simpson's method result: %lf\n", simpsons(low, high, interval));
  return 0;
}