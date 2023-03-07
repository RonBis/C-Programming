#include <stdio.h>

int isVowel(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    return 1;

  default:
    return 0;
  }
}

int main() {
  char str[40], newstr[40];
  printf("Enter a string: ");
  gets(str);

  int vowel_buff = 0;
  int new_strlen = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (isVowel(str[i])) {
      vowel_buff++;
      // if two consecutive vowels are found, reset vowel buff
      if (vowel_buff == 2) {
        vowel_buff = 0;
      }
    } else {
      // if previous character was a vowel, but the current one isn't,
      // then also reset vowel_buff.
      if (vowel_buff == 1) {
        newstr[new_strlen++] = str[i - 1];
        vowel_buff = 0;
      }
      newstr[new_strlen++] = str[i];
    }
  }
  newstr[new_strlen] = '\0';
  printf("%s\n", newstr);
  return 0;
}
// BID ADIEU TO YOUR DEAR ONES