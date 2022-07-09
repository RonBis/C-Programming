#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 100

typedef struct alphabet_node {
  char alphabet;
  int count;
  struct alphabet_node *next;
} alphabet_n;

alphabet_n *head;

void insert_alphabet(char alphabet) {
  alphabet_n *temp, *curr;

  temp = (alphabet_n *)malloc(sizeof(alphabet_n));
  temp->alphabet = alphabet;
  temp->count = 1;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    curr = head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = temp;
  }
}

void display() {
  alphabet_n *curr = head;
  int count = 0;

  while (curr != NULL) {
    printf("%c : %d\n", curr->alphabet, curr->count);
    curr = curr->next;
    count++;
  }

  printf("\nTotal number of distinct alphabets is %d", count);
}

int check_if_exists(char alphabet) {
  alphabet_n *curr = head;

  while (curr != NULL) {
    if (curr->alphabet == alphabet) {
      curr->count++;
      return true;
    }
    curr = curr->next;
  }
  return false;
}

int main() {
  char sentence[STRING_LEN];

  printf("Give a sentence : ");
  gets(sentence);

  for (int i = 0; i < strlen(sentence); i++) {
    if (isalpha(sentence[i]) && !check_if_exists(sentence[i])) {
      insert_alphabet(tolower(sentence[i]));
    }
  }

  display();
  printf("\n");
  return 0;
}
