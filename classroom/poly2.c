#include <stdio.h>
#include <stdlib.h>

typedef struct term {
  int base, pow;
  struct term *next;
} LL;

LL *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

void insertTerm(int n, LL *p1, LL *p2) {
  LL *new = (LL *)malloc(sizeof(LL));
  switch (n) {
  case 1:
    printf("Enter Base, Power: ");
    scanf("%d, %d", &new->base, &new->pow);
    if (poly1 == NULL)
      new->next = NULL;
    else
      new->next = poly1;
    poly1 = new;
    break;
  case 2:
    printf("Enter Base, Power: ");
    scanf("%d, %d", &new->base, &new->pow);
    if (poly2 == NULL)
      new->next = NULL;
    else
      new->next = poly2;
    poly2 = new;
    break;
  case 3:
    new->pow = p1->pow;
    new->base = p1->base + p2->base;
    if (poly3 == NULL)
      new->next = NULL;
    else
      new->next = poly3;
    poly3 = new;
    break;
  case 4:
    new->pow = p1->pow;
    new->base = p1->base;
    if (poly3 == NULL)
      new->next = NULL;
    else
      new->next = poly3;
    poly3 = new;
    break;
  case 5:
    new->pow = p2->pow;
    new->base = p2->base;
    if (poly3 == NULL)
      new->next = NULL;
    else
      new->next = poly3;
    poly3 = new;
    break;
  }
}

void createpoly(int n) {
  int a = 1;
  char ch;
  LL *new = NULL;
  while (a == 1) {
    printf("\n      Enter 'y' to insert a term or Enter 'n' to stop: ");
    scanf(" %c", &ch);
    switch (ch) {
    case 'y':
      insertTerm(n, NULL, NULL);
      break;
    case 'n':
      a = 0;
      break;
    default:
      printf("\nINVALID INPUT\n");
    }
  }
}

void display(LL *poly) {
  if (poly == NULL) {
    printf("POLYNOMIAL IS EMPTY\n");
    return;
  }
  LL *term = poly;
  while (term != NULL) {
    if (term->pow == 0)
      printf("%d", term->base);
    else
      printf("%dx^%d", term->base, term->pow);
    term = term->next;
    if (term != NULL)
      printf(" + ");
  }
}

void addleftovers(int n, LL *poly) {
  LL *p3 = poly3, *p = poly;
  int z;
  while (p != NULL) {
    z = 0, p3 = poly3;
    while (p3 != NULL) {
      if (p3->pow == p->pow) {
        z = 1;
        break;
      } else if (p3->next != NULL)
        p3 = p3->next;
      else if (p3->next == NULL && p3->pow != p->pow) {
        z = 0;
        break;
      }
    }
    if (z == 1)
      p = p->next;
    else if (z == 0) {
      n = 4;
      insertTerm(n, p, NULL);
      p = p->next;
    }
  }
}

void add(int n) {
  LL *p1 = poly1, *p2 = poly2;
  while (p1 != NULL) {
    if (p1->pow == p2->pow) {
      insertTerm(n, p1, p2);
      p1 = p1->next;
      p2 = poly2;
    } else if (p2->next != NULL)
      p2 = p2->next;
    else {
      p1 = p1->next;
      p2 = poly2;
    }
  }
  n = 4;
  addleftovers(n, poly1);
  n = 5;
  addleftovers(n, poly2);
}

void freePoly(LL *poly) {
  LL *term = poly;
  while (term != NULL) {
    LL *temp = term;
    term = term->next;
    free(temp);
  }
}

int main() {
  int ch, n;
  while (1) {
    printf("\n\nMenu:\n     1. Enter 1st Polynominal. \n     2. Enter 2nd "
           "Polynomial. \n     3. Add the 2 Polynomials. \n     4. Retry. \n   "
           "  0. Exit. \nEnter Choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      n = 1;
      createpoly(n);
      printf("\n1st Polynomial: ");
      display(poly1);
      break;
    case 2:
      n = 2;
      createpoly(n);
      printf("\n2nd Polynomial: ");
      display(poly2);
      break;
    case 3:
      n = 3;
      printf("\n1st Polynomial: ");
      display(poly1);
      printf("\n2nd Polynomial: ");
      display(poly2);
      printf("\n----------------------------------------------------");
      add(n);
      printf("\nAdded Polynomial: ");
      display(poly3);
      break;
    case 4:
      freePoly(poly1), freePoly(poly2), freePoly(poly3);
      poly1 = NULL, poly2 = NULL, poly3 = NULL;
      printf("resetting done you can retry...");
      break;
    case 0:
      freePoly(poly1), freePoly(poly2), freePoly(poly3);
      printf("exiting...");
      exit(-1);
    default:
      printf("\nINVALID INPUT\n");
    }
  }
  return 0;
}