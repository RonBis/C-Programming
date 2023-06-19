#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int *stack;
int top = -1;

void push(char operand) {
  if (top == MAX - 1) {
    printf("max stack size is reached\n");
    exit(EXIT_FAILURE);
  }
  stack[++top] = operand;
}

void pop() {
  if (top == -1) {
    printf("error: stack underflow\n");
    exit(EXIT_FAILURE);
  }
  top--;
}

void evalPrefix(char *exp) {}

void evalPostfix(char *exp) {
  for (int i = 0; exp[i] != '\0'; i++) {
  }
}

int main() {
  int choice;
  printf("Enter choice:\n1.Prefix expression\n2.Postfix expression");
  scanf("%d", &choice);

  char exp[MAX];
  printf("Enter expression: ");
  scanf("%s", exp);

  if (choice == 1) {
    evalPrefix(exp);
  } else if (choice) {
    evalPostfix(exp);
  } else {
    printf("Invalid choice\n");
  }

  return 0;
}