#include "stdio.h"
#include "string.h"

int main() {
    char line[100];
    char action[20];
    int value, forward = 0, depth = 0;


    FILE *fp = fopen("./test.txt", "r");    
    while(fgets(line, sizeof(line), fp) != NULL){
        if(sscanf(line, "%19s %d", action, &value) == 2){
            if(strcmp(action, "forward")){
                forward += value;
                printf("%d\n %d\n", forward, value);
            }
            else if(strcmp(action, "down")){
                depth -= value;
            }
            else if(strcmp(action, "up")){
                depth += value;
            }
     }
    }
    fclose(fp);
    printf("forward: %d\n depth: %d\n", forward, depth);
}
