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

        //TXA
        Instruction TXA_IMP;

        //TYA
        Instruction TYA_IMP;

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

        //SBC
        Instruction SBC_IM;
        Instruction SBC_ZP;
        Instruction SBC_ZP_X;
        Instruction SBC_ABS;
        Instruction SBC_ABS_X;
        Instruction SBC_ABS_Y;
        Instruction SBC_IN_X;
        Instruction SBC_IN_Y;

        //CMP
        Instruction CMP_IM;
        Instruction CMP_ZP;
        Instruction CMP_ZP_X;
        Instruction CMP_ABS;
        Instruction CMP_ABS_X;
        Instruction CMP_ABS_Y;
        Instruction CMP_IN_X;
        Instruction CMP_IN_Y;

        //CPX
        Instruction CPX_IM;
        Instruction CPX_ZP;
        Instruction CPX_ABS;

        //CPY
        Instruction CPY_IM;
        Instruction CPY_ZP;
        Instruction CPY_ABS;

        //INC
        Instruction INC_ZP;
        Instruction INC_ZP_X;
        Instruction INC_ABS;
        Instruction INC_ABS_X;

        //INX
        Instruction INX_IMP;

        //INY
        Instruction INY_IMP;

        //DEC
        Instruction DEC_ZP;
        Instruction DEC_ZP_X;
        Instruction DEC_ABS;
        Instruction DEC_ABS_X;

        //DEX
        Instruction DEX_IMP;

        //DEY
        Instruction DEY_IMP;

        //ASL
        Instruction ASL_ACC;
        Instruction ASL_ZP;
        Instruction ASL_ZP_X;
        Instruction ASL_ABS;
        Instruction ASL_ABS_X;

        //LSR
        Instruction LSR_ACC;
        Instruction LSR_ZP;
        Instruction LSR_ZP_X;
        Instruction LSR_ABS;
        Instruction LSR_ABS_X;

        //ROL
        Instruction ROL_ACC;
        Instruction ROL_ZP;
        Instruction ROL_ZP_X;
        Instruction ROL_ABS;
        Instruction ROL_ABS_X;

        //ROR
        Instruction ROR_ACC;
        Instruction ROR_ZP;
        Instruction ROR_ZP_X;
        Instruction ROR_ABS;
        Instruction ROR_ABS_X;

        //JMP
        Instruction JMP_ABS;
        Instruction JMP_IND;

        //JSR
        Instruction JSR_ABS;

        //RTS
        Instruction RTS_IMP;

        //BCC
        Instruction BCC_REL;

        //BCS
        Instruction BCS_REL;

        //BEQ
        Instruction BEQ_REL;

        //BMI
        Instruction BMI_REL;

        //BNE
        Instruction BNE_REL;

        //BPL
        Instruction BPL_REL;

        //BVC
        Instruction BVC_REL;

        //BVS
        Instruction BVS_REL;

        //CLC
        Instruction CLC_IMP;

        //CLD
        Instruction CLD_IMP;

        //CLI
        Instruction CLI_IMP;

        //CLV
        Instruction CLV_IMP;

        //SEC
        Instruction SEC_IMP;

        //SED
        Instruction SED_IMP;

        //SEI
        Instruction SEI_IMP;

        //BRK
        Instruction BRK_IMP;

        //RTI
        Instruction RTI_IMP;

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
Word readWord(u32* cycles, Word address, const Memory* memory);
void writeWord(u32* cycles, Word data, Word address, Memory *memory);

Byte wrapByte(Word value);
Word wrapWord(Word value);

//--Load/Store-Operations--//
void LDA(CPU* cpu, Memory* memory, u32* cycles);
void LDX(CPU* cpu, Memory* memory, u32* cycles);
void LDY(CPU* cpu, Memory* memory, u32* cycles);
void STA(CPU* cpu, Memory* memory, u32* cycles);
void STX(CPU* cpu, Memory* memory, u32* cycles);
void STY(CPU* cpu, Memory* memory, u32* cycles);

