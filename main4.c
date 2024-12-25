#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21
struct character {
    char name[MAX];
    char id[MAX];
    struct character *ptr;
};
int numberofchar;
char endmessage[MAX] = "end of operation";
void insert (struct character *person){
    for (int i = 0 ; i < numberofchar ; i ++){
        scanf("%s",person->name); //person.name
        scanf("%s",person->id); //person.id
        person->ptr = (person+1); //person.ptr = (person+1)
    }
    printf("%s\n",endmessage);
}
void display (struct character *person){
    for (int i = 0 ; i < numberofchar ; i ++){
        printf("%s\n",person->name);
        printf("%s\n",person->id);
        person->ptr = (person+1);
    }
    printf("%s\n",endmessage);
}
int main () {
    printf("insert number of char\n");
    scanf("%d",&numberofchar);
    struct character *locchar = (struct character *)malloc(numberofchar*sizeof(struct character));
    if (locchar == (struct character *)NULL){
        printf("Failed");
        free(locchar);
        exit(1);
    }
    insert(locchar);
    display(locchar);
    free(locchar);
}