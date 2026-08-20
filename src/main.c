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
    const RunParams params = {0, True, 0};

    fillMemory("res/6502_functional_test.bin", &memory);

    reset(&cpu, &memory);

    cpu.PC = 0x0400;

    execute(&cpu, &memory, params);

    return 0;
}