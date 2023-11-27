#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

void encipher();
void decipher();

int main()
{
    int choice;


    while (1)
    {
        printf("\n1. Encrypt Text");
        printf("\t2. Decrypt Text");
        printf("\t3. Exit");
        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        if (choice == 3)
            break;
        else if (choice == 1)
            encipher();
        else if (choice == 2)
            decipher();
        else
            printf("Please Enter Valid Option.");
    }

    return 0;
}

void encipher()
{
    unsigned int i, j;
    char input[50], key[10];

    printf("\n\nEnter Plain Text: ");
    scanf("%s", input);

    printf("\nEnter Key Value: ");
    scanf("%s", key);

    printf("\nResultant Cipher Text: ");

    for (i = 0, j = 0; i < strlen(input); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }

        printf("%c", 'A' + (((toupper(input[i]) - 'A') + (toupper(key[j]) - 'A')) % 26));
    }

    printf("\n");
}

void decipher()
{
    unsigned int i, j;
    char input[50], key[10];
    int value;

    printf("\n\nEnter Cipher Text: ");
    scanf("%s", input);

    printf("\nEnter Key Value: ");
    scanf("%s", key);

    printf("\nResultant Deciphered Text: ");

    for (i = 0, j = 0; i < strlen(input); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }

        value = (toupper(input[i]) - 'A') - (toupper(key[j]) - 'A');
        if (value < 0)
        {
            value = value + 26;
        }

        printf("%c", 'A' + (value % 26));
    }

    printf("\n");
}

