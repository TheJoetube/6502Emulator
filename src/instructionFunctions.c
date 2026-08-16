#include "../include/instructionFunctions.h"
#include "../include/constants.h"
#include <stdio.h>

void initInstructions() {
    //LDA
    inst.LDA_IM = (Instruction){0xA9,2,Immediate,LDA};
    inst.LDA_ZP = (Instruction){0xA5,3,ZeroPage,LDA};
    inst.LDA_ZP_X = (Instruction){0xB5,4,ZeroPage_X,LDA};
    inst.LDA_ABS = (Instruction){0xAD,4,Absolute,LDA};
    inst.LDA_ABS_X = (Instruction){0xBD,4,Absolute_X,LDA};
    inst.LDA_ABS_Y = (Instruction){0xB9,4,Absolute_Y,LDA};
    inst.LDA_IN_X = (Instruction){0xA1,6,IndexedIndirect,LDA};
    inst.LDA_IN_Y = (Instruction){0xB1,5,IndirectIndexed,LDA};

    //LDX
    inst.LDX_IM = (Instruction){0xA2,2,Immediate,LDX};
    inst.LDX_ZP = (Instruction){0xA6,3,ZeroPage,LDX};
    inst.LDX_ZP_Y = (Instruction){0xB6,4,ZeroPage_Y,LDX};
    inst.LDX_ABS = (Instruction){0xAE,4,Absolute,LDX};
    inst.LDX_ABS_Y = (Instruction){0xBE,4,Absolute_Y,LDX};

    //LDY
    inst.LDY_IM = (Instruction){0xA0,2,Immediate,LDY};
    inst.LDY_ZP = (Instruction){0xA4,3,ZeroPage,LDY};
    inst.LDY_ZP_X = (Instruction){0xB4,4,ZeroPage_X,LDY};
    inst.LDY_ABS = (Instruction){0xAC,4,Absolute,LDY};
    inst.LDY_ABS_X = (Instruction){0xBC,4,Absolute_X,LDY};

    //STA
    inst.STA_ZP = (Instruction) {0x85,3,ZeroPage,STA};
    inst.STA_ZP_X = (Instruction){0x95,4,ZeroPage_X,STA};
    inst.STA_ABS = (Instruction){0x8D,4,Absolute,STA};
    inst.STA_ABS_X = (Instruction){0x9D,5,Absolute_X,STA};
    inst.STA_ABS_Y = (Instruction){0x99,5,Absolute_Y,STA};
    inst.STA_IN_X = (Instruction){0x81,6, IndexedIndirect, STA};
    inst.STA_IN_Y = (Instruction){0x91,6, IndirectIndexed, STA};

    //STX
    inst.STX_ZP = (Instruction){0x86,3,ZeroPage,STX};
    inst.STX_ZP_Y = (Instruction){0x96,4,ZeroPage_Y,STX};
    inst.STX_ABS = (Instruction){0x8E,4,Absolute,STX};

    //STY
    inst.STY_ZP = (Instruction){0x84,3,ZeroPage,STY};
    inst.STY_ZP_X = (Instruction){0x94,4,ZeroPage_X,STY};
    inst.STY_ABS = (Instruction){0x8C,4,Absolute,STY};

    //TAX
    inst.TAX_IMP = (Instruction){0xAA,2,Implicit,TAX};

    //TAY
    inst.TAY_IMP = (Instruction){0xA8,2,Implicit,TAY};

    //TXA
    inst.TXA_IMP = (Instruction){0x8A,2,Implicit,TXA};

    //TYA
    inst.TYA_IMP = (Instruction){0x98,2,Implicit,TYA};

    //TSX
    inst.TSX_IMP = (Instruction){0xBA,2, Implicit, TSX};

    //TXS
    inst.TXS_IMP = (Instruction){0x9A,2,Implicit,TXS};

    //PHA
    inst.PHA_IMP = (Instruction){0x48,3,Implicit,PHA};

    //PHP
    inst.PHP_IMP = (Instruction){0x08,3,Implicit,PHP};

    //PLA
    inst.PLA_IMP = (Instruction){0x68,4,Implicit,PLA};

    //PLP
    inst.PLP_IMP = (Instruction){0x28,4,Implicit,PLP};

    //AND
    inst.AND_IM = (Instruction){0x29,2,Immediate,AND};
    inst.AND_ZP = (Instruction){0x25,3,ZeroPage,AND};
    inst.AND_ZP_X = (Instruction){0x35,4,ZeroPage_X,AND};
    inst.AND_ABS = (Instruction){0x2D,4,Absolute,AND};
    inst.AND_ABS_X = (Instruction){0x3D,4,Absolute_X,AND};
    inst.AND_ABS_Y = (Instruction){0x39,4,Absolute_Y,AND};
    inst.AND_IN_X = (Instruction){0x21,6,IndexedIndirect,AND};
    inst.AND_IN_Y = (Instruction){0x31,5,IndirectIndexed,AND};

    //EOR
    inst.EOR_IM = (Instruction){0x49,2,Immediate,EOR};
    inst.EOR_ZP = (Instruction){0x45,3,ZeroPage,EOR};
    inst.EOR_ZP_X = (Instruction){0x55,4,ZeroPage_X,EOR};
    inst.EOR_ABS = (Instruction){0x4D,4,Absolute,EOR};
    inst.EOR_ABS_X = (Instruction){0x5D,4,Absolute_X,EOR};
    inst.EOR_ABS_Y = (Instruction){0x59,4,Absolute_Y,EOR};
    inst.EOR_IN_X = (Instruction){0x41,6,IndexedIndirect,EOR};
    inst.EOR_IN_Y = (Instruction){0x51,5,IndirectIndexed,EOR};

    //ORA
    inst.ORA_IM = (Instruction){0x09,2,Immediate,ORA};
    inst.ORA_ZP = (Instruction){0x05,3,ZeroPage,ORA};
    inst.ORA_ZP_X = (Instruction){0x15,4,ZeroPage_X,ORA};
    inst.ORA_ABS = (Instruction){0x0D,4,Absolute,ORA};
    inst.ORA_ABS_X = (Instruction){0x1D,4,Absolute_X,ORA};
    inst.ORA_ABS_Y = (Instruction){0x19,4,Absolute_Y,ORA};
    inst.ORA_IN_X = (Instruction){0x01,6,IndexedIndirect,ORA};
    inst.ORA_IN_Y = (Instruction){0x11,5,IndirectIndexed,ORA};

    //BIT
    inst.BIT_ZP = (Instruction){0x24,3,ZeroPage,BIT};
    inst.BIT_ABS = (Instruction){0x2C,4,Absolute,BIT};

    //ADC
    inst.ADC_IM = (Instruction){0x69,2,Immediate,ADC};
    inst.ADC_ZP = (Instruction){0x65,2,ZeroPage,ADC};
    inst.ADC_ZP_X = (Instruction){0x75,2,ZeroPage_X,ADC};
    inst.ADC_ABS = (Instruction){0x6D,3,Absolute,ADC};
    inst.ADC_ABS_X = (Instruction){0x7D,3,Absolute_X,ADC};
    inst.ADC_ABS_Y = (Instruction){0x79,3,Absolute_Y,ADC};
    inst.ADC_IN_X = (Instruction){0x61,2,IndexedIndirect,ADC};
    inst.ADC_IN_Y = (Instruction){0x71,2,IndirectIndexed,ADC};

    //JSR
    inst.JSR_ABS = (Instruction){0x20,6,Absolute,JSR};

    //NOP
    inst.NOP_IMP = (Instruction){0xEA,2,Implicit,NOP};
}

