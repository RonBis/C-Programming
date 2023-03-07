#include <stdbool.h>
#include <stdio.h>

int str2int(char *number) {
  bool not_int = false, negative = false;
  int num = 0;

  // check if there is a negative sign in front of the string
  if(number[0] == '-') negative = true;

  // if negative the first character should be a '-' sign
  // so start index from 1
  int i = negative ? 1 : 0;
  for (i; number[i] != '\0'; i++) {
    // ASCII trick
    int digit = number[i] - 48;
    if(digit < 0 || digit > 9) {
      not_int = true;
      break;
    }
    num = num * 10 + digit;
  }

  if(not_int) {
    return -1;
  } else {
    if(negative) return -num;
    return num;
  }
}

int main(int argc, char **argv) {
  printf("%d\n", str2int(argv[1]));
  return 0;
}
