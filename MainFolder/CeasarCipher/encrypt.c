#include <stdio.h>
#include <string.h>
#define MAXMESSAGE 51
/*
        TO DO 
key NUMBER
message STRING
encoded STRING
decoded STRING
*/

void EnterMessage(char *message){
    printf("\t\tPlease enter the message:\n");
    fgets(message,MAXMESSAGE,stdin);
    /*
    for (int i = 0 ; message[i] != '\0' ; i ++){
        printf("\t%d\n",message[i]);
    }
    printf("length of message = %d\n",(int)strlen(message));
    */
    //char *ptr = &message[(int)strlen(message)]; //DOESNT NEED I FORGOR;
    //if (*ptr == '\n') *ptr = '\0';
}

void EnterShiftedKEY (int *key) {
    printf("\nEnter number key:\n");
    scanf("%d",key);
    *key = (*key)%26;
    printf("\nshifted by: %d\n",*key);
}
void ShiftMessage (char *message,int key){
    int j = 0;
    for (int i = 0 ; i < ((int)strlen(message)) ; i++){
        if (message[i] == '\0') continue;
        //printf("%d\n",message[i]);
        if (message[i] >= 'A' && message[i] <= 'Z'){
            while (j < key){
                message[i] += 1;
                if (message[i] > 'Z') message[i] = 'A';
                j ++;
            }
        }
        if (message[i] >= 'a' && message[i] <= 'z'){
            while (j < key){
                message[i] += 1;
                if (message[i] > 'z') message[i] = 'a';
                j ++;
            }
        }
        j = 0;
    }
}
int main () {
    char message[MAXMESSAGE];
    int key = 0;
    EnterMessage(message);
    EnterShiftedKEY(&key);
    ShiftMessage(message,key);
    printf("\t\tThe encypted message is:\n%s",message);
    //printf("key == %d",key);
}