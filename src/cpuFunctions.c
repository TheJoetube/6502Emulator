#include <stdio.h>
#include "cpuFunctions.h"
#include "instructionFunctions.h"

void reset(CPU* cpu, Memory* memory) {
    cpu->PC = RESVEC_LO;
    cpu->SP = 0xFF;
    cpu->A = cpu->X = cpu->Y = 0;
    cpu->status.value = 0;
    cpu->mode = Immediate;
    //memset(memory, 0, sizeof(Byte));

    Word resVec = memory->data[RESVEC_LO];
    resVec |= memory->data[RESVEC_HI] << 8;

    cpu->PC = resVec;

    //printf("Resvec Points to: 0x%04x\n", cpu->PC);
}

/**
 * Prints information about the cpu.
 * @param cpu A pointer to a @link<CPU>
 */
void printStatus(const CPU* cpu) {
    printf("A: 0x%02x\nX: 0x%02x\nY: 0x%02x\n", cpu->A, cpu->X, cpu->Y);
    printf("PC: 0x%04x\nSP: 0x%02x\n", cpu->PC, cpu->SP);
    printf("Mode: %d\n", cpu->mode);
    printf("Status: 0b");
    printf("%d", cpu->status.C);
    printf("%d", cpu->status.Z);
    printf("%d", cpu->status.I);
    printf("%d", cpu->status.D);
    printf("%d", cpu->status.B);
    printf("%d", cpu->status.V);
    printf("%d\n", cpu->status.N);
}

void execute(CPU* cpu, Memory* memory, u32 cycles) {
    while (cycles > 0) {

        //--fetch--//
        const Byte instructionByte = fetchByte(&cycles, cpu, memory);
        //printf("%02x\n", instruction);

        //--decode--//
        const Instruction decodedInstruction = *getInstruction(instructionByte, cpu);

        //--execute--//
        decodedInstruction.execute(cpu, memory, &cycles);

        //printStatus(cpu);
    }
}