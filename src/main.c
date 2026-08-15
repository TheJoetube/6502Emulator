#include <stdio.h>
#include <string.h>
#include "instructionFunctions.h"
#include "constants.h"
#include "cpuFunctions.h"

void fillMemory(Memory* memory) {
    FILE *fp = fopen("res/prg.bin", "rb");

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
    initInstructions();
    //----------------Init CPU----------------//
    Memory memory;
    CPU cpu;
    
    fillMemory(&memory);

    reset(&cpu, &memory);
    execute(&cpu, &memory, inst.LDA_IM.cycles);

    return 0;
}