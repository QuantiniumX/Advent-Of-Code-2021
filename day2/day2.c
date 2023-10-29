#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    char action[20];
    int value, forward = 0, depth = 0;


    FILE *fp = fopen("./test.txt", "r");    
    while(fgets(line, sizeof(line), fp) != NULL){
        if(sscanf(line, "%19s %d", action, &value) == 2){
            if(strcmp(action, "forward") == 0){
                forward += value;
            }
            else if(strcmp(action, "down") == 0){
                depth += value;
            }
            else if(strcmp(action, "up") == 0){
                depth -= value;
            }
        }
    }
    fclose(fp);
    printf("Product of final horizontal position and final depth is: %d\n", forward * depth);
}

