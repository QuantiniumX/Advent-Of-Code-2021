#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LINES 1000

int getFirstInt(char *line) {
  int first_int;
  for (int i = 0; i < strlen(line); i++) {
    if (isdigit(line[i])) {
      first_int = line[i] - '0';
      break;
    }
  }
  return first_int;
}

int getLastInt(char *line) {
  int last_int;
  for (int i = strlen(line) - 1; i >= 0; i--) {
    if (isdigit(line[i])) {
      last_int = line[i] - '0';
      break;
    }
  }
  return last_int;
}

int calculateSum(char *line) {
  int first = getFirstInt(line);
  int last = getLastInt(line);
  return 10 * first + last;
}

int main(void) {
  char line[256];  // Adjust the size according to your needs
  int answer = 0;
  FILE *fp = fopen("./input.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (fgets(line, sizeof(line), fp)) {
    answer += calculateSum(line);
  }

  fclose(fp);

  printf("The answer for the first part is: %d\n", answer);
  return 0;
}

