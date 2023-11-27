#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MD5_BLOCK_SIZE 64

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

typedef struct {
    uint32_t A, B, C, D, E;
} MD5_STATE;

void md5_transform(uint32_t state[5], const uint8_t block[MD5_BLOCK_SIZE]) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t x[16];

    for (int i = 0; i < 16; i++) {
        x[i] = *((uint32_t*)(block + i * 4));
    }

    // MD5 rounds
    // Round 1
    for (int i = 0; i < 16; i++) {
        uint32_t temp = F(b, c, d) + x[i] + 0x5A827999 + a;
        a = e;
        e = d;
        d = LEFT_ROTATE(c, 30);
        c = b;
        b = a;
        a = temp;
    }

    // Round 2
    for (int i = 0; i < 16; i++) {
        uint32_t temp = G(b, c, d) + x[(5 * i + 1) % 16] + 0x6ED9EBA1 + a;
        a = e;
        e = d;
        d = LEFT_ROTATE(c, 30);
        c = b;
        b = a;
        a = temp;
    }

    // Round 3
    for (int i = 0; i < 16; i++) {
        uint32_t temp = H(b, c, d) + x[(3 * i + 5) % 16] + 0x8F1BBCDC + a;
        a = e;
        e = d;
        d = LEFT_ROTATE(c, 30);
        c = b;
        b = a;
        a = temp;
    }

    // Round 4
    for (int i = 0; i < 16; i++) {
        uint32_t temp = I(b, c, d) + x[(7 * i) % 16] + 0xCA62C1D6 + a;
        a = e;
        e = d;
        d = LEFT_ROTATE(c, 30);
        c = b;
        b = a;
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

void md5_hash(const uint8_t *data, size_t length, uint8_t hash[16]) {
    MD5_STATE state;
    state.A = 0x67452301;
    state.B = 0xEFCDAB89;
    state.C = 0x98BADCFE;
    state.D = 0x10325476;
    state.E = 0x76543210;

    size_t block_count = length / MD5_BLOCK_SIZE;

    for (size_t i = 0; i < block_count; i++) {
        md5_transform((uint32_t*)&state, data + i * MD5_BLOCK_SIZE);
    }

    memcpy(hash, &state, 16);
}

int main() {
    char input[1000];

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline characters from the input
    input[strcspn(input, "\n")] = '\0';

    uint8_t hash[16];

    md5_hash((uint8_t*)input, strlen(input), hash);

    printf("Input: %s\n", input);
    printf("MD5 Hash: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

