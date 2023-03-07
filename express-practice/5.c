#include <stdio.h>

int main() {
  char str[50];
  printf("Enter a string: ");
  gets(str);

  int len = 0;
  for (len = 0; str[len] != '\0'; len++)
    ;

  int is_palindrome = 1;
  for (int j = 0; j < len / 2; j++) {
    if (str[j] != str[len - j - 1]) {
      is_palindrome = 0;
      break;
    }
  }

  printf(is_palindrome ? "Palindrome!\n" : "Not palindrome 😔\n");
  return 0;
}
