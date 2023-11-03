#include "stdio.h"

int main() {
  int size = 0;
  int currentNumber = 0;
  int countPart1 = 0, countPart2 = 0;

  FILE *fp = fopen("./test.txt", "r");
  if (fp == NULL) {
    printf("Error opening file");
  }

  while (fscanf(fp, "%d", &currentNumber) == 1) {
    size++;
  }

  fseek(fp, 0, SEEK_SET);

  int sumSize = size - 2;
  int sumOfThree[sumSize];
  int number[size];
  for (int i = 0; i < size; ++i) {
    fscanf(fp, "%d", &currentNumber);
    number[i] = currentNumber;

    if (i >= 1 && number[i] > number[i - 1]) {
      countPart1++;
    }

    if (i >= 2) {
      sumOfThree[i - 2] = number[i - 2] + number[i - 1] + number[i];
      if (i >= 3 && sumOfThree[i - 3] < sumOfThree[i - 2]) {
        countPart2++;
      }
    }
  }

  printf("Answer for part 1 = %d\nAnswer for Part 2 = %d\n", countPart1,
         countPart2);
}
