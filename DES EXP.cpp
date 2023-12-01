#include<stdio.h>
#include<stdint.h>
static int initial_permutation[64]={
};
void initialPermutation(uint64_t* data){
}
void desRound(uint32_t* left, uint32_t* right, uint32_t subkey){
}
void desEncrypt(uint64_t* data, uint64_t* key){
}
int main()
{
    uint64_t plaintext=0x0123456789ABCDEF;
    uint64_t key=0x133457799BBCDFF1;      
    printf("Original Plaintext:0x%016llX\n",plaintext);
    printf("Key:0x%016llX\n",key);
    initialPermutation(&plaintext);
    desEncrypt(&plaintext,&key);
    printf("Encrypted Text:0x%016llX\n",plaintext);
    return 0;
}
