#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    unsigned int a[2][2] = {{9, 4}, {5, 7}};
    unsigned int b[2][2] = {{16, 3}, {15, 12}}; 
    int i, j, t = 0;
    unsigned int c[100], d[100];
    char msg[100];

    printf("Enter plain text:\n");
    fgets(msg, sizeof(msg), stdin);

    printf("Input key matrix for encryption:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Input key matrix for decryption:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < strlen(msg); i++) {
        c[i] = msg[i] - 65;
        printf("%d ", c[i]);
    }

    for (i = 0; i < strlen(msg); i += 2) {
        t = (a[0][0] * c[i] + a[0][1] * c[i + 1]) % 26;
        d[i] = t;

        t = (a[1][0] * c[i] + a[1][1] * c[i + 1]) % 26;
        d[i + 1] = t;
    }

    printf("\nEncrypted Cipher Text: ");
    for (i = 0; i < strlen(msg); i++)
        printf("%c", d[i] + 65);

    for (i = 0; i < strlen(msg); i += 2) {
        t = (b[0][0] * d[i] + b[0][1] * d[i + 1]) % 26;
        c[i] = t;

        t = (b[1][0] * d[i] + b[1][1] * d[i + 1]) % 26;
        c[i + 1] = t;
    }

    printf("\nDecrypted Cipher Text: ");
    for (i = 0; i < strlen(msg); i++)
        printf("%c", c[i] + 65);

    getch();
    return 0;
}

