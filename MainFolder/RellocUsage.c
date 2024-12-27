#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// calulate the total price with optional choice

int main () {
    unsigned short numberofthings;
    printf("numbers of things:");
    scanf("%u", &numberofthings);
    /////////////////////////////////////////////////////////////////////
    int *priceofthings = (int *)malloc(((numberofthings+1)*sizeof(int)));
    /////////////////////////////////////////////////////////////////////
    if (priceofthings == (int *)NULL){
        printf("error");
        free (priceofthings);
        exit(1);
    }
    printf("insert price naja\n");
    for (unsigned short i = 0 ; i < numberofthings ; i  ++){
        scanf("%d", &priceofthings[i]);
        priceofthings[numberofthings] += priceofthings[i];
    }
    printf("do you want to add up ONE more thing?:");
    // re allocate mem
    /////////////////////////////////////////////////////////////////////////////////
    priceofthings = (int *)realloc(priceofthings,((numberofthings+1+1)*sizeof(int)));
    /*
    The point to note is that realloc() should only be used for dynamically allocated memory. 
    If the memory is not dynamically allocated, then behavior is undefined.
    */
    /////////////////////////////////////////////////////////////////////////////////
    if (priceofthings == (int *)NULL){
        printf("failed");
        free (priceofthings);
        exit(1);
    }
    scanf("%d",&priceofthings[numberofthings+1]);
    priceofthings[numberofthings] += priceofthings[numberofthings+1];

    printf("the total price is %d\n", priceofthings[numberofthings]);
    free (priceofthings);
}
