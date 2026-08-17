#include <stdio.h>
#include "cpuFunctions.h"
#include "instructionFunctions.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void reset(CPU* cpu, const Memory* memory) {
    initInstructions();

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
 * @param cpu A pointer to a CPU struct
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

void setDefaultParams(RunParams* params) {
    params->numCycles = 0;
    params->constRun = False;
    params->clockSpeed = 0;
}

void execute(CPU* cpu, Memory* memory, RunParams params) {
    while (params.constRun || params.numCycles > 0) {

        //--fetch--//
        const Byte instructionByte = fetchByte(&params.numCycles, cpu, memory);
        //printf("%02x\n", instruction);

        //--decode--//
        const Instruction decodedInstruction = *getInstruction(instructionByte, cpu);

        //--execute--//
        decodedInstruction.execute(cpu, memory, &params.numCycles);

        printStatus(cpu);

        #ifdef _WIN32
        Sleep(params.clockSpeed);
        #else
        usleep(params.clockSpeed*1000);
        #endif
    }
}