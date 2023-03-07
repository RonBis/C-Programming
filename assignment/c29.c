#include <stdio.h>

int mstrlen(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

void add_char(char c, char str[]) {
  char codes[] = {'#', '$', '%', '^'};
  static int code_index = 0;

  // get prevoius length of string before adding new codes
  int len = mstrlen(str);

  // if character is not an alphabet, add that character to the string without
  // modification
  if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
    str[len] = c;
    str[len + 1] = '\0';
    return;
  }

  // if lowercase char, change them to uppercase
  if (c >= 'a' && c <= 'z') {
    c = c - 32;
  }

  // calculate alphabetical index of char
  int size = c - 'A' + 1;
  int i;
  // string concat at end
  for (i = 0; i < size; i++) {
    // codes[i % 4] gives the alternative sequence of codes
    str[len + i] = codes[code_index % 4];
  }
  // add a string terminator at the end of string
  str[len + i + 1] = '\0';
  code_index++;
}

int main() {
  char src_str[20];
  printf("Enter string: ");
  gets(src_str);

  char new_str[500] = "";
  for (int i = 0; src_str[i] != '\0'; i++) {
    add_char(src_str[i], new_str);
  }
  printf("%s\n", new_str);

  return 0;
}
