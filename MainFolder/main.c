#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMEmax 21

/*
        TO DO:
struct queue (from ANSI C book)
create two pointer*
1. point to top (in)
2. point to bottom (out)
Enqueue (put in) and Serving (put out)
FIFO
*/

struct person {
    char name[NAMEmax];
    struct person *next_address;
};

struct person *qIN,*qOUT;

void enqueue (char *new_name) {
    struct person *new;
    new = (struct person *)malloc (sizeof(struct person));
    if (new == (struct person *)NULL){
        printf("Failed to push\n");
        exit(1);
    }
    if (qOUT == NULL){
        qOUT = new;
    }
    if (qIN != NULL){
        qIN->next_address = new;
    }
    strcpy(new->name,new_name);
    new->next_address = NULL;
    qIN = new;
}
void serve (char *new_name){
    struct person *next;
    strcpy(new_name,qOUT->name);
    next = qOUT->next_address;
    free(qOUT);
    qOUT = next;
}
void create () {
    char name[NAMEmax];
    printf("\ninsert name\npress \"x\" to cancel:");
    while (1){
        fgets(name,NAMEmax,stdin);
        if (strncmp(name,"x",1) == 0) break;
        enqueue(name);
    }
}
void display () {
    char name[NAMEmax];
    printf("\nThe names in the queue are:\n");
    while (qOUT != NULL){
        serve(name);
        printf("%s\n",name);
    }
}

int main () {
    qIN = NULL;
    qOUT = NULL;
    create();
    display();
}