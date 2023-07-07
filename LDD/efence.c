#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[5];
    char *dynamicBuffer;

    // Buffer overflow error
    strcpy(buffer, "Hello, World!");

    // Dynamic memory allocation
    dynamicBuffer = malloc(10);
    strcpy(dynamicBuffer, "Memory Error!");

    // Access out-of-bounds memory
    dynamicBuffer[15] = 'X';

    // Free dynamic memory
    free(dynamicBuffer);

    return 0;
}

