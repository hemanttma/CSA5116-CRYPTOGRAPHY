#include <stdio.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    while (*text != '\0') {
        if (isalpha(*text)) {
            char base = isupper(*text) ? 'A' : 'a';
            *text = (char)(((int)(*text - base + shift) % 26) + base);
        }
        text++;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, -shift);
}

int main() {
    char plaintext[] = "Hello, World!";
    int shift_amount = 3;

    encrypt(plaintext, shift_amount);n
    printf("Encrypted: %s\n", plaintext);

    decrypt(plaintext, shift_amount);
    printf("Decrypted: %s\n", plaintext);

    return 0;
}
