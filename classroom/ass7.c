#include <stdio.h>
#include <string.h>

int top = -1;
int prefix[10];

void push(int element) {
  if (top == 19)
    printf("The stack is full");
  else {
    top++;
    prefix[top] = element;
  }
}

int pop() {
  int element;
  if (top == -1)
    printf("The stack is empty");
  else {
    element = prefix[top];
    top--;
  }
  return element;
}

void display() {
  int i = 0;
  printf("Prefix Evaluation: ");
  printf("%d", prefix[i]);
}

int main() {
  int i, operand1, operand2, p;
  char stack[20], ch;
  printf("Enter the prefix expression: ");
  scanf("%s", stack);
  i = strlen(stack) - 1;
  while (i >= 0) {
    ch = stack[i];
    if (ch - '0' >= 0 && ch - '0' <= 9) {
      push(ch - '0');
    } else {
      operand1 = pop();
      operand2 = pop();
      switch (ch) {
      case '/':
        p = operand1 / operand2;
        push(p);
        break;
      case '*':
        p = operand1 * operand2;
        push(p);
        break;
      case '+':
        p = operand1 + operand2;
        push(p);
        break;
      case '-':
        p = operand1 - operand2;
        push(p);
        break;
      default:
        printf("Invalid input");
      }
    }
    i--;
  }
  display();
  return 0;
}
