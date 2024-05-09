#include <stdio.h>

void decToBin(int num) {
  if (num == 0) {
    printf("0\n");
  } else if (num < 0) {
    printf("Invalid number entered.\n");
  } else {
    int binNum = 0, i = 1;
    while (num > 0) {
      binNum += (num % 2) * i;
      i *= 10;
      num /= 2;
    }
    printf("%d\n", binNum);
  }
}

void decToOct(int num) {
  if (num <= 7 && num >= 0) {
    printf("%d\n", num);
  } else if (num < 0) {
    printf("Invalid number entered.\n");
  } else {

    int octNum = 0, i = 1;
    while (num > 0) {
      octNum += (num % 8) * i;
      i *= 10;
      num /= 8;
    }
    printf("%d\n", octNum);
  }
}

void decToHex(int num) {
  if (num == 0) {
    return;
  } else if (num < 0) {
    printf("Invalid number entered.\n");
  } else {

    int hexNum = 0;
    hexNum = num % 16;
    decToHex(num / 16);
    if (hexNum > 9) {
      printf("%c", 'A' + (hexNum - 10));
    } else {
      printf("%d", hexNum);
    }
  }
}

int main() {
  int n, choice;
  while (1) {
    char ch;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    printf("1.Decimal to Binary\n2.Decimal to Octal\n3.Decimal to "
           "Hexadecimal\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3) {
      printf("Invalid choice.");
      continue;
    }
    switch (choice) {
    case 1:
      decToBin(n);
      break;
    case 2:
      decToOct(n);
      break;
    case 3:
      decToHex(n);
      printf("\n");
      break;
    default:
      printf("Wrong choice entered.");
    }

    printf("Continue (y/n)? ");
    getchar();
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y') {
      continue;
    } else {
      break;
    }
  }
  return 0;
}
