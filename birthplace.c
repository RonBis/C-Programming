#include <stdio.h>
#include <string.h>

int main() {
  char birthplace[25];

  printf("Enter your birthplace : ");
  gets(birthplace);

  int res = strcmp(birthplace, "kolkata");

  if (res < 0) {
    printf("Your birthplace %s comes before kolkata in dictionary\n",
           birthplace);
  } else if (res > 0) {
    printf("Your birthplace %s comes after kolkata in dictionary\n",
           birthplace);
  } else {
    printf("I guess you just entered kolkata\n");
  }
  return 0;
}
