#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct digit {
  int digit;
  int freq;
} digit;

void updateDigits(digit *digits, int *digits_len, int dig) {
  for (int i = 0; i < *digits_len; i++) {
    if (digits[i].digit == dig) {
      digits[i].freq++;
      return;
    }
  }

  *digits_len = *digits_len + 1;
  digits = (digit *)realloc(digits, *digits_len * sizeof(digit));
  digits[*digits_len - 1] = (digit){.digit = dig, .freq = 1};
}

int main() {
  int number;
  digit *digits = (digit *)malloc(sizeof(digit));
  int digits_len = 0;

  printf("Enter a number: ");
  scanf("%d", &number);

  int numcopy = number;
  while (number != 0) {
    int r = number % 10;
    updateDigits(digits, &digits_len, r);
    number /= 10;
  }

  for(int i=0; i<digits_len; i++) {
    printf("%d: %d\n", digits[i].digit, digits[i].freq);
  }

  return 0;
}
