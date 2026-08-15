#include "../include/instructionFunctions.h"
#include "../include/constants.h"
#include <stdio.h>

void initInstructions() {
    //LDA
    inst.LDA_IM = (Instruction){
        0xA9,
        2,
        Immediate,
        LDA
    };

    inst.LDA_ZP = (Instruction){
        0xA5,
        3,
        ZeroPage,
        LDA
    };

    inst.LDA_ZP_X = (Instruction){
        0xB5,
        4,
        ZeroPage_X,
        LDA
    };

    inst.LDA_ABS = (Instruction){
        0xAD,
        4,
        Absolute,
        LDA
    };

    inst.LDA_ABS_X = (Instruction){
        0xBD,
        4,
        Absolute_X,
        LDA
    };

    inst.LDA_ABS_Y = (Instruction){
        0xB9,
        4,
        Absolute_Y,
        LDA
    };

    inst.LDA_IN_X = (Instruction){
        0xA1,
        6,
        IndexedIndirect,
        LDA
    };

    inst.LDA_IN_Y = (Instruction){
        0xB1,
        5,
        IndirectIndexed,
        LDA
    };

    //LDX
    inst.LDX_IM = (Instruction){
        0xA2,
        2,
        Immediate,
        LDX
    };

    inst.LDX_ZP = (Instruction){
        0xA6,
        3,
        ZeroPage,
        LDX
    };

    inst.LDX_ZP_Y = (Instruction){
        0xB2,
        4,
        ZeroPage_X,
        LDX
    };

    inst.LDX_ABS = (Instruction){
        0xAE,
        4,
        Absolute,
        LDX
    };

    inst.LDX_ABS_Y = (Instruction){
        0xBE,
        4,
        Absolute_Y,
        LDX
    };

    //LDY
    inst.LDY_IM = (Instruction){
        0xA0,
        2,
        Immediate,
        LDY
    };

    inst.LDY_ZP = (Instruction){
        0xA4,
        3,
        ZeroPage,
        LDY
    };

    inst.LDY_ZP_X = (Instruction){
        0xB4,
        4,
        ZeroPage_X,
        LDY
    };

    inst.LDY_ABS = (Instruction){
        0xAC,
        4,
        Absolute,
        LDY
    };

    inst.LDY_ABS_X = (Instruction){
        0xBC,
        4,
        Absolute_X,
        LDY
    };

    //ADC
    inst.ADC_IM = (Instruction){
        0x69,
        2,
        Immediate,
        ADC
    };
    inst.ADC_ZP = (Instruction){
        0x65,
        2,
        ZeroPage,
        ADC
    };
    inst.ADC_ZP_X = (Instruction){
        0x75,
        2,
        ZeroPage_X,
        ADC
    };
    inst.ADC_ABS = (Instruction){
        0x6D,
        3,
        Absolute,
        ADC
    };
    inst.ADC_ABS_X = (Instruction){
        0x7D,
        3,
        Absolute_X,
        ADC
    };
    inst.ADC_ABS_Y = (Instruction){
        0x79,
        3,
        Absolute_Y,
        ADC
    };
    inst.ADC_IN_X = (Instruction){
        0x61,
        2,
        IndexedIndirect,
        ADC
    };
    inst.ADC_IN_Y = (Instruction){
        0x71,
        2,
        IndirectIndexed,
        ADC
    };

    //JSR
    inst.JSR_ABS = (Instruction){
        0x20,
        6,
        Absolute,
        JSR
    };

    //NOP
    inst.NOP_IMP = (Instruction){
            0xEA,
        2,
        Implicit,
        NOP
    };
}

Byte fetchByte(u32* cycles, CPU* cpu, const Memory* memory) {
    const Byte data = memory->data[cpu->PC];
    cpu->PC++;
    *cycles -= 1;
    return data;
}

Byte readByte(u32* cycles, Word address, const Memory* memory) {
    const Byte data = memory->data[address];
    *cycles -= 1;
    return data;
}

Word fetchWord(u32* cycles, CPU *cpu, const Memory *memory) {
    //6502 is little endian
    Word data = memory->data[cpu->PC];
    cpu->PC++;

    data |= (memory->data[cpu->PC] << 8);
    cpu->PC++;
    *cycles -= 2;

    return data;
}

void writeWord(u32* cycles, Word data, Word address, Memory *memory) {
    memory->data[address] = data & 0xFF;
    memory->data[address+1] = (data >> 8);
    *cycles -= 2;
}

Instruction* getInstruction(const Byte instruction, CPU* cpu) {
    const size_t numInstructions = sizeof(inst) / sizeof(Instruction);
    for (size_t i = 0; i < numInstructions; i++) {
        if (inst.instructions[i].opcode == instruction) {
            cpu->mode = inst.instructions[i].mode;
            return &inst.instructions[i];
        }
    }
    cpu->mode = inst.NOP_IMP.mode;
    return &inst.NOP_IMP;
}

void LDA(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->A = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->A = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpAddressX = fetchByte(cycles, cpu, memory);
            zpAddressX += cpu->X;
            *cycles -= 1;
            cpu->A = readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            break;

        case Absolute_X:
            break;

        case Absolute_Y:
            break;

        case IndexedIndirect:
            break;

        case IndirectIndexed:
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void LDX(CPU* cpu, Memory* memory, u32* cycles) {
    const Byte fetchedByte = fetchByte(cycles, cpu, memory);
    switch(cpu->mode) {
        case Immediate:
            cpu->X = fetchedByte;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & 0b10000000) > 0;
}

void LDY(CPU* cpu, Memory* memory, u32* cycles) {
    const Byte fetchedByte = fetchByte(cycles, cpu, memory);
    switch(cpu->mode) {
        case Immediate:
            cpu->Y = fetchedByte;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & 0b10000000) > 0;
}

void ADC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Immediate:
            cpu->A += fetchByte(cycles, cpu, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void JSR(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Absolute:
            const Word subAddr = fetchWord(cycles, cpu, memory);
            writeWord(cycles, cpu->PC - 1, cpu->SP, memory);
            cpu->PC = subAddr;
            cpu->SP++;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void NOP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}