#ifndef INC_6502EMULATOR_CONSTANTS_H
#define INC_6502EMULATOR_CONSTANTS_H

#define True 1
#define False 0
#define Byte_s signed char
#define Byte unsigned char
#define Word unsigned short
#define u32 unsigned int

#define MEMSIZE 65536
#define RESVEC_LO 0xFFFC
#define RESVEC_HI 0xFFFD
#define STACKSTART 0x0100
#define STACKEND 0x01FF
#define IRQVEC_HI 0xFFFE
#define IRQVEC_LO 0xFFFF

#define NEGATIVEBITMASK 0b10000000

#define NONMATCHCASE "Non matched Instruction (From Switch)"

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
        Byte Unused:1; //Unused Byte
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

typedef struct {
    u32 numCycles;
    int constRun;
    int clockSpeed;
} RunParams;

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