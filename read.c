#include <stdio.h>
#include <stdlib.h>

FILE *FILEloc;

int main () {
    char messages[100];
    if ((FILEloc = fopen("text.txt","r")) == NULL){
        printf("NULL FILEloc program terminated");
        getchar();
        exit(0);
    }
    FILEloc = fopen("text.txt","r");
    printf("\n\n\t\t\t\tTHE INBOUND MESSAGE IS\n");
    while (fgets(messages,100,FILEloc) != NULL){
        printf("%s",messages);
    }
    fclose(FILEloc);
}
