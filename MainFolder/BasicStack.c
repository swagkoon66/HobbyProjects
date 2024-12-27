#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMEmax 21
/*
        TO DO:
struct stack (from ANSI C book)
create one pointer*
1. point to top
push (put in) and pop (put out)
LIFO
*/

struct person {
    char name[NAMEmax];
    struct person *previous_loc;
};

struct person *top;


void push (char *new_name){
    struct person *new;
    new = (struct person *)malloc(sizeof(struct person));
    if (new == (struct person *)NULL){
        printf("Failed to push\n");
        exit(1);
    }
    strcpy(new->name,new_name);
    new->previous_loc = top;
    top = new;
}
void pop (char *new_name){
    struct person *temp;
    strcpy(new_name,top->name);
    temp = top->previous_loc;
    free(top);
    top = temp;
}
void create (){
    char name[NAMEmax];
    printf("\ninsert name\npress \"x\" to cancel:");
    while (1){
        fgets(name,NAMEmax,stdin);
        if (strncmp(name,"x",1) == 0) break;
        push(name);
    }
}
void displayandPOP () {
    char name[NAMEmax];
    printf("\nThe names in the stacks are:\n");
    while (top != NULL){
        pop(name);
        printf("%s\n",name);
    }
}



int main () {
    top = NULL; //points to NULL first
    create();
    displayandPOP();
    return 0;
}