Byte fetchByte(u32* cycles, CPU* cpu, const Memory* memory) {
    const Byte data = memory->data[cpu->PC];
    cpu->PC++;
    *cycles -= 1;
    return data;
}

Byte readByte(u32* cycles, const Word address, const Memory* memory) {
    const Byte data = memory->data[address];
    *cycles -= 1;
    return data;
}

void writeByte(u32* cycles, const Byte data, const Word address, Memory* memory) {
    memory->data[address] = data;
    *cycles -= 1;
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

void writeWord(u32* cycles, const Word data, const Word address, Memory *memory) {
    memory->data[address] = data & 0xFF;
    memory->data[address+1] = (data >> 8);
    *cycles -= 2;
}

Byte wrapByte(const Word value) {
    return value & 0xFF;
}

Word wrapWord(const Word value) {
    return value & 0x00FF;
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
            zpAddressX = wrapByte(zpAddressX);
            *cycles -= 1;
            cpu->A = readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->A = readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            cpu->A = readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            cpu->A = readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            cpu->A = readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            cpu->A = readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void LDX(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->X = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->X = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_Y:
            Byte zpAddressY = fetchByte(cycles, cpu, memory);
            zpAddressY += cpu->Y;
            *cycles -= 1;
            cpu->X = readByte(cycles, 0x0000 | zpAddressY, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->X = readByte(cycles, absAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            cpu->X = readByte(cycles, absYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & 0b10000000) > 0;
}

void LDY(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->Y = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->Y = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpAddressX = fetchByte(cycles, cpu, memory);
            zpAddressX += cpu->X;
            *cycles -= 1;
            cpu->Y = readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->Y = readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            cpu->Y = readByte(cycles, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & 0b10000000) > 0;
}

void STA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->A, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->A, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->A, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->A, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            *cycles -= 1;
            writeByte(cycles, cpu->A, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            writeByte(cycles, cpu->A, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 3;
            writeByte(cycles, cpu->A, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void STX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->X, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_Y:
            Byte zpYAddress = fetchByte(cycles, cpu, memory);
            zpYAddress += cpu->Y;
            *cycles -= 1;
            writeByte(cycles, cpu->X, 0x0000 | zpYAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->X, absAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void STY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->Y, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->Y, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->Y, absAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void TAX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->X = cpu->A;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & 0b10000000) > 0;
}

void TAY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->Y = cpu->A;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & 0b10000000) > 0;
}

void TXA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->A = cpu->X;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void TYA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->A = cpu->Y;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void TSX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->X = cpu->SP;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & 0b10000000) > 0;
}

void TXS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->SP = cpu->X;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void PHA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            writeByte(cycles, cpu->A, STACKSTART + cpu->SP, memory);
            cpu->SP--;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void PHP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            writeByte(cycles, cpu->status.value, STACKSTART + cpu->SP, memory);
            cpu->SP--;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void PLA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            const Byte stackByte = readByte(cycles, STACKSTART + cpu->SP, memory);
            cpu->SP++;
            cpu->A = stackByte;
            *cycles -= 2;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void PLP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            const Byte stackByte = readByte(cycles, STACKSTART + cpu->SP, memory);
            cpu->SP++;
            cpu->status.value = stackByte;
            *cycles -= 2;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void AND(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->A &= fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->A &= readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpAddressX = fetchByte(cycles, cpu, memory);
            zpAddressX += cpu->X;
            zpAddressX = wrapByte(zpAddressX);
            *cycles -= 1;
            cpu->A &= readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->A &= readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            cpu->A &= readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            cpu->A &= readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            cpu->A &= readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            cpu->A &= readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void EOR(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->A ^= fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpAddressX = fetchByte(cycles, cpu, memory);
            zpAddressX += cpu->X;
            zpAddressX = wrapByte(zpAddressX);
            *cycles -= 1;
            cpu->A ^= readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            cpu->A ^= readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            cpu->A ^= readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            cpu->A ^= readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            cpu->A ^= readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void ORA(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate:
            cpu->A |= fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            cpu->A |= readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpAddressX = fetchByte(cycles, cpu, memory);
            zpAddressX += cpu->X;
            zpAddressX = wrapByte(zpAddressX);
            *cycles -= 1;
            cpu->A |= readByte(cycles, 0x0000 | zpAddressX, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            cpu->A |= readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            cpu->A |= readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            cpu->A |= readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            cpu->A |= readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            cpu->A |= readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & 0b10000000) > 0;
}

void BIT(CPU* cpu, Memory* memory, u32* cycles) {
    Byte result = 0x00;
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    result = cpu-> A & memVal;

    cpu->status.Z = (result == 0x00);
    cpu->status.V = (0b01000000 & memVal) > 0;
    cpu->status.N = (0b10000000 & memVal) > 0;
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
            writeWord(cycles, cpu->PC - 1, STACKSTART + cpu->SP, memory);
            cpu->PC = subAddr;
            cpu->SP--;
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