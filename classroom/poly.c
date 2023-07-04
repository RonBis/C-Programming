#include <stdio.h>
#include <stdlib.h>

#define MAXPOW 10

typedef struct POLY {
  int coeff;
  int pow;
  struct POLY *next;
} poly;

poly *getInput(poly *p, int max_pow) {
  for (int i = max_pow; i >= 0; i--) {
    int coeff;
    printf("Coefficient for index %d: ", i);
    scanf("%d", &coeff);

    poly *term = (poly *)malloc(sizeof(poly));
    term->pow = i;
    term->coeff = coeff;

    term->next = p;
    p = term;
  }
  return p;
}

int getMaxPow(char prompt[]) {
  int maxPow;
  printf("\nEnter max power for %s: ", prompt);
  while (1) {
    scanf("%d", &maxPow);
    if (maxPow >= 0 || maxPow <= MAXPOW) {
      return maxPow;
    }
    continue;
  }
}

void display(poly *head) {
  poly *tmp = head;
  while (tmp != NULL) {
    printf("%dx^%d + ", tmp->coeff, tmp->pow);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  poly *p1 = NULL, *p2 = NULL;

  int maxPow1 = getMaxPow("polynomial 1");
  p1 = getInput(p1, maxPow1);
  int maxPow2 = getMaxPow("polynomial 2");
  p2 = getInput(p2, maxPow2);

  // display(p1);
  // display(p2);

  // sum head
  poly *sum = NULL;
  // summation
  while (p1 != NULL && p2 != NULL) {
    poly *term = (poly *)malloc(sizeof(poly));
    term->pow = p1->pow;
    term->coeff = p1->coeff + p2->coeff;

    term->next = sum;
    sum = term;

    p1 = p1->next;
    p2 = p2->next; 
  }

  if (p1 == NULL && p2 == NULL) {
    printf("Sum: ");
    display(sum);
    return 0;
  }
  if (p1 == NULL) {
    p2->next = sum;
    sum = p2;
  } else {
    p1->next = sum;
    sum = p1;
  }
  printf("Sum: ");
  display(sum);

  return 0;
}
