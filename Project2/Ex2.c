//213923931

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

            arr[i] = key[i % keyLength];//(to wrap around) -the index in key[] goes back to the beginning when it exceeds the length of key[]
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
    int arrLength = strlen(key);
    char* arr = keyMethod(key);


    int res;
    int j = 0;
    int termsIndex = 0;

    if (!isspace(str[0]))
        terms[termsIndex++] = &e[0];

    //printf("%s\t%s %s %s %s  %s\t %s\n", "index", "str[i]", "num(str[i])", "arr[i]", "num(arr[i])", "res", "e[i]");
    for (int i = 0; i < strLength; i++) {

        if (isalpha(str[i])) {
            res = (numericVal(str[i]) + numericVal(arr[j % arrLength])) % 26;
            e[i] = res + 'a';
            j++; // increase if letter only
            //printf("%d\t%c\t%d\t   %c\t  %d\t        %d\t  %c\n ", i, str[i], numericVal(str[i]), arr[i], numericVal(arr[i]), res, e[i]);
        }
        else {

            e[i] = str[i];
        }
        if ((isspace(str[i]) || str[i] == '\0') && isalpha(str[i + 1]) && termsIndex < MAX_TERMS)
            terms[termsIndex++] = &e[i + 1];
    }
    e[strLength] = '\0';


    for (int k = termsIndex; k < MAX_TERMS; k++)
        terms[k] = NULL;

    free(arr);
}


void getIthElement(char e[], char* terms[], int i, char out[]) {
    if (terms[i] != NULL) {
        // Copy the ith term into the output array
        // Assuming that words are space-delimited and terms array is properly populated
        int j = 0;
        while (terms[i][j] && terms[i][j] != ' ') {
            out[j] = terms[i][j];
            j++;
        }
        out[j] = '\0'; // Null-terminate the output string
    }
    else {
        // If i is out of bounds, set out to an empty string
        out[0] = '\0';
    }
}



int main() {

    char str[] = "Ritaj is my bestFriend";
    char key[] = "queen";
    char e[MAX_STR];
    char* terms[MAX_TERMS];

    encode(str, key, e, terms);

    printf("Original: %s\n", str);
    printf("Key: %s\n", key);
    printf("Encoded:  %s\n", e);


    printf("Terms:\n");
    for (int i = 0; terms[i] != NULL; i++) { // Assuming terms array is null-terminated
        printf("terms[%d] points to %c (Address: %p)\n", i, terms[i], (void)terms[i]);
    }
    return 0;
}
