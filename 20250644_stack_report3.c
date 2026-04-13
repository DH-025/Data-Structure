#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  int data[MAX]; // 계산 위해 int로 변경
  int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int value) {
  if (isFull(s)) {
    printf("Stack overflow!\n");
    return;
  }
  s->data[++(s->top)] = value;
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return s->data[(s->top)--];
}

int peek(Stack *s) {
  if (isEmpty(s)) {
    return -1;
  }
  return s->data[s->top];
}

int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return -1;
}

// 후위표기식 계산
int evaluatePostfix(char *postfix) {
  Stack s;
  initStack(&s);

  for (int i = 0; postfix[i] != '\0'; i++) {
    char ch = postfix[i];

    if (isdigit(ch)) {
      push(&s, ch - '0');
    } else {
      int b = pop(&s);
      int a = pop(&s);
      int result;

      switch (ch) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        result = a / b;
        break;
      default:
        printf("error...\n");
        exit(1);
      }
      push(&s, result);
    }
  }
  return pop(&s);
}

// 중위 → 후위 변환
int infixToPostfix(char *infix, char *postfix) {
  Stack s;
  initStack(&s);

  int j = 0;

  for (int i = 0; infix[i] != '\0'; i++) {
    char ch = infix[i];

    if (isdigit(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      push(&s, ch);
    } else if (ch == ')') {
      while (!isEmpty(&s) && peek(&s) != '(') {
        postfix[j++] = pop(&s);
      }
      pop(&s); // '(' 제거
    } else {
      while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
        postfix[j++] = pop(&s);
      }
      push(&s, ch);
    }
  }

  while (!isEmpty(&s))
    postfix[j++] = pop(&s);

  postfix[j] = '\0';

  return evaluatePostfix(postfix);
}

int main() {
  char infix[MAX];
  char postfix[MAX];
  int result;

  printf("중위표기식 입력: ");
  scanf("%s", infix);

  result = infixToPostfix(infix, postfix);

  printf("후위표기식: %s\n", postfix);
  printf("계산 결과: %d\n", result);

  return 0;
}