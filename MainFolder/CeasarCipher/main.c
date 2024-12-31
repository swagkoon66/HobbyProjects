#include <stdio.h>
#include <stdlib.h>

/*
        TODO CEASAR CHIPHER read one by one
0.creates file name "message.txt" 
1.choose 
    1.1 encrypt
    1.2 decrypt
2.read from the file
3.askes for the KEY
4.either do 1.1 or 1.2
5.creates file name "result.txt" stores the main message
*/

FILE *messageLOC;
FILE *resultLOC;
unsigned short option;
unsigned short key;

FILE *checkTEXT (FILE *LOC) {
    LOC = fopen("message.txt","r");
    if (LOC == NULL){
        printf("messageloc == null\n");
        //exit(1);
        return NULL;
    }
    printf("messageloc == okay!\n");
    return LOC;
}
FILE *checkRESULT (FILE *LOC) {
    LOC = fopen("result.txt","r");
    if (LOC == NULL){
        printf("resultloc == null\n");
        //exit(1);
        return NULL;
    }
    printf("resultloc == okay!\n");
    return LOC;
}

FILE *createTEXT (FILE *LOC) {
    LOC = fopen("message.txt","w+");
    if (LOC == NULL){
        printf("create messageloc == null\n");
        //exit(1);
        return NULL;
    }
    printf("create messageloc == okay!\n");
    return LOC;
}
FILE *createRESULT (FILE *LOC) {
    LOC = fopen("result.txt","w+");
    if (LOC == NULL){
        printf("create resultloc == null\n");
        //exit(1);
        return NULL;
    }
    printf("create resultloc == okay!\n");
    return LOC;
}

unsigned short chooseOPTION (unsigned short loc) {
    printf("\t\t\tPlease Choose 1.encrypt 2.decrypt\n");
    scanf("%hu",&loc);
    if (loc == 1) return 1;
    else if (loc == 2) return 2;
    else return 0;

}

unsigned short askesforKEY (unsigned short key){
    printf("\t\tplease enter the key\n");
    scanf("%hu",&key);
    return (key%26);
}
/*
read and stores in single char buffer
*/
void encrypt (FILE *messageLOC , FILE *resultLOC , unsigned short key){
    int i = 0;
    int j = 0;
    char buffer;
    while (buffer != EOF){
        fseek(messageLOC,i,SEEK_SET);
        buffer = fgetc(messageLOC);
        if (buffer == EOF) break;
            if (buffer >= 'A' && buffer <= 'Z'){
                while (j < key){
                    buffer += 1;
                    if (buffer > 'Z') buffer = 'A';
                    j ++;
                }
            }
            if (buffer >= 'a' && buffer <= 'z'){
                while (j < key){
                    buffer += 1;
                    if (buffer > 'z') buffer = 'a';
                    j ++;
                }
            }
        j = 0;
        printf("%c",buffer);
        fputc(buffer,resultLOC);
        i++;
    }

}
void decrypt (FILE *messageLOC , FILE *resultLOC , unsigned short key){
    int i = 0;
    int j = key; //
    char buffer;
    while (buffer != EOF){
        fseek(messageLOC,i,SEEK_SET);
        buffer = fgetc(messageLOC);
        if (buffer == EOF) break;
            if (buffer >= 'A' && buffer <= 'Z'){
                while (j > 0){
                    buffer -= 1;
                    if (buffer < 'A') buffer = 'Z';
                    j --;
                }
            }
            if (buffer >= 'a' && buffer <= 'z'){
                while (j > 0){
                    buffer -= 1;
                    if (buffer < 'a') buffer = 'z';
                    j --;
                }
            }
        j = key;
        printf("%c",buffer);
        fputc(buffer,resultLOC);
        i++;
    }
}

int main () {
    messageLOC = checkTEXT(messageLOC);
    resultLOC = checkRESULT(resultLOC);
    if (messageLOC == NULL) messageLOC = createTEXT(messageLOC);
    if (resultLOC == NULL) resultLOC = createRESULT(resultLOC);
    fclose(messageLOC);
    fclose(resultLOC);
    messageLOC = fopen("message.txt","r");
    resultLOC = fopen("result.txt","w");
    option = chooseOPTION(option);
    
    switch (option) {
        case 1 :
            printf("encrypt\n");
            key = askesforKEY(key);
            encrypt(messageLOC,resultLOC,key);
            //printf("key == %u\n",key);
            break;
        case 2 :
            printf("decrypt\n");
            key = askesforKEY(key);
            decrypt(messageLOC,resultLOC,key);
            //printf("key == %u\n",key);
            break;
        default :
            printf("INVALID OPTION\n");
            getchar();
            break;
    }

    fclose(messageLOC);
    fclose(resultLOC);
}