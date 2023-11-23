#include <stdio.h>

int main() {
  double absoluteValue, approximateValue;

  printf("Enter the absolute value: ");
  scanf("%lf", &absoluteValue);
  printf("Enter the approximate value: ");
  scanf("%lf", &approximateValue);

  // Calculate absolute error
  double absoluteError = absoluteValue - approximateValue;
  if (absoluteError < 0) {
    absoluteError *= -1;
  }

  // Calculate relative error
  double relativeError = absoluteError / absoluteValue;

  // Calculate error percentage
  double errorPercentage = (absoluteError / absoluteValue) * 100;

  // Output results
  printf("\ni. Absolute Error = %lf\n", absoluteError);
  printf("ii. Relative Error = %lf\n", relativeError);
  printf("iii. Error Percentage = %.2lf%%\n", errorPercentage);

  return 0;
}
