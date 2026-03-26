#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grades[10];
    int sum = 0;
    double average;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        grades[i] = rand() % 101;
        sum += grades[i];
        
        printf("%d번 학생 성적: %d점\n", i + 1, grades[i]);
    }

    average = (double)sum / 10;

    printf("---------------------------\n");
    printf("전체 학생 점수 합계: %d점\n", sum);
    printf("전체 학생 평균 점수: %.2f점\n", average);

    return 0;
}
