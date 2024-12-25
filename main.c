#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 21
char endmessage[MAX] = {"end of operation\n"};
struct contactinfos {
    char name[MAX];
    char tele[MAX];
    struct contactinfos *ptr;
};


void display1 (struct contactinfos *loc) { //BOOK METHOD
    while (loc != NULL){
        printf("%s %s\n",(*loc).name,(*loc).tele);
        loc = (*loc).ptr; //read at this struct ptr
    }
    printf("%-.20s", endmessage);
}
void display2 (struct contactinfos *loc) { //BOOK writing
    while (loc != NULL){
        printf("%s %s\n",loc->name,loc->tele);
        loc = loc->ptr; //point to this ptr
    }
    printf("%-.20s", endmessage);
}

int main () {
    struct contactinfos infos[4] = {{"maxwell","131"},{"coco","212"},{"jojo","428"},{"koon","5542"}};

    //manual setup
    struct contactinfos *first = &infos[0];
    
    infos[0].ptr = &infos[1];
    infos[1].ptr = &infos[2];
    infos[2].ptr = &infos[3];
    infos[3].ptr = NULL;
    display1(first);
    display2(first);
}
