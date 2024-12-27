#include <stdio.h>
#include <stdlib.h>

FILE *FILEloc;

int main () {
    char messages[100];
    if ((FILEloc = fopen("text.txt","a")) == NULL){
        printf("NULL FILEloc program terminated");
        getchar();
        exit(0);
    }
    FILEloc = fopen("text.txt","a");
    printf("\n\n\t\t\t\tTHE OUTBOUND MESSAGE IS\n");
    while (messages != NULL) {
        fgets(messages,100,stdin);
        //printf("\n%c\n",messages[0]);
        if (messages[0] == 'q') break;
        fputs(messages,FILEloc);
    } 
    fclose(FILEloc);
}
