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

Word fetchWord(u32* cycles, CPU *cpu, const Memory *memory);
void writeWord(u32* cycles, Word data, Word address, Memory *memory);

void LDA(CPU*, Memory*, u32* cycles);
void LDX(CPU*, Memory*, u32* cycles);
void LDY(CPU*, Memory*, u32* cycles);
void ADC(CPU*, Memory*, u32* cycles);
void JSR(CPU*, Memory*, u32* cycles);
void NOP(CPU*, Memory*, u32* cycles);

#endif //INC_6502EMULATOR_INSTRUCTIONFUNCTIONS_H