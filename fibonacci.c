/*
    C code to perform Fibonacci term printing with recursion and function
   pointers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str;

int recursiveFibboTerm(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return recursiveFibboTerm(n - 1) + recursiveFibboTerm(n - 2);
  }
}

char *pushToString(int val) {
  char *val_str;
  static int insert_after_pos = -1;

  // gets the length of int value converted to string
  int val_length = snprintf(NULL, 0, "%d", val);

  if (insert_after_pos == -1) {
    str = malloc((val_length + 1) * sizeof(char));
  }

  // store int value(val) into string(val_str)
  val_str = malloc((val_length + 1) * sizeof(char));
  snprintf(val_str, val_length + 1, "%d", val);

  /*
    format : position_to_insert > two_spaces(2) > val_length >
    string_terminator(1)
  */
  str = realloc(str, (insert_after_pos + 3 + val_length) * sizeof(char));
  strcat(str, strcat(val_str, "  "));
  insert_after_pos += (val_length + 2);
}

void printTerm(int n) {
  void (*fp1)(int);
  fp1 = printTerm;
  if (n != 0) {
    int (*fp)(int);
    fp = recursiveFibboTerm;

    pushToString((*fp)(n));
    (*fp1)(n - 1);
  } else {
    // -3 for not to print two extra whitespace at start
    for (int i = strlen(str) - 3; i >= 0; i--) {
      printf("%c", str[i]);
    }
    return;
  }
}

int main(void) {
  int noOfTerms;

  printf("Please tell how many terms you want to print:");
  scanf("%d", &noOfTerms);

  void (*fp1)(int);
  fp1 = printTerm;
  (*fp1)(noOfTerms);

  printf("\n");

  return 0;
}
