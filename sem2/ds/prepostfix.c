#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct STACK {
  char *vals;
  int top;
} stack;

void push(stack *stack, char val) { stack->vals[++stack->top] = val; }

char pop(stack *stack) {
  char top = stack->top;
  stack->top--;
  return stack->vals[top];
}

int precedence(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '/' || c == '*') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  stack expstack = (stack){
      .vals = (char *)malloc(sizeof(char) * 20),
      .top = -1,
  };

  char infix_exp[20], exp[20];
  int exp_len = 0;

  printf("Infix expression: ");
  scanf("%s", infix_exp);

  for (int i = 0; infix_exp[i] != '\0'; i++) {
    char c = infix_exp[i];
    // check if operand
    if (isalnum(c)) {
      exp[exp_len++] = c;
    } else if (c == '(') {
      push(&expstack, '(');
    } else if (c == ')') {
      while (expstack.vals[expstack.top] != '(') {
        exp[exp_len++] = pop(&expstack);
      }
      pop(&expstack); // pop the '('
    } else {
      // lower precedence than TOP
      while (precedence(c) < precedence(expstack.vals[expstack.top])) {
        exp[exp_len++] = pop(&expstack);
      }
      // higher precedence than TOP
      if (precedence(c) > precedence(expstack.vals[expstack.top])) {
        push(&expstack, c);
      }
      // equal precedence
      else {
        // TODO
      }
    }
  }
  // reached end-of-expression, pop all and add them to expression
  while (expstack.top != -1) {
    exp[exp_len++] = pop(&expstack);
  }
  exp[exp_len] = '\0';
  printf("%s\n", exp);

  free(expstack.vals);
  return 0;
}
