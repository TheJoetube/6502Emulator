#include "constants.h"
#include "cpuFunctions.h"

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