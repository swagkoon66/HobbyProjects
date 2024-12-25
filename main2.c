#include <stdio.h>
#include <stdlib.h>
#define MAX 21
struct contactinfo {
    char name[MAX];
    char address[MAX];
    char telephone[MAX];
    struct contactinfo *ptr;
};

void display (struct contactinfo *loc);
void insert (struct contactinfo *loc);
void test (struct contactinfo *loc);
int n;
int x = 1;
int y = 1;
int main () {
    
    //printf("insert number naja :");
    //scanf("%d", &n);
    struct contactinfo persons[2] = {{"koon", "1134" , "062"},{"keen","3314","089"}};
    //insert(persons);
    //display(persons);
    test(persons);

}
void test (struct contactinfo *loc) {
    while ( (*loc).name != NULL){
        printf("%s\n", (*loc).name);
        loc->ptr = (loc++);
    }
    

}
/*
void display (struct contactinfo *loc){
    while (loc != (struct contactinfo *)NULL || y != n-1){
        printf("%s %s %s\n",(*loc).name,(*loc).address,(*loc).telephone);
        loc->ptr = (loc+y);
        y ++;
    }
}
void insert (struct contactinfo *loc){
    while (loc != (struct contactinfo *)NULL || x != n-1){
        scanf("%s",(*loc).name);
        scanf("%s",(*loc).address);
        scanf("%s",(*loc).telephone);
        loc->ptr = (loc+x);
        x ++;
    }
}
*/