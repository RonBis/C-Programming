#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define todigit(c) c - '0'

typedef struct STACK {
  int vals[20];
  int top;
} stack;

void push(stack *stack, int val) { stack->vals[++stack->top] = val; }

int pop(stack *stack) {
  int top = stack->top;
  stack->top--;
  return stack->vals[top];
}

int raiseToPow(int base, int pow) {
  if (pow == 0)
    return 1;
  if (pow == 1)
    return base;

  int res;
  for (int i = 2; i <= pow; i++) {
    res = res * base;
  }
  return res;
}

int main() {
  char expression[20];
  stack evalstack = (stack){.top = -1, .vals = {}};

  printf("Postfix expression: ");
  scanf("%s", &expression);

  float evaled = 0;
  for (int i = 0; expression[i] != '\0'; i++) {
    char c = expression[i];
    if (isdigit(c)) {
      push(&evalstack, todigit(c));
    } else {
      // c is an operator
      float opnd2 = pop(&evalstack), opnd1 = pop(&evalstack);

      switch (c) {
      case '+':
        evaled = opnd1 + opnd2;
        break;
      case '-':
        evaled = opnd1 - opnd2;
        break;
      case '*':
        evaled = opnd1 * opnd2;
        break;
      case '/':
        evaled = opnd1 / opnd2;
        break;
      case '^':
        evaled = raiseToPow(opnd1, opnd2);
        break;
      default:
        printf("Unidentified operator encountered '%c'", c);
        exit(1);
      }

      push(&evalstack, evaled);
    }
  }

  printf("Evaluated value: %.2f\n", evaled);
  return 0;
}
