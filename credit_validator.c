#include <stdio.h>

#define LENGTH 16

int toint(char c) { return c - 48; }

int main() {
  char card_num[LENGTH];
  int sum = 0;

  printf("Enter card number : ");
  scanf("%s", card_num);

  int checksum = toint(card_num[LENGTH - 1]);

  for (int i = 1; i <= LENGTH - 1; i++) {
    if (i % 2 != 0) {
      if (toint(card_num[i - 1]) * 2 > 9) {
        sum += ((toint(card_num[i - 1]) * 2) % 10 + 1);
      } else {
        sum += (toint(card_num[i - 1]) * 2);
      }
    } else {
      sum += toint(card_num[i - 1]);
    }
  }

  printf("%d\n", checksum + sum);

  if ((sum + checksum) % 10 == 0) {
    printf("Card number is valid\n");
  } else {
    printf("Card number is invalid\n");
  }

  return 0;
}
