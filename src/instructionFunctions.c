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
    inst.ADC_ZP = (Instruction){0x65,3,ZeroPage,ADC};
    inst.ADC_ZP_X = (Instruction){0x75,4,ZeroPage_X,ADC};
    inst.ADC_ABS = (Instruction){0x6D,4,Absolute,ADC};
    inst.ADC_ABS_X = (Instruction){0x7D,4,Absolute_X,ADC};
    inst.ADC_ABS_Y = (Instruction){0x79,4,Absolute_Y,ADC};
    inst.ADC_IN_X = (Instruction){0x61,6,IndexedIndirect,ADC};
    inst.ADC_IN_Y = (Instruction){0x71,5,IndirectIndexed,ADC};

    //SBC
    inst.SBC_IM = (Instruction){0xE9,2,Immediate,SBC};
    inst.SBC_ZP = (Instruction){0xE5,3,ZeroPage,SBC};
    inst.SBC_ZP_X = (Instruction){0xF5,4,ZeroPage_X,SBC};
    inst.SBC_ABS = (Instruction){0xED,4,Absolute,SBC};
    inst.SBC_ABS_X = (Instruction){0xFD,4,Absolute_X,SBC};
    inst.SBC_ABS_Y = (Instruction){0xF9,4,Absolute_Y,SBC};
    inst.SBC_IN_X = (Instruction){0xE1,6,IndexedIndirect,SBC};
    inst.SBC_IN_Y = (Instruction){0xF1,5,IndirectIndexed,SBC};

    //CMP
    inst.CMP_IM = (Instruction){0xC9,2,Immediate,CMP};
    inst.CMP_ZP = (Instruction){0xC5,3,ZeroPage,CMP};
    inst.CMP_ZP_X = (Instruction){0xD5,4,ZeroPage_X,CMP};
    inst.CMP_ABS = (Instruction){0xCD,4,Absolute,CMP};
    inst.CMP_ABS_X = (Instruction){0xDD,4,Absolute_X,CMP};
    inst.CMP_ABS_Y = (Instruction){0xD9,4,Absolute_Y,CMP};
    inst.CMP_IN_X = (Instruction){0xC1,6,IndexedIndirect,CMP};
    inst.CMP_IN_Y = (Instruction){0xD1,5,IndirectIndexed,CMP};

    //CPX
    inst.CPX_IM = (Instruction){0xE0,2,Immediate,CPX};
    inst.CPX_ZP = (Instruction){0xE4,3,ZeroPage,CPX};
    inst.CPX_ABS = (Instruction){0xEC, 4, Absolute, CPX};

    //CPY
    inst.CPY_IM = (Instruction){0xC0,2,Immediate,CPY};
    inst.CPY_ZP = (Instruction){0xC4,3,ZeroPage,CPY};
    inst.CPY_ABS = (Instruction){0xCC, 4, Absolute, CPY};

    //INC
    inst.INC_ZP = (Instruction){0xE6,5,ZeroPage,INC};
    inst.INC_ZP_X = (Instruction){0xF6,6,ZeroPage_X, INC};
    inst.INC_ABS = (Instruction){0xEE,6,Absolute, INC};
    inst.INC_ABS_X = (Instruction){0xFE,7,Absolute_X,INC};

    //INX
    inst.INX_IMP = (Instruction){0xE8,2,Implicit,INX};

    //INY
    inst.INY_IMP = (Instruction){0xC8,2,Implicit,INY};

    //DEC
    inst.DEC_ZP = (Instruction){0xC6,5,ZeroPage,DEC};
    inst.DEC_ZP_X = (Instruction){0xD6,6,ZeroPage_X, DEC};
    inst.DEC_ABS = (Instruction){0xCE,6,Absolute, DEC};
    inst.DEC_ABS_X = (Instruction){0xDE,7,Absolute_X,DEC};

    //DEX
    inst.DEX_IMP = (Instruction){0xCA,2,Implicit,DEC};

    //DEY
    inst.DEY_IMP = (Instruction){0x88,2,Implicit,DEY};

    //ASL
    inst.ASL_ACC = (Instruction){0x0A,2,Accumulator,ASL};
    inst.ASL_ZP = (Instruction){0x06,5,ZeroPage,ASL};
    inst.ASL_ZP_X = (Instruction){0x16,6,ZeroPage_X,ASL};
    inst.ASL_ABS = (Instruction){0x0E,6,Absolute,ASL};
    inst.ASL_ABS_X = (Instruction){0x1E,7,Absolute_X,ASL};

    //LSR
    inst.LSR_ACC = (Instruction){0x4A,2,Accumulator,LSR};
    inst.LSR_ZP = (Instruction){0x46,5,ZeroPage,LSR};
    inst.LSR_ZP_X = (Instruction){0x56,6,ZeroPage_X,LSR};
    inst.LSR_ABS = (Instruction){0x4E,6,Absolute,LSR};
    inst.LSR_ABS_X = (Instruction){0x5E,7,Absolute_X,LSR};

    //ROL
    inst.ROL_ACC = (Instruction){0x2A,2,Accumulator,ROL};
    inst.ROL_ZP = (Instruction){0x26,5,ZeroPage,ROL};
    inst.ROL_ZP_X = (Instruction){0x36,6,ZeroPage_X,ROL};
    inst.ROL_ABS = (Instruction){0x2E,6,Absolute,ROL};
    inst.ROL_ABS_X = (Instruction){0x3E,7,Absolute_X,ROL};

    //ROR
    inst.ROR_ACC = (Instruction){0x6A,2,Accumulator,ROR};
    inst.ROR_ZP = (Instruction){0x66,5,ZeroPage,ROR};
    inst.ROR_ZP_X = (Instruction){0x76,6,ZeroPage_X,ROR};
    inst.ROR_ABS = (Instruction){0x6E,6,Absolute,ROR};
    inst.ROR_ABS_X = (Instruction){0x7E,7,Absolute_X,ROR};

    //JMP
    inst.JMP_ABS = (Instruction){0x4C,3,Absolute, JMP};
    inst.JMP_IND = (Instruction){0x6C,5,Indirect, JMP};

    //JSR
    inst.JSR_ABS = (Instruction){0x20,6,Absolute,JSR};

    //RTS
    inst.RTS_IMP = (Instruction){0x60,6,Implicit,RTS};

    //BCC
    inst.BCC_REL = (Instruction){0x90,2,Relative,BCC};

    //BCS
    inst.BCS_REL = (Instruction){0xB0,2,Relative,BCS};

    //BEQ
    inst.BCS_REL = (Instruction){0xF0,2,Relative,BEQ};

    //BMI
    inst.BMI_REL = (Instruction){0x30,2,Relative,BMI};

    //BNE
    inst.BMI_REL = (Instruction){0xD0,2,Relative,BNE};

    //BPL
    inst.BPL_REL = (Instruction){0x10,2,Relative,BPL};

    //BVC
    inst.BVC_REL = (Instruction){0x50,2,Relative,BVC};

    //BVS
    inst.BVS_REL = (Instruction){0x70,2,Relative,BVS};

    //CLC
    inst.CLC_IMP = (Instruction){0x18,2,Implicit,CLC};

    //CLD
    inst.CLC_IMP = (Instruction){0xD8,2,Implicit,CLD};

    //CLI
    inst.CLI_IMP = (Instruction){0x58,2,Implicit,CLI};

    //CLV
    inst.CLV_IMP = (Instruction){0xB8,2,Implicit,CLV};

    //SEC
    inst.SEC_IMP = (Instruction){0x38,2,Implicit,SEC};

    //SED
    inst.SED_IMP = (Instruction){0xF8,2,Implicit,SED};

    //SEI
    inst.SEI_IMP = (Instruction){0x78,2,Implicit,SEI};

    //BRK
    inst.BRK_IMP = (Instruction){0x00,7,Implicit,BRK};

    //RTI
    inst.RTI_IMP = (Instruction){0x40, 6, Implicit, RTI};

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

