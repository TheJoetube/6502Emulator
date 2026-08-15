#ifndef INC_6502EMULATOR_INSTRUCTIONFUNCTIONS_H
#define INC_6502EMULATOR_INSTRUCTIONFUNCTIONS_H

#include "constants.h"

typedef union {
    struct {
        //LDA
        Instruction LDA_IM;
        Instruction LDA_ZP;
        Instruction LDA_ZP_X;
        Instruction LDA_ABS;
        Instruction LDA_ABS_X;
        Instruction LDA_ABS_Y;
        Instruction LDA_IN_X;
        Instruction LDA_IN_Y;

        //LDX
        Instruction LDX_IM;
        Instruction LDX_ZP;
        Instruction LDX_ZP_Y;
        Instruction LDX_ABS;
        Instruction LDX_ABS_Y;

        //LDY
        Instruction LDY_IM;
        Instruction LDY_ZP;
        Instruction LDY_ZP_X;
        Instruction LDY_ABS;
        Instruction LDY_ABS_X;

        //STA
        Instruction STA_ZP;
        Instruction STA_ZP_X;
        Instruction STA_ABS;
        Instruction STA_ABS_X;
        Instruction STA_ABS_Y;
        Instruction STA_IN_X;
        Instruction STA_IN_Y;

        //STX
        Instruction STX_ZP;
        Instruction STX_ZP_Y;
        Instruction STX_ABS;

        //STY
        Instruction STY_ZP;
        Instruction STY_ZP_X;
        Instruction STY_ABS;

        //TAX
        Instruction TAX_IMP;

        //TAY
        Instruction TAY_IMP;

        //TSX
        Instruction TSX_IMP;

        //TXS
        Instruction TXS_IMP;

        //PHA
        Instruction PHA_IMP;

        //PHP
        Instruction PHP_IMP;

        //PLA
        Instruction PLA_IMP;

        //PLP
        Instruction PLP_IMP;

        //AND
        Instruction AND_IM;
        Instruction AND_ZP;
        Instruction AND_ZP_X;
        Instruction AND_ABS;
        Instruction AND_ABS_X;
        Instruction AND_ABS_Y;
        Instruction AND_IN_X;
        Instruction AND_IN_Y;

        //EOR
        Instruction EOR_IM;
        Instruction EOR_ZP;
        Instruction EOR_ZP_X;
        Instruction EOR_ABS;
        Instruction EOR_ABS_X;
        Instruction EOR_ABS_Y;
        Instruction EOR_IN_X;
        Instruction EOR_IN_Y;

        //ORA
        Instruction ORA_IM;
        Instruction ORA_ZP;
        Instruction ORA_ZP_X;
        Instruction ORA_ABS;
        Instruction ORA_ABS_X;
        Instruction ORA_ABS_Y;
        Instruction ORA_IN_X;
        Instruction ORA_IN_Y;

        //BIT
        Instruction BIT_ZP;
        Instruction BIT_ABS;

        //ADC
        Instruction ADC_IM;
        Instruction ADC_ZP;
        Instruction ADC_ZP_X;
        Instruction ADC_ABS;
        Instruction ADC_ABS_X;
        Instruction ADC_ABS_Y;
        Instruction ADC_IN_X;
        Instruction ADC_IN_Y;

        //JSR
        Instruction JSR_ABS;

        //NOP
        Instruction NOP_IMP;
    };
    Instruction instructions[];
}Instructions;

Instructions inst;

void initInstructions();
Instruction* getInstruction(Byte instruction, CPU* cpu);
Byte fetchByte(u32 *cycles, CPU *cpu, const Memory *memory);
Byte readByte(u32* cycles, Word address, const Memory* memory);
void writeByte(u32* cycles, Byte data, Word address, Memory* memory);

Word fetchWord(u32* cycles, CPU *cpu, const Memory *memory);
void writeWord(u32* cycles, Word data, Word address, Memory *memory);

Byte wrapByte(Word value);
Word wrapWord(Word value);

void LDA(CPU*, Memory*, u32* cycles);
void LDX(CPU*, Memory*, u32* cycles);
void LDY(CPU*, Memory*, u32* cycles);

void STA(CPU*, Memory*, u32* cycles);
void STX(CPU*, Memory*, u32* cycles);
void STY(CPU*, Memory*, u32* cycles);

void TAX(CPU*, Memory*, u32* cycles);
void TAY(CPU*, Memory*, u32* cycles);
void TXA(CPU*, Memory*, u32* cycles);
void TYA(CPU*, Memory*, u32* cycles);

void TSX(CPU*, Memory*, u32* cycles);
void TXS(CPU*, Memory*, u32* cycles);
void PHA(CPU*, Memory*, u32* cycles);
void PHP(CPU*, Memory*, u32* cycles);
void PLA(CPU*, Memory*, u32* cycles);
void PLP(CPU*, Memory*, u32* cycles);

void AND(CPU*, Memory*, u32* cycles);
void EOR(CPU*, Memory*, u32* cycles);
void ORA(CPU*, Memory*, u32* cycles);
void BIT(CPU*, Memory*, u32* cycles);

void ADC(CPU*, Memory*, u32* cycles);
void JSR(CPU*, Memory*, u32* cycles);
void NOP(CPU*, Memory*, u32* cycles);

#endif //INC_6502EMULATOR_INSTRUCTIONFUNCTIONS_H