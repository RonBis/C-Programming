#include <stdio.h>
#include <stdlib.h>

void decrypt() {
  printf("\nDecryption\n");
  FILE *in = fopen("output.txt", "r");

  int shift, i = 0;
  while (1) {
    printf("Enter shift: ");
    scanf("%d", &shift);

    if (shift < 0) {
      printf("Invalid shift.\n\n");
      continue;
    }
    break;
  }

  char ch, decr[100];
  while ((ch = fgetc(in)) != EOF) {
    if (ch >= 'A' && ch <= 'Z') {
      ch = (ch - 'A' - shift + 26) % 26 + 'A';
    }
    if (ch >= 'a' && ch <= 'z') {
      ch = (ch - 'a' - shift + 26) % 26 + 'a';
    }
    decr[i++] = ch;
  }
  decr[i++] = '\0';

  printf("Decrypted message: %s\n", decr);
  fclose(in);
}

int main() {
  FILE *in = fopen("input.txt", "r");
  if (in == NULL) {
    printf("Error reading \"input.txt\".");
    exit(0);
  }
  FILE *out = fopen("output.txt", "w");
  if (out == NULL) {
    printf("Error opening \"output.txt\" in write mode.");
    exit(0);
  }

  printf("Encryption\n");
  int shift, i = 0;
  while (1) {
    printf("Enter shift: ");
    scanf("%d", &shift);

    if (shift < 0) {
      printf("Invalid shift.\n\n");
      continue;
    }
    break;
  }

  char ch, message[100];
  while ((ch = fgetc(in)) != EOF) {
    if (ch >= 'A' && ch <= 'Z') {
      ch = (ch - 'A' + shift) % 26 + 'A';
    }
    if (ch >= 'a' && ch <= 'z') {
      ch = (ch - 'a' + shift) % 26 + 'a';
    }
    message[i++] = ch;
  }
  message[i++] = '\0';
  printf("Encoded Message: %s\n", message);
  fputs(message, out);
  printf("Encoded message is written to output.txt.\n");

  fclose(in);
  fclose(out);

  decrypt();
  return 0;
}
