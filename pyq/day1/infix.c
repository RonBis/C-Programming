// 10 + ((7 - 5) + 10) / 2 + 5 * 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char postfix[100], infix[100], expstack[50], top = -1;

void push(char ch) {
  expstack[++top] = ch;
}

char pop() {
  char ch = expstack[top];
  top--;
  return ch;
}

int precedence(char c) {
  switch(c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}

bool isOperator(char c) {
  switch(c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return true;
    default:
      return false;
  }
}

char topElement() {return expstack[top];}

int main() {
  printf("Enter infix expression: ");
  gets(infix);

  int j = 0;
  for(int i = 0; infix[i] != '\0'; i++) {
    char ch = infix[i];

    // add operands to postfix
    if(!isOperator(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      push(ch);
    } else if(ch == ')') {
      char popped;
      while((popped = pop()) != '(') {
        postfix[j++] = popped;
      }
    } else {
      while(precedence(topElement()) >= precedence(infix[i])) {
        postfix[j++] = pop();
      }

      push(infix[i++]);
    }
  }
  while(top != -1) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';

  printf("postfix expression: %s\n", postfix);

  return 0;
}

