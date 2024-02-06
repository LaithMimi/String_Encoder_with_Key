#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TERMS 20
#define MAX_STR 200


//to return the numeric values of the letters
int numericVal(char c) { return tolower(c) - 'a'; }

//this key method fills up an array with the key letters
char* keyMethod(char key[]) {

    char* arr = (char*)malloc(MAX_TERMS * sizeof(char));

    if (arr == NULL)return NULL;

    int keyLength = (int)strlen(key);

    if (keyLength > 0) {
        for (int i = 0; i < MAX_TERMS - 1; i++) {
            arr[i] = key[i % keyLength];//(to wrap around) the index in key[] goes back to the beginning when it exceeds the length of key[]
        }
        arr[MAX_TERMS - 1] = '\0';
    }
    else {
        arr[0] = '\0';
    }

    return arr;
}


/* --------------------------------------------Wrong Code----------------------------------------------------------------
void encode(char str[], char key[], char e[], char* terms[]) {

    int strLength = (int)strlen(str);
    char* arr = keyMethod(key);

    int res ;
    printf("%s\t%s %s %s %s  %s\t %s\n", "index", "str[i]", "num(str[i])", "arr[i]", "num(arr[i])", "res", "e[i]");
    for (int i = 0; i < strLength;i++) {
        res = 0;
        if (isalpha(str[i])) {
            res = (numericVal(str[i]) + numericVal(arr[i])) % 26;
            e[i] = res +'a';
      
            printf("%d\t%c\t%d\t   %c\t  %d\t        %d\t  %c\n ",i , str[i], numericVal(str[i]), arr[i], numericVal(arr[i]),res,e[i]);
        }
        else {
            //printf("%d\t ", i);
            e[i] = str[i];// to preserve the spaces
          
            //printf("%d\t ", i);
            //printf("%c\t%c\n ", str[i], arr[i]);
            int res = (numericVal(str[i]) + numericVal(arr[i])) % 26;
            e[i] = res +'a';
        }
        else {
            
            //printf("%d\t ", i);
            e[i] = str[i]; // to preserve the spaces
            
        }
        //for loop to point at each letter in the beginning of the word in a sentance;
        //terms[i] = &e[i];
    }
    e[strLength] = '\0';

    terms[MAX_TERMS] = NULL;

    free(arr);
}*/
void encode(char str[], char key[], char e[], char* terms[]) {
    int strLength = (int)strlen(str);
    int arrLength = strlen(key);
    char* arr = keyMethod(key); 


    int res;
    int j = 0;
    //printf("%s\t%s %s %s %s  %s\t %s\n", "index", "str[i]", "num(str[i])", "arr[i]", "num(arr[i])", "res", "e[i]");
    for (int i = 0; i < strLength; i++) {
        int strNumericVal = numericVal(str[i]);
        int arrNumericVal = numericVal(arr[j % arrLength]);
        if (isalpha(str[i])) {
            res = (strNumericVal + arrNumericVal) % 26;
            e[i] = res + 'a';
            j++; // increase if letter only
            //printf("%d\t%c\t%d\t   %c\t  %d\t        %d\t  %c\n ", i, str[i], numericVal(str[i]), arr[i], numericVal(arr[i]), res, e[i]);
        }
        else {
            e[i] = str[i]; 
        }

        //for loop to point at each letter in the beginning of the word in a sentance;
       //terms[i] = &e[i];
    }

void getIthElement(char e[], char* terms[], int i, char out[]) {

}



int main() {
    
    char str[] = "World";
    char key[] = "pob";
    char e[50];
    char* terms[50]; 

    encode(str, key, e, terms);

    printf("Original: %s\n", str);
    printf("Encoded:  %s\n", e);

 
    printf("Terms:\n");
    for (int i = 0; e[i] != '\0'; i++) {
        printf("terms[%d] points to %c (Address: %p)\n", i, *terms[i], (void*)terms[i]);
    }

    return 0;
}
