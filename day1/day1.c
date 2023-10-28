#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    char line[2000][2001];
    int i = 0;
    int number[2001];
    int count = 0;
    FILE *fp = fopen("./text", "r");
    while( fgets(line[i], 100, fp) != NULL) {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    int tot = i;
    for(int i = 0; i < 2001;i++) {
        number[i] = atoi(line[i]);
    }
    for(int i = 0; i < 1999;i++){
        printf("%d > %d\n", number[i + 1], number[i]);
        if((int) number[i + 1] > number[i]) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
