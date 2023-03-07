#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct alphabet {
  char ch;
  int freq;
} alpha;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Argument missing.\n");
    exit(0);
  }

  alpha alphabets[26];
  int alpha_count = 0;

  char *str = argv[1];
  for (int i = 0; str[i] != '\0'; i++) {
    bool is_new = true;
    // loop for searching if character is unique
    for (int j = 0; j < alpha_count; j++) {
      if (str[i] == alphabets[j].ch) {
        // update frequency
        alphabets[j].freq += 1;
        is_new = false;
        break;
      }
    }

    if (is_new) {
      alphabets[alpha_count] = (alpha){.ch = str[i], .freq = 1};
      alpha_count++;
    }
  }

  for (int i = 0; i < alpha_count; i++) {
    printf("%c: %3d\n", alphabets[i].ch, alphabets[i].freq);
  }

  return 0;
}
