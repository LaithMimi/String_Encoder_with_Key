#### Overview
The `Ex2.c` file is a C program designed to encode a given string using a specified key. The encoding is performed by shifting the characters of the input string based on the numeric values of the characters in the key.

#### Key Functions
- **numericVal**: Returns the numeric value of a character (a=0, b=1, ..., z=25).
- **keyMethod**: Generates an array based on the key, repeating the key characters to fill up the array.
- **encode**: Encodes the input string using the key and stores the result in the provided output array.
- **getIthElement**: Retrieves the i-th term from the encoded string.

#### Example Usage
```c
int main() {
    char str[] = "laith Is Hardworker";
    char key[] = "Bravo";
    char e[MAX_STR];
    char* terms[MAX_TERMS];

    encode(str, key, e, terms);

    printf("Original: %s\n", str);
    printf("Key: %s\n", key);
    printf("Encoded:  %s\n", e);

    printf("terms:\n");
    for(int i=0 ;terms[i]!=NULL;i++)
        printf("terms[%d] points to %c (Address: %p)\n", i, *terms[i], (void*)terms[i]);

    char out[50];

    // Test the getIthElement function
    for (int i = 0; i < 5; ++i) {
        getIthElement(e, terms, i, out);
        if (out[0] != '\0') {
            printf("The %dth term is '%s'\n", i, out);
        }
        else break;
    }
    
    return 0;
}
```

This usage example demonstrates how to encode a string and retrieve specific terms from the encoded result.
