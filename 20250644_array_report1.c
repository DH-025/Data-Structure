#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main() {
  int scores[30];
  int studentNumber;
  double average;

  srand(time(0));

  for (int i = 0; i < 30; i++) {
    scores[i] = rand() % 101;
  }

  average = calculateAverage(scores, 30);
  printf("학급 평균 점수: %.2f\n", average);

  printf("학생 번호를 입력하세요 (1 ~ 30): ");
  scanf("%d", &studentNumber);

  int score = getStudentScore(scores, 30, studentNumber);
  if (score != -1) {
    printf("%d번 학생의 점수: %d\n", studentNumber, score);
  } else {
    printf("유효하지 않은 학생 번호입니다.\n");
  }

  printf("\n--- 전체 학생 ---\n");
  printScore(scores, 30, average, 0);

  printf("\n--- 평균 이상 학생 ---\n");
  printScore(scores, 30, average, 1);

  printf("\n--- 평균 미만 학생 ---\n");
  printScore(scores, 30, average, 2);

  return 0;
}

double calculateAverage(int scores[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += scores[i];
  }
  return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
  if (studentNumber >= 1 && studentNumber <= size) {
    return scores[studentNumber - 1];
  }
  return -1;
}

void printScore(int scores[], int size, double average, int option) {
  if (option < 0 || option > 2) {
    printf("잘못된 옵션입니다.\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    if (option == 0 || (option == 1 && scores[i] >= average) ||
        (option == 2 && scores[i] < average)) {

      printf("%2d번 학생: %3d점\n", i + 1, scores[i]);
    }
  }
}