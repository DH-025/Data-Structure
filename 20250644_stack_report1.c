#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[101];
  char *stack;
  int top = -1;
  int length = 0;

  printf("문자열을 입력하세요: ");
  fgets(input, sizeof(input), stdin);

  while (input[length] != '\0') {
    length++;
  }

  if (input[length - 1] == '\n') {
    input[length - 1] = '\0';
    length--;
  }

  stack = (char *)malloc(sizeof(char) * length);

  for (int i = 0; i < length; i++) {
    stack[++top] = input[i];
  }

  printf("거꾸로 출력된 문자열: ");
  while (top >= 0) {
    printf("%c", stack[top--]);
  }
  printf("\n");

  free(stack);

  return 0;
}