Word readWord(u32* cycles, const Word address, const Memory* memory) {
    Byte loByte = readByte(cycles, address, memory);
    Byte hiByte = readByte(cycles, address + 1, memory);
    return loByte | (hiByte << 8);
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
    printf("Non matched Instruction: 0x%02x\n", instruction);
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
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            cpu->A = readByte(cycles, 0x0000 | zpXAddress, memory);
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
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
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            cpu->Y = readByte(cycles, 0x0000 | zpXAddress, memory);
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
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            cpu->A &= readByte(cycles, 0x0000 | zpXAddress, memory);
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            cpu->A ^= readByte(cycles, 0x0000 | zpXAddress, memory);
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            cpu->A |= readByte(cycles, 0x0000 | zpXAddress, memory);
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
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
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
    cpu->status.N = (NEGATIVEBITMASK & memVal) > 0;
}

void ADC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    Word result = 0x0000;

    switch (cpu->mode) {
        case Immediate:
            memVal = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            memVal = readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            memVal = readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            memVal = readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            memVal = readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    const int areSignBitsTheSame = !((cpu->A ^ memVal) & 0b10000000);
    result = cpu->A + memVal + cpu->status.C;
    cpu->A = (result & 0xFF);

    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    cpu->status.C = result > 0xFF;
    cpu->status.V = areSignBitsTheSame && ((cpu->A ^ memVal) & NEGATIVEBITMASK);
}

void SBC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    Word result = 0x0000;

    switch (cpu->mode) {
        case Immediate:
            memVal = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            memVal = readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            memVal = readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            memVal = readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            memVal = readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    memVal = ~memVal;
    const int areSignBitsTheSame = !((cpu->A ^ memVal) & NEGATIVEBITMASK);
    result = cpu->A + memVal + cpu->status.C;
    cpu->A = (result & 0xFF);

    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    cpu->status.C = result > 0xFF;
    cpu->status.V = areSignBitsTheSame && ((cpu->A ^ memVal) & NEGATIVEBITMASK);
}

void CMP(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate:
            memVal = fetchByte(cycles, cpu, memory);
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            memVal = readByte(cycles, absXAddress, memory);
            break;

        case Absolute_Y:
            Word absYAddress = fetchWord(cycles, cpu, memory);
            absYAddress += cpu->Y;
            memVal = readByte(cycles, absYAddress, memory);
            break;

        case IndexedIndirect:
            Byte indirectXAddress = fetchByte(cycles, cpu, memory);
            indirectXAddress += cpu->X;
            indirectXAddress = wrapWord(indirectXAddress);
            *cycles -= 3;
            memVal = readByte(cycles, indirectXAddress, memory);
            break;

        case IndirectIndexed:
            Byte indirectYAddress = fetchByte(cycles, cpu, memory);
            indirectYAddress += cpu->Y;
            *cycles -= 2;
            memVal = readByte(cycles, indirectYAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.C = cpu->A >= memVal;
    cpu->status.Z = cpu->A == memVal;
    cpu->status.N = ((cpu->A - memVal) & NEGATIVEBITMASK) > 0;
}

void CPX(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate:
            memVal = fetchByte(cycles, cpu, memory);
            break;

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
    cpu->status.C = cpu->X >= memVal;
    cpu->status.Z = cpu->X == memVal;
    cpu->status.N = ((cpu->X - memVal) & NEGATIVEBITMASK) > 0;
}

void CPY(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate:
            memVal = fetchByte(cycles, cpu, memory);
            break;

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
    cpu->status.C = cpu->Y >= memVal;
    cpu->status.Z = cpu->Y == memVal;
    cpu->status.N = ((cpu->Y - memVal) & NEGATIVEBITMASK) > 0;
}

void INC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (memVal == 0);
    cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
}

void INX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->X += 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void INY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->Y += 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

void DEC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    switch (cpu->mode) {
        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            zpXAddress = wrapByte(zpXAddress);
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (memVal == 0);
    cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
}

void DEX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->X -= 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void DEY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->Y -= 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

void ASL(CPU* cpu, Memory* memory, u32* cycles) {
    int isAcc = False;
    Byte memVal = 0x00;
    Byte oldVal = 0x00;

    switch (cpu->mode) {
        case Accumulator:
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A << 1;
            *cycles -= 1;
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    if (isAcc) {
        cpu->status.Z = (cpu->A == 0);
        cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    } else {
        cpu->status.Z = (memVal == 0);
        cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
    }
    cpu->status.C = (oldVal & NEGATIVEBITMASK) > 0;
}

void LSR(CPU* cpu, Memory* memory, u32* cycles) {
    int isAcc = False;
    Byte memVal = 0x00;
    Byte oldVal = 0x00;

    switch (cpu->mode) {
        case Accumulator:
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A >> 1;
            *cycles -= 1;
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    if (isAcc) {
        cpu->status.Z = (cpu->A == 0);
        cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    } else {
        cpu->status.Z = (memVal == 0);
        cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
    }
    cpu->status.C = (oldVal & 0b00000001) > 0;
}

void ROL(CPU* cpu, Memory* memory, u32* cycles) {
    int isAcc = False;
    Byte memVal = 0x00;
    Byte oldVal = 0x00;
    const Byte newBit0 = cpu->status.C ? 0b00000001 : 0;

    switch (cpu->mode) {
        case Accumulator:
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A << 1;
            cpu->A |= newBit0;
            *cycles -= 1;
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    if (isAcc) {
        cpu->status.Z = (cpu->A == 0);
        cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    } else {
        cpu->status.Z = (memVal == 0);
        cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
    }
    cpu->status.C = (oldVal & NEGATIVEBITMASK) > 0;
}

void ROR(CPU* cpu, Memory* memory, u32* cycles) {
    int isAcc = False;
    Byte memVal = 0x00;
    int oldBit0 = False;

    switch (cpu->mode) {
        case Accumulator:
            isAcc = True;
            oldBit0 = (cpu->A & 0b00000001) > 0 ? True : False;
            cpu->A = cpu->A >> 1;
            if (cpu->status.C) {
                cpu->A |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            break;

        case ZeroPage:
            const Byte zpAddress = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | zpAddress, memory);
            oldBit0 = (memVal & 0b00000001) > 0 ? True : False;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpAddress, memory);
            break;

        case ZeroPage_X:
            Byte zpXAddress = fetchByte(cycles, cpu, memory);
            zpXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | zpXAddress, memory);
            oldBit0 = (memVal & 0b00000001) > 0 ? True : False;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | zpXAddress, memory);
            break;

        case Absolute:
            const Word absAddress = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, absAddress, memory);
            oldBit0 = (memVal & 0b00000001) > 0 ? True : False;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, absAddress, memory);
            break;

        case Absolute_X:
            Word absXAddress = fetchWord(cycles, cpu, memory);
            absXAddress += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, absXAddress, memory);
            oldBit0 = (memVal & 0b00000001) > 0 ? True : False;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, absXAddress, memory);
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
    if (isAcc) {
        cpu->status.Z = (cpu->A == 0);
        cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
    } else {
        cpu->status.Z = (memVal == 0);
        cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
    }
    cpu->status.C = oldBit0;
}

void JMP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Absolute:
            const Word jmpAddr = fetchWord(cycles, cpu, memory);
            cpu->PC = jmpAddr;
            break;

        case Indirect:
            const Word jmpIndAddr = fetchWord(cycles, cpu, memory);
            const Byte lowByte = readByte(cycles, jmpIndAddr, memory);
            const Byte highByte = readByte(cycles, jmpIndAddr + 1, memory);
            cpu->PC = (Word) (highByte << 8) | lowByte;
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
            cpu->SP -= 2;
            cpu->PC = subAddr;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void RTS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            const Word returnAddress = readWord(cycles, STACKSTART + cpu->SP, memory);
            cpu->SP += 2;
            cpu->PC = returnAddress + 1;
            *cycles -= 3;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BCC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.C) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BCS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.C) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BEQ(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.Z) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BMI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.N) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BNE(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.Z) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BPL(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.N) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BVC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.V) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BVS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative:
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.V) {
                cpu->PC += offset;
            }
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void CLC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.C = 0;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void CLD(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.D = 0;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void CLI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.I = 0;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void CLV(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.V = 0;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void SEC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.C = 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void SED(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.D = 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void SEI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            cpu->status.I = 1;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void BRK(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            writeWord(cycles, cpu->PC + 1, STACKSTART + cpu->SP, memory);
            cpu->SP -= 2;
            writeByte(cycles, cpu->status.value, STACKSTART + cpu->SP, memory);
            cpu->SP -= 1;
            cpu->PC = readWord(cycles, IRQVEC_LO, memory);
            cpu->status.B = True;
            //cpu->status.I = True;
            *cycles -= 1;
            break;

        default:
            printf("%s", NONMATCHCASE);
            break;
    }
}

void RTI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit:
            const Byte processorFlags = readByte(cycles, STACKSTART + cpu->SP, memory);
            cpu->status.value = processorFlags;
            cpu->SP += 1;
            const Byte pcValue = readWord(cycles, STACKSTART + cpu->SP, memory);
            cpu->PC = pcValue;
            cpu->SP += 2;
            *cycles -= 2;
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