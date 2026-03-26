#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 10

int main() {
    int grades[STUDENT_COUNT];
    int sum = 0;
    double average;

    srand(time(NULL));

    for (int i = 0; i < STUDENT_COUNT; i++) {
        grades[i] = rand() % 101;
        sum += grades[i];

        printf("%2d번 학생 성적: %3d점\n", i + 1, grades[i]);
    }

    average = (double)sum / STUDENT_COUNT;

    printf("---------------------------\n");
    printf("전체 학생 점수 합계: %d점\n", sum);
    printf("전체 학생 평균 점수: %.2f점\n", average);

    return 0;
}
