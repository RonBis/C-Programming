#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[20];
int top = -1;
int isEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}
void push(char ch) {
  top++;
  stack[top] = ch;
}
char pop() {
  char element;
  element = stack[top];
  top--;
  return element;
}
char topElement() { return stack[top]; }
int isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return 1;
  else
    return 0;
}
int precedence(char ch) {
  if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '+' || ch == '-') {
    return 1;
  } else
    return 0;
}
char *infixToPostfix(char *infix) {
  int size = strlen(infix);
  char *postfix = (char *)malloc((size + 1) * sizeof(char));
  int x;
  int i = 0;
  int j = 0;
  while (infix[i] != '\0') {
    if (!isOperator(infix[i])) {
      postfix[j] = infix[i];
      j++;
      i++;
    } else if (infix[i] == '(') {
      push(infix[i]);
      i++;
    } else if (infix[i] == ')') {
      while ((x = pop()) != '(') {
        postfix[j] = x;
        j++;
      }
    } else {
      while (top > -1 && precedence(infix[i]) <= precedence(topElement())) {
        postfix[j++] = pop();
      }
      push(infix[i++]);
    }
  }
  while (isEmpty() != 1) {
    postfix[j] = pop();
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}
int main() {
  char infix[20];
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  printf("Infix is %s", infix);
  printf("\nThe postfix is: %s\n", infixToPostfix(infix));
  return 0;
}