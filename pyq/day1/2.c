/* balanced brackets - Day1/Q2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void push(char exp[], int *top, char ch) {
  if(*top == MAX - 1) {
    printf("Stack overflow\n");
    return;
  }
  exp[++(*top)] = ch;
}

char pop(char exp[], int *top) {
  if(*top == -1) {
    printf("Stack is empty\n");
    return '\0';
  }
  char ch = exp[*top];
  (*top)--;
  return ch;
}

int main() {
  char str[MAX];
  printf("Enter expression: ");
  fgets(str, 100, stdin);
  str[strcspn(str, "\n")] = 0; // removes trailing \n

  char exp[100]; int top = -1;

  for(int i = 0; str[i] != '\0'; i++) {
    char ch = str[i];
    if(ch == '[' || ch == '{' || ch == '(') {
      push(exp, &top, ch);
    }

    // check validity for closing brackets, exit program on failure
    else if((ch == ')' && exp[top] != '(') 
    || (ch == '}' && exp[top] != '{') 
    || (ch == ']' && exp[top] != '[')) {
      printf("Invalid expression\n");
      exit(0);
    }

    // pop for valid ending brackets
    else if(ch == ')' || ch == '}' || ch == ']') {
      pop(exp, &top);
    }
  }

  // if successful, all brackets will be popped from stack
  if(top != -1) {
    printf("Invalid expression\n");
    exit(0);
  }

  printf("Expression is valid\n");
  return 0;
}
