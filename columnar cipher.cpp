#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Columnar Transposition Cipher
void encrypt(char *plaintext, char *key) {
    int len = strlen(plaintext);
    int keyLen = strlen(key);

    // Create an array to store the column indices based on the key
    int keyOrder[keyLen];
    for (int i = 0; i < keyLen; i++) {
        keyOrder[i] = i;
    }

    // Sort the keyOrder array based on the letters of the key
    for (int i = 0; i < keyLen - 1; i++) {
        for (int j = 0; j < keyLen - i - 1; j++) {
            if (key[j] > key[j + 1]) {
                // Swap keyOrder elements if the corresponding key letters are out of order
                int temp = keyOrder[j];
                keyOrder[j] = keyOrder[j + 1];
                keyOrder[j + 1] = temp;
            }
        }
    }

    // Calculate the number of rows required
    int rows = len / keyLen;
    if (len % keyLen != 0) {
        rows++;
    }

    // Create a 2D array to hold the characters in the table
    char table[rows][keyLen];

    // Initialize the table with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            table[i][j] = ' ';
        }
    }

    // Fill in the table with the plaintext
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (index < len) {
                table[i][keyOrder[j]] = plaintext[index++];
            }
        }
    }

    // Print the encrypted message column by column
    printf("Encrypted Message: ");
    for (int j = 0; j < keyLen; j++) {
        for (int i = 0; i < rows; i++) {
            if (table[i][j] != ' ') {
                printf("%c", table[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char plaintext[1000];
    char key[100];

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline characters from the input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Input the key
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message
    encrypt(plaintext, key);

    return 0;
}

