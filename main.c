#include <stdio.h> //main thing
#include <stdlib.h> //system("cls");
#include <string.h>

FILE *FILELOC;
char filename[9+1];

/*  FOPEN
READ r
WRITE w //OVERRIDE THE EXISTING CONTENT
APPEND a (write at EOF,if no file == create new)
r+ (if file exist, discard its content) //BASICCALLY DELETED THE CONTENT
w+ (create for read & write)
a+ (read & write BUT started from EOF, If no file exist ,creates a new one)
*/

void readfromfile(FILE *loc){
    char temporary[51];
    while(fgets(temporary, 51, loc)!= NULL) {
        // Print the dataToBeRead
        printf("%s", temporary);
    }
    
}

void writeintofile(FILE *loc){
    loc = fopen(filename,"w");
    char temporary[51];
    fgets(temporary,51,stdin);
    for (int i = 0 ; i < 51 ; i ++){
        if(temporary[i] == '\n'){
            *(temporary+i) = '\0';
        }
    }
    if ((int)strlen(temporary) != 0) {
        fputs(temporary, loc); //This thing writes only one line
    }
}

void appendintofile(FILE *loc){
    loc = fopen(filename,"a");
    char temporary[51];
    fgets(temporary,51,stdin);
    
    for (int i = 0 ; i < 51 ; i ++){
        if(temporary[i] == '\n'){
            *(temporary+i) = '\0';
        }
    }
    if ((int)strlen(temporary) != 0) {
        fputs("\n", loc);
        fputs(temporary, loc); //This thing writes only one line
    }
}

void discardreadfile(FILE *loc){
    
}
void writereadfile(FILE *loc){
    
}
void appendorcreatefile(FILE *loc){
    
}

void CHECK_WHAT_TO_DO(){
    char ans[3];
    printf("Which operation do you want to perform? (r,w,a,r+,w+,a+)\n (only r,w,a available)\n");
    scanf("%s",ans);
    getchar();
    if (strcmp(ans,"r") == 0){
        system("cls");
        printf("\t\tread\n");
        readfromfile(FILELOC);
    }
    else if (strcmp(ans,"w") == 0) {
        system("cls");
        printf("\t\tover-write\n");
        writeintofile(FILELOC);
    }
    else if (strcmp(ans,"a") == 0) {
        system("cls");
        printf("\t\twritefrombefore-append\n");
        appendintofile(FILELOC);
    }
    else if (strcmp(ans,"r+") == 0) {
        system("cls");
        printf("\t\tread+discard\n");
        discardreadfile(FILELOC);
    }
    else if (strcmp(ans,"w+") == 0) {
        system("cls");
        printf("\t\twrite+create\n");
        writereadfile(FILELOC);
    }
    else if (strcmp(ans,"a+") == 0) {
        system("cls");
        printf("\t\tappend+create\n");
        appendorcreatefile(FILELOC);
    }
    
}
FILE *Create_New_file_YN(FILE *loc){
    char ans;
    printf("\n\nWould you like to create new file? Y/N:");
    ans = getchar();
    if (ans == 'Y'){
        printf("\nNew file has been created\n");
        return loc = fopen(filename,"w+");
    }
    else {
        return NULL;
        exit(1);
    }
}
FILE *CHECK_FILE(FILE *loc){
    if ((loc = fopen(filename,"r")) == NULL) {
        printf("\nNO\n");
        return loc = NULL;
    }
    else {
        printf("\nYES\n");
        return loc = fopen(filename,"r");
    }
}
void ENTER_FILE_NAME(char *loc){
    printf("\t\tEnter file's name:");
    fgets(loc,9,stdin);
    for(int i = 0 ; i < 10 ; i++){
        if (loc[i] == '\n'){
            *(loc+i) = '\0'; //this shit is way too cool
        }
    }
    getchar();
    printf("\n\t\tthe file name is:%s\n",loc);
    
}

int main () {
    //STEP1 enter the file's name
    ENTER_FILE_NAME(filename);
    //STEP2 Check whether the loc is not NULL
    FILELOC = CHECK_FILE(FILELOC);
    if (FILELOC == NULL){
        //STEP3 askes to create new file or not
        FILELOC = Create_New_file_YN(FILELOC);
    }
    //STEP4 check which operation to do
    CHECK_WHAT_TO_DO();
    getchar();
    //STEP5 Closes FILELOC steam path
    fclose(FILELOC);
}
//TESTS FOR SALES 😂😁
//printf("%s",filename);
//printf("the file location is: %p",FILELOC);