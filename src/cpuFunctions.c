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
    cpu->status.I = 1;
    cpu->status.Unused = 1;
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
    fprintf(stderr,"A: 0x%02x X: 0x%02x Y: 0x%02x ", cpu->A, cpu->X, cpu->Y);
    fprintf(stderr,"PC: 0x%04x SP: 0x%02x ", cpu->PC, cpu->SP);
    fprintf(stderr,"Mode: %d ", cpu->mode);
    fprintf(stderr,"Status: 0b");
    fprintf(stderr,"%d", cpu->status.N);
    fprintf(stderr,"%d", cpu->status.V);
    fprintf(stderr,"%d", cpu->status.Unused);
    fprintf(stderr,"%d", cpu->status.B);
    fprintf(stderr,"%d", cpu->status.D);
    fprintf(stderr,"%d", cpu->status.I);
    fprintf(stderr,"%d", cpu->status.Z);
    fprintf(stderr,"%d\n", cpu->status.C);
}

void printPC(const CPU* cpu) {
    fprintf(stderr, "PC: 0x%04x\n", cpu->PC);
}

void setDefaultParams(RunParams* params) {
    params->numCycles = 0;
    params->constRun = False;
    params->clockSpeed = 0;
}

void execute(CPU* cpu, Memory* memory, RunParams params) {
    while (params.constRun || params.numCycles > 0) {

        if (cpu->PC == 0x3469) {
            fprintf(stderr,"Success");
            return;
        }
        //--fetch--//
        const Byte instructionByte = fetchByte(&params.numCycles, cpu, memory);
        //printf("%02x\n", instruction);

        //--decode--//
        const Instruction decodedInstruction = *getInstruction(instructionByte, cpu);
        //fprintf(stderr,"%s:\n", instNames[decodedInstruction.opcode]);

        //--execute--//
        decodedInstruction.execute(cpu, memory, &params.numCycles);

        //printStatus(cpu);
        //printPC(cpu);

        #ifdef _WIN32
        Sleep(params.clockSpeed);
        #else
        usleep(params.clockSpeed*1000);
        #endif
    }
}