//--Register-Transfers--//
void TAX(CPU* cpu, Memory* memory, u32* cycles);
void TAY(CPU* cpu, Memory* memory, u32* cycles);
void TXA(CPU* cpu, Memory*, u32* cycles);
void TYA(CPU* cpu, Memory* memory, u32* cycles);

//--Stack-Operations--//
void TSX(CPU* cpu, Memory* memory, u32* cycles);
void TXS(CPU* cpu, Memory* memory, u32* cycles);
void PHA(CPU* cpu, Memory* memory, u32* cycles);
void PHP(CPU* cpu, Memory* memory, u32* cycles);
void PLA(CPU* cpu, Memory* memory, u32* cycles);
void PLP(CPU* cpu, Memory* memory, u32* cycles);

//--Logical--//
void AND(CPU* cpu, Memory* memory, u32* cycles);
void EOR(CPU* cpu, Memory* memory, u32* cycles);
void ORA(CPU* cpu, Memory* memory, u32* cycles);
void BIT(CPU* cpu, Memory* memory, u32* cycles);

//--Arithmetic--//
void ADC(CPU* cpu, Memory* memory, u32* cycles);
void SBC(CPU* cpu, Memory* memory, u32* cycles);
void CMP(CPU* cpu, Memory* memory, u32* cycles);
void CPX(CPU* cpu, Memory* memory, u32* cycles);
void CPY(CPU* cpu, Memory* memory, u32* cycles);

//--Increments-&-Decrements--//
void INC(CPU* cpu, Memory* memory, u32* cycles);
void INX(CPU* cpu, Memory* memory, u32* cycles);
void INY(CPU* cpu, Memory* memory, u32* cycles);
void DEC(CPU* cpu, Memory* memory, u32* cycles);
void DEX(CPU* cpu, Memory* memory, u32* cycles);
void DEY(CPU* cpu, Memory* memory, u32* cycles);

//--Shifts--//
void ASL(CPU* cpu, Memory* memory, u32* cycles);
void LSR(CPU* cpu, Memory* memory, u32* cycles);
void ROL(CPU* cpu, Memory* memory, u32* cycles);
void ROR(CPU* cpu, Memory* memory, u32* cycles);

//--Jumps-&-Calls--//
void JMP(CPU* cpu, Memory* memory, u32* cycles);
void JSR(CPU* cpu, Memory* memory, u32* cycles);
void RTS(CPU* cpu, Memory* memory, u32* cycles);

//--Branches--//
void BCC(CPU* cpu, Memory* memory, u32* cycles);
void BCS(CPU* cpu, Memory* memory, u32* cycles);
void BEQ(CPU* cpu, Memory* memory, u32* cycles);
void BMI(CPU* cpu, Memory* memory, u32* cycles);
void BNE(CPU* cpu, Memory* memory, u32* cycles);
void BPL(CPU* cpu, Memory* memory, u32* cycles);
void BVC(CPU* cpu, Memory* memory, u32* cycles);
void BVS(CPU* cpu, Memory* memory, u32* cycles);

//--Status-Flag-Changes--//
void CLC(CPU* cpu, Memory* memory, u32* cycles);
void CLD(CPU* cpu, Memory* memory, u32* cycles);
void CLI(CPU* cpu, Memory* memory, u32* cycles);
void CLV(CPU* cpu, Memory* memory, u32* cycles);
void SEC(CPU* cpu, Memory* memory, u32* cycles);
void SED(CPU* cpu, Memory* memory, u32* cycles);
void SEI(CPU* cpu, Memory* memory, u32* cycles);

//System-Functions--//
void BRK(CPU* cpu, Memory* memory, u32* cycles);
void NOP(CPU* cpu, Memory* memory, u32* cycles);
void RTI(CPU* cpu, Memory* memory, u32* cycles);

#endif //INC_6502EMULATOR_INSTRUCTIONFUNCTIONS_H