#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TERMS 20
#define MAX_STR 200


//to return the numeric values of the letters
int numericVal(char c) { return tolower(c) - 'a'; } //Convert Character Case

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


void encode(char str[], char key[], char e[], char* terms[]) {

    int strLength = (int)strlen(str);
    char* arr = keyMethod(key);

    for (int i = 0; i < strLength;i++) {
            
        if (isalpha(str[i])) {
            //printf("%d\t ", i);
            //printf("%c\t%c\n ", str[i], arr[i]);
            int res = (numericVal(str[i]) + numericVal(arr[i])) % 26;
            e[i] = res +'a';
        }
        else {
            
            printf("%d\t ", i);
            e[i] = str[i]; // to preserve the spaces
            
        }

        terms[i] = &e[i];
    }
    e[strLength] = '\0';

    terms[MAX_TERMS] = NULL;

    free(arr);
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