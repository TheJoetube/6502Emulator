#ifndef INC_6502EMULATOR_CPUFUNCTIONS_H
#define INC_6502EMULATOR_CPUFUNCTIONS_H

#include "constants.h"

void reset(CPU* cpu, Memory* memory);
void printStatus(const CPU* cpu);
void execute(CPU* cpu, Memory* memory, u32 cycles);

#endif //INC_6502EMULATOR_CPUFUNCTIONS_H