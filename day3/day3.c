#include <stdio.h>
#include <stdlib.h>

int main() {
  int count[12] = {0};
  int gammaBit[12] = {0};
  int epsilonBit[12] = {0};
  char buffer[100];
  FILE *fp = fopen("test.txt", "r");

  if (fp == NULL) {
    perror("Error opening the file");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    for (int i = 0; i < 12; i++) {
      if (buffer[i] == '1') {
        count[i]++;
      }
    }
  }

  fclose(fp);

  for (int i = 0; i < 12; i++) {
    if (count[i] > 500) {
      gammaBit[i] = 1;
      epsilonBit[i] = 0;
    } else {
      gammaBit[i] = 0;
      epsilonBit[i] = 1;
    }
  }

  int gammaDecimal = 0;
  int epsilonDecimal = 0;
  for (int i = 0; i < 12; i++) {
    gammaDecimal = (gammaDecimal << 1) | gammaBit[i];
    epsilonDecimal = (epsilonDecimal << 1) | epsilonBit[i];
  }

  int power = gammaDecimal * epsilonDecimal;
  printf("%d", power);
  return 0;
}
