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
            arr[i] = key[i % keyLength];
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

    for (int i = 0; i < strLength; i++) {

        if (isalpha(str[i])) {
            int res = (numericVal(str[i]) + numericVal(arr[i])) % 26;
            e[i] = 'a' + res;
        }
        else {
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



void main() {
    return 0;
}