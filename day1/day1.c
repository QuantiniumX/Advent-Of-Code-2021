//Advent of Code 2021 Day 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    FILE *fp = fopen("./test.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int previousNumber, currentNumber;
    if (fscanf(fp, "%d", &previousNumber) == 1) {
        while (fscanf(fp, "%d", &currentNumber) == 1) {
            if (currentNumber > previousNumber) {
                count++;
            }
            previousNumber = currentNumber;
        }
    }

    fclose(fp);

    printf("Count: %d\n", count);
    return 0;
}
