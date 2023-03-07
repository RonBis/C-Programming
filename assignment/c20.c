#include <stdio.h>

int mstrlen(char str[]) {
  int i;
  for (i = 0; str[i] != '\0'; i++)
    ;
  return i;
}

int main() {
  char word[10];
  printf("Enter word: ");
  scanf("%s", word);

  int len = mstrlen(word);

  // for upper triangle
  // outer loop for choosing the starting position of printing characters
  for (int i = 0; i < len; i++) {

    // inner loop for printing each character
    for (int j = 0; j < len; j++) {
      if (j < i) {
        // print spaces before starting position
        printf(" ");
      } else {
        printf("%c", word[j]);
      }
    }
    printf("\n");
  }

  // for lower triangle

  // as the upper triangle also contains the single last character,
  // to prevent that last character from printing again, start loop from (len-2)
  // note: (len-1) is the last index of string
  for (int i = len - 2; i >= 0; i--) {
    for (int j = 0; j < len; j++) {
      if (j < i) {
        printf(" ");
      } else {
        printf("%c", word[j]);
      }
    }
    printf("\n");
  }

  return 0;
}