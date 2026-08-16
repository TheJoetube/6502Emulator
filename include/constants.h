#ifndef INC_6502EMULATOR_CONSTANTS_H
#define INC_6502EMULATOR_CONSTANTS_H

#define True 1
#define False 0
#define Byte unsigned char
#define Word unsigned short
#define u32 unsigned int

#define MEMSIZE 65536
#define RESVEC_LO 0xFFFC
#define RESVEC_HI 0xFFFD
#define STACKSTART 0x0100
#define STACKEND 0x01FF

#define NONMATCHCASE "Wtf"

typedef enum {
    Implicit,
    Accumulator,
    Immediate,
    ZeroPage,
    ZeroPage_X,
    ZeroPage_Y,
    Relative,
    Absolute,
    Absolute_X,
    Absolute_Y,
    Indirect,
    IndexedIndirect,
    IndirectIndexed,
} Mode;

typedef union {
    struct {
        Byte C:1; //Carry Flag
        Byte Z:1; //Zero Flag
        Byte I:1; //Interrupt Disable
        Byte D:1; //Decimal Mode
        Byte B:1; //Break Command
        Byte V:1; //Overflow Flag
        Byte N:1; //Negative Flag
    };
    Byte value;
} Status;

typedef struct {
    Word PC; //program counter
    Byte SP; //stack pointer
    Byte A; //registers
    Byte X;
    Byte Y;

    Status status;
    Mode mode;
} CPU;

typedef union {
    Byte data[MEMSIZE];
} Memory;

typedef struct {
    Byte opcode;
    int cycles;
    Mode mode;
    void (*execute)(CPU*, Memory*, u32* cycles);
} Instruction;

#endif //INC_6502EMULATOR_CONSTANTS_H