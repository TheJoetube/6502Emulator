#include "../include/instructionFunctions.h"
#include "../include/constants.h"
#include <stdio.h>

const char* instNames[256] = {
    // 0x0x
    [0x00] = "BRK_IMP",
    [0x01] = "ORA_IND_X",
    [0x05] = "ORA_ZP",
    [0x06] = "ASL_ZP",
    [0x08] = "PHP_IMP",
    [0x09] = "ORA_IM",
    [0x0A] = "ASL_ACC",
    [0x0D] = "ORA_ABS",
    [0x0E] = "ASL_ABS",

    // 0x1x
    [0x10] = "BPL_REL",
    [0x11] = "ORA_IND_Y",
    [0x15] = "ORA_ZP_X",
    [0x16] = "ASL_ZP_X",
    [0x18] = "CLC_IMP",
    [0x19] = "ORA_ABS_Y",
    [0x1D] = "ORA_ABS_X",
    [0x1E] = "ASL_ABS_X",

    // 0x2x
    [0x20] = "JSR_ABS",
    [0x21] = "AND_IND_X",
    [0x24] = "BIT_ZP",
    [0x25] = "AND_ZP",
    [0x26] = "ROL_ZP",
    [0x28] = "PLP_IMP",
    [0x29] = "AND_IM",
    [0x2A] = "ROL_ACC",
    [0x2C] = "BIT_ABS",
    [0x2D] = "AND_ABS",
    [0x2E] = "ROL_ABS",

    // 0x3x
    [0x30] = "BMI_REL",
    [0x31] = "AND_IND_Y",
    [0x35] = "AND_ZP_X",
    [0x36] = "ROL_ZP_X",
    [0x38] = "SEC_IMP",
    [0x39] = "AND_ABS_Y",
    [0x3D] = "AND_ABS_X",
    [0x3E] = "ROL_ABS_X",

    // 0x4x
    [0x40] = "RTI_IMP",
    [0x41] = "EOR_IND_X",
    [0x45] = "EOR_ZP",
    [0x46] = "LSR_ZP",
    [0x48] = "PHA_IMP",
    [0x49] = "EOR_IM",
    [0x4A] = "LSR_ACC",
    [0x4C] = "JMP_ABS",
    [0x4D] = "EOR_ABS",
    [0x4E] = "LSR_ABS",

    // 0x5x
    [0x50] = "BVC_REL",
    [0x51] = "EOR_IND_Y",
    [0x55] = "EOR_ZP_X",
    [0x56] = "LSR_ZP_X",
    [0x58] = "CLI_IMP",
    [0x59] = "EOR_ABS_Y",
    [0x5D] = "EOR_ABS_X",
    [0x5E] = "LSR_ABS_X",

    // 0x6x
    [0x60] = "RTS_IMP",
    [0x61] = "ADC_IND_X",
    [0x65] = "ADC_ZP",
    [0x66] = "ROR_ZP",
    [0x68] = "PLA_IMP",
    [0x69] = "ADC_IM",
    [0x6A] = "ROR_ACC",
    [0x6C] = "JMP_IND",
    [0x6D] = "ADC_ABS",
    [0x6E] = "ROR_ABS",

    // 0x7x
    [0x70] = "BVS_REL",
    [0x71] = "ADC_IND_Y",
    [0x75] = "ADC_ZP_X",
    [0x76] = "ROR_ZP_X",
    [0x78] = "SEI_IMP",
    [0x79] = "ADC_ABS_Y",
    [0x7D] = "ADC_ABS_X",
    [0x7E] = "ROR_ABS_X",

    // 0x8x
    [0x81] = "STA_IND_X",
    [0x84] = "STY_ZP",
    [0x85] = "STA_ZP",
    [0x86] = "STX_ZP",
    [0x88] = "DEY_IMP",
    [0x8A] = "TXA_IMP",
    [0x8C] = "STY_ABS",
    [0x8D] = "STA_ABS",
    [0x8E] = "STX_ABS",

    // 0x9x
    [0x90] = "BCC_REL",
    [0x91] = "STA_IND_Y",
    [0x94] = "STY_ZP_X",
    [0x95] = "STA_ZP_X",
    [0x96] = "STX_ZP_Y",
    [0x98] = "TYA_IMP",
    [0x99] = "STA_ABS_Y",
    [0x9A] = "TXS_IMP",
    [0x9D] = "STA_ABS_X",

    // 0xAx
    [0xA0] = "LDY_IM",
    [0xA1] = "LDA_IND_X",
    [0xA2] = "LDX_IM",
    [0xA4] = "LDY_ZP",
    [0xA5] = "LDA_ZP",
    [0xA6] = "LDX_ZP",
    [0xA8] = "TAY_IMP",
    [0xA9] = "LDA_IM",
    [0xAA] = "TAX_IMP",
    [0xAC] = "LDY_ABS",
    [0xAD] = "LDA_ABS",
    [0xAE] = "LDX_ABS",

    // 0xBx
    [0xB0] = "BCS_REL",
    [0xB1] = "LDA_IND_Y",
    [0xB4] = "LDY_ZP_X",
    [0xB5] = "LDA_ZP_X",
    [0xB6] = "LDX_ZP_Y",
    [0xB8] = "CLV_IMP",
    [0xB9] = "LDA_ABS_Y",
    [0xBA] = "TSX_IMP",
    [0xBC] = "LDY_ABS_X",
    [0xBD] = "LDA_ABS_X",
    [0xBE] = "LDX_ABS_Y",

    // 0xCx
    [0xC0] = "CPY_IM",
    [0xC1] = "CMP_IND_X",
    [0xC4] = "CPY_ZP",
    [0xC5] = "CMP_ZP",
    [0xC6] = "DEC_ZP",
    [0xC8] = "INY_IMP",
    [0xC9] = "CMP_IM",
    [0xCA] = "DEX_IMP",
    [0xCC] = "CPY_ABS",
    [0xCD] = "CMP_ABS",
    [0xCE] = "DEC_ABS",

    // 0xDx
    [0xD0] = "BNE_REL",
    [0xD1] = "CMP_IND_Y",
    [0xD5] = "CMP_ZP_X",
    [0xD6] = "DEC_ZP_X",
    [0xD8] = "CLD_IMP",
    [0xD9] = "CMP_ABS_Y",
    [0xDD] = "CMP_ABS_X",
    [0xDE] = "DEC_ABS_X",

    // 0xEx
    [0xE0] = "CPX_IM",
    [0xE1] = "SBC_IND_X",
    [0xE4] = "CPX_ZP",
    [0xE5] = "SBC_ZP",
    [0xE6] = "INC_ZP",
    [0xE8] = "INX_IMP",
    [0xE9] = "SBC_IM",
    [0xEA] = "NOP_IMP",
    [0xEC] = "CPX_ABS",
    [0xED] = "SBC_ABS",
    [0xEE] = "INC_ABS",

    // 0xFx
    [0xF0] = "BEQ_REL",
    [0xF1] = "SBC_IND_Y",
    [0xF5] = "SBC_ZP_X",
    [0xF6] = "INC_ZP_X",
    [0xF8] = "SED_IMP",
    [0xF9] = "SBC_ABS_Y",
    [0xFD] = "SBC_ABS_X",
    [0xFE] = "INC_ABS_X"
};

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
    inst.DEX_IMP = (Instruction){0xCA,2,Implicit,DEX};

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
    inst.BEQ_REL = (Instruction){0xF0,2,Relative,BEQ};

    //BMI
    inst.BMI_REL = (Instruction){0x30,2,Relative,BMI};

    //BNE
    inst.BNE_REL = (Instruction){0xD0,2,Relative,BNE};

    //BPL
    inst.BPL_REL = (Instruction){0x10,2,Relative,BPL};

    //BVC
    inst.BVC_REL = (Instruction){0x50,2,Relative,BVC};

    //BVS
    inst.BVS_REL = (Instruction){0x70,2,Relative,BVS};

    //CLC
    inst.CLC_IMP = (Instruction){0x18,2,Implicit,CLC};

    //CLD
    inst.CLD_IMP = (Instruction){0xD8,2,Implicit,CLD};

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
    const Byte loByte = readByte(cycles, address, memory);
    const Byte hiByte = readByte(cycles, address + 1, memory);
    return loByte | (hiByte << 8);
}

void writeWord(u32* cycles, const Word data, const Word address, Memory *memory) {
    memory->data[address] = data & 0xFF;
    memory->data[address+1] = (data >> 8);
    *cycles -= 2;
}

void pushWordToStack(u32* cycles, CPU* cpu, const Word data, Memory *memory) {
    writeByte(cycles, data >> 8, STACKSTART + cpu->SP, memory);
    cpu->SP -= 1;

    writeByte(cycles, data & 0xFF, STACKSTART + cpu->SP, memory);
    cpu->SP -= 1;
}

void pushByteToStack(u32* cycles, CPU* cpu, const Byte data, Memory *memory) {
    memory->data[STACKSTART + cpu->SP] = data;
    *cycles -= 1;
    cpu->SP -= 1;
    *cycles -= 1;
}

Byte popByteFromStack(u32* cycles, CPU* cpu, const Memory *memory) {
    cpu->SP += 1;
    *cycles -= 1;
    const Byte value = memory->data[STACKSTART + cpu->SP];
    *cycles -= 1;
    return value;
}

Word popWordFromStack(u32* cycles, CPU* cpu, const Memory* memory) {
    const Byte low = popByteFromStack(cycles, cpu, memory);
    const Byte high = popByteFromStack(cycles, cpu, memory);
    return ((high << 8) | low);
}

Word readZeroPageAddressX(u32* cycles, const CPU* cpu, Byte address, const Memory* memory) {
    address += cpu->X;
    *cycles -= 1;
    address &= 0xFF;
    const Byte low = readByte(cycles, address, memory);
    const Byte high = readByte(cycles, (address + 1) & 0xFF, memory);
    return (high << 8) | low;
}

Word readZeroPageAddressY(u32* cycles, const CPU* cpu, const Byte address, const Memory* memory) {
    const Byte low = readByte(cycles, address, memory);
    const Byte high = readByte(cycles, (address + 1) & 0xFF, memory);
    Word finalAddr = (high << 8) | low;
    crossedPageBoundary(cycles, finalAddr, finalAddr + cpu->Y);
    finalAddr += cpu->Y;
    return finalAddr;
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

void crossedPageBoundary(u32* cycles, const Word address1, const Word address2) {
    const Byte CrossedPageBoundary = (address1 ^ address2) >> 8;
    if ( CrossedPageBoundary )
    {
        *cycles -= 1;
    }

}

void crossedPageBoundaryPC(u32* cycles, const Word pc1, const Word pc2) {
    const Byte PageChanged = (pc2 >> 8) != (pc1 >> 8);
    if ( PageChanged )
    {
        *cycles -= 1;
    }
}

void LDA(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->A = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            cpu->A = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->A = readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            cpu->A = readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            cpu->A = readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A = readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A = readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void LDX(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->X = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->X = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_Y: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->Y;
            *cycles -= 1;
            cpu->X = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->X = readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            cpu->X = readByte(cycles, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void LDY(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->Y = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->Y = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            cpu->Y = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->Y = readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            cpu->Y = readByte(cycles, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

void STA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->A, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->A, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->A, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->A, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->Y;
            *cycles -= 1;
            writeByte(cycles, cpu->A, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            const Word addressX = readZeroPageAddressX(cycles, cpu, address, memory);
            writeByte(cycles, cpu->A, addressX, memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            *cycles -= 1;
            const Word addressY = readZeroPageAddressY(cycles, cpu, address, memory);
            writeByte(cycles, cpu->A, addressY, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void STX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->X, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_Y: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->Y;
            *cycles -= 1;
            writeByte(cycles, cpu->X, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->X, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void STY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            writeByte(cycles, cpu->Y, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            writeByte(cycles, cpu->Y, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            writeByte(cycles, cpu->Y, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void TAX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->X = cpu->A;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void TAY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->Y = cpu->A;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

void TXA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->A = cpu->X;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void TYA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->A = cpu->Y;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void TSX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->X = cpu->SP;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void TXS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->SP = cpu->X;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void PHA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            pushByteToStack(cycles, cpu, cpu->A, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void PHP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            const Byte psStack = cpu->status.value | 0b000010000 | 0b000100000;
            pushByteToStack(cycles, cpu, psStack, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void PLA(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            const Byte stackByte = popByteFromStack(cycles, cpu, memory);
            cpu->A = stackByte;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void PLP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            const Byte stackByte = popByteFromStack(cycles, cpu, memory);
            cpu->status.value = stackByte;
            //delay I polling by 1 instruction?
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

//100% Done
void AND(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->A &= fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A &= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            cpu->A &= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->A &= readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            cpu->A &= readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            cpu->A &= readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A &= readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A &= readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void EOR(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->A ^= fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            cpu->A ^= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            cpu->A ^= readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            cpu->A ^= readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A ^= readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void ORA(CPU* cpu, Memory* memory, u32* cycles) {
    switch(cpu->mode) {
        case Immediate: {
            cpu->A |= fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A |= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            cpu->A |= readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            cpu->A |= readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            cpu->A |= readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            cpu->A |= readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A |= readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            cpu->A |= readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->A == 0);
    cpu->status.N = (cpu->A & NEGATIVEBITMASK) > 0;
}

void BIT(CPU* cpu, Memory* memory, u32* cycles) {
    Byte result = 0x00;
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    result = cpu->A & memVal;

    cpu->status.Z = (result == 0);
    cpu->status.V = (0b01000000 & memVal) > 0;
    cpu->status.N = (NEGATIVEBITMASK & memVal) > 0;
}

void ADC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate: {
            memVal = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    const Byte oldA = cpu->A;
    const Byte carryIn = cpu->status.C ? 1 : 0;

    /*
     * Always calculate the binary result first.
     * NMOS 6502 uses this for V, and its decimal-mode N/Z behavior
     * is based on this binary intermediate result.
     */
    const Word binaryResult = (Word)oldA + (Word)memVal + carryIn;

    const Byte binaryByte = (Byte)binaryResult;

    cpu->status.Z = (binaryByte == 0);
    cpu->status.N = (binaryByte & 0x80) != 0;

    cpu->status.V = ((~(oldA ^ memVal) & (oldA ^ binaryByte)) & 0x80) != 0;

    if (!cpu->status.D) {
        cpu->A = binaryByte;
        cpu->status.C = binaryResult > 0xFF;
    } else {
        /*
         * Decimal/BCD adjustment.
         */
        int low  = (oldA & 0x0F) + (memVal & 0x0F) + carryIn;
        int high = (oldA >> 4) + (memVal >> 4);

        if (low > 9) {
            low += 6;
            high++;
        }

        cpu->status.C = high > 9;

        if (high > 9) {
            high += 6;
        }

        cpu->A = (Byte)((high << 4) | (low & 0x0F));
    }
}

void SBC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate: {
            memVal = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    const Byte oldA = cpu->A;
    const Byte carryIn = cpu->status.C ? 1 : 0;

    /*
     * Binary subtraction:
     *
     * A - M - (1-C)
     *
     * equivalently:
     *
     * A + (~M) + C
     */
    const Word binaryResult = (Word)oldA + (Word)(memVal ^ 0xFF) + carryIn;

    const Byte binaryByte = (Byte)binaryResult;

    cpu->status.Z = (binaryByte == 0);
    cpu->status.N = (binaryByte & 0x80) != 0;

    cpu->status.V = ((oldA ^ binaryByte) & (oldA ^ memVal) & 0x80) != 0;

    if (!cpu->status.D) {
        cpu->A = binaryByte;
        cpu->status.C = (binaryResult & 0x100) != 0;
    } else {
        /*
         * Decimal/BCD subtraction.
         */
        int low =
            (oldA & 0x0F) -
            (memVal & 0x0F) -
            (carryIn ? 0 : 1);

        int high =
            (oldA >> 4) -
            (memVal >> 4);

        if (low < 0) {
            low -= 6;
            high--;
        }

        if (high < 0) {
            high -= 6;
            cpu->status.C = 0;
        } else {
            cpu->status.C = 1;
        }

        cpu->A = (Byte)(((high & 0x0F) << 4) | (low & 0x0F));
    }
}

void CMP(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate: {
            memVal = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->X);
            address += cpu->X;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case Absolute_Y: {
            Word address = fetchWord(cycles, cpu, memory);
            crossedPageBoundary(cycles, address, address + cpu->Y);
            address += cpu->Y;
            memVal = readByte(cycles, address, memory);
            break;
        }

        case IndexedIndirect: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressX(cycles, cpu, address, memory), memory);
            break;
        }

        case IndirectIndexed: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, readZeroPageAddressY(cycles, cpu, address, memory), memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.C = cpu->A >= memVal;
    cpu->status.Z = cpu->A == memVal;
    cpu->status.N = ((cpu->A - memVal) & NEGATIVEBITMASK) > 0;
}

void CPX(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate: {
            memVal = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.C = cpu->X >= memVal;
    cpu->status.Z = cpu->X == memVal;
    cpu->status.N = ((cpu->X - memVal) & NEGATIVEBITMASK) > 0;
}

void CPY(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;

    switch (cpu->mode) {
        case Immediate: {
            memVal = fetchByte(cycles, cpu, memory);
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.C = cpu->Y >= memVal;
    cpu->status.Z = cpu->Y == memVal;
    cpu->status.N = ((cpu->Y - memVal) & NEGATIVEBITMASK) > 0;
}

void INC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            memVal += 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (memVal == 0);
    cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
}

void INX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->X += 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void INY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->Y += 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

void DEC(CPU* cpu, Memory* memory, u32* cycles) {
    Byte memVal = 0x00;
    switch (cpu->mode) {
        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            memVal -= 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (memVal == 0);
    cpu->status.N = (memVal & NEGATIVEBITMASK) > 0;
}

void DEX(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->X -= 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->X == 0);
    cpu->status.N = (cpu->X & NEGATIVEBITMASK) > 0;
}

void DEY(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->Y -= 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
    cpu->status.Z = (cpu->Y == 0);
    cpu->status.N = (cpu->Y & NEGATIVEBITMASK) > 0;
}

//100% Done
void ASL(CPU* cpu, Memory* memory, u32* cycles) {
    int isAcc = False;
    Byte memVal = 0x00;
    Byte oldVal = 0x00;

    switch (cpu->mode) {
        case Accumulator: {
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A << 1;
            *cycles -= 1;
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
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
        case Accumulator: {
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A >> 1;
            *cycles -= 1;
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal >> 1;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
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
        case Accumulator: {
            isAcc = True;
            oldVal = cpu->A;
            cpu->A = cpu->A << 1;
            cpu->A |= newBit0;
            *cycles -= 1;
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            oldVal = memVal;
            memVal = memVal << 1;
            memVal |= newBit0;
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
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
        case Accumulator: {
            isAcc = True;
            oldBit0 = (cpu->A & 0b00000001) > 0;
            cpu->A = cpu->A >> 1;
            if (cpu->status.C) {
                cpu->A |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            break;
        }

        case ZeroPage: {
            const Byte address = fetchByte(cycles, cpu, memory);
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldBit0 = (memVal & 0b00000001) > 0;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case ZeroPage_X: {
            Byte address = fetchByte(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, 0x0000 | address, memory);
            oldBit0 = (memVal & 0b00000001) > 0;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, 0x0000 | address, memory);
            break;
        }

        case Absolute: {
            const Word address = fetchWord(cycles, cpu, memory);
            memVal = readByte(cycles, address, memory);
            oldBit0 = (memVal & 0b00000001) > 0;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        case Absolute_X: {
            Word address = fetchWord(cycles, cpu, memory);
            address += cpu->X;
            *cycles -= 1;
            memVal = readByte(cycles, address, memory);
            oldBit0 = (memVal & 0b00000001) > 0;
            memVal = memVal >> 1;
            if (cpu->status.C) {
                memVal |= NEGATIVEBITMASK;
            }
            *cycles -= 1;
            writeByte(cycles, memVal, address, memory);
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
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
        case Absolute: {
            const Word jmpAddr = fetchWord(cycles, cpu, memory);
            cpu->PC = jmpAddr;
            break;
        }

        case Indirect: {
            const Word jmpIndAddr = fetchWord(cycles, cpu, memory);
            const Word address = readWord(cycles, jmpIndAddr, memory);
            cpu->PC = address;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void JSR(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Absolute: {
            const Word subAddr = fetchWord(cycles, cpu, memory);
            pushWordToStack(cycles, cpu, cpu->PC - 1, memory);
            cpu->PC = subAddr;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void RTS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            const Word returnAddress = popWordFromStack(cycles, cpu, memory);
            cpu->PC = returnAddress + 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BCC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.C) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BCS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.C) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BEQ(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.Z) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BMI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.N) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BNE(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.Z) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BPL(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.N) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BVC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (!cpu->status.V) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BVS(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Relative: {
            const Byte_s offset = (Byte_s) fetchByte(cycles, cpu, memory);
            if (cpu->status.V) {
                crossedPageBoundaryPC(cycles, cpu->PC, cpu->PC + offset);
                cpu->PC += offset;
                *cycles -= 1;
            }
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void CLC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.C = 0;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void CLD(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.D = 0;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void CLI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.I = 0;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void CLV(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.V = 0;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void SEC(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.C = 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void SED(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.D = 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void SEI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            cpu->status.I = 1;
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void BRK(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            pushWordToStack(cycles, cpu, cpu->PC + 1, memory);
            const Byte psStack = cpu->status.value | 0b00010000 | 0b00100000;
            pushByteToStack(cycles, cpu, psStack, memory);
            cpu->PC = readWord(cycles, IRQVEC_HI, memory);
            cpu->status.I = True;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void RTI(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            const Byte processorFlags = popByteFromStack(cycles, cpu, memory);
            cpu->status.value = processorFlags;
            const Word pcValue = popWordFromStack(cycles, cpu, memory);
            cpu->PC = pcValue;
            //very bad bandaid fix but what can you do
            *cycles += 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}

void NOP(CPU* cpu, Memory* memory, u32* cycles) {
    switch (cpu->mode) {
        case Implicit: {
            *cycles -= 1;
            break;
        }

        default: {
            printf("%s", NONMATCHCASE);
            break;
        }
    }
}