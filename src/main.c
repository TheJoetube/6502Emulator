#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "cpuFunctions.h"

void fillMemory(const char* fileName, Memory* memory) {
    FILE *fp = fopen(fileName, "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    const long filelen = ftell(fp);
    rewind(fp);

    fread(memory, sizeof(Byte), filelen, fp);

    fclose(fp);
}

int main(void) {
    //----------------Init CPU----------------//
    Memory memory;
    CPU cpu;
    const RunParams params = {0, True, 1000};

    fillMemory("res/prg.bin", &memory);
    reset(&cpu, &memory);

    execute(&cpu, &memory, params);

    return 0;
}