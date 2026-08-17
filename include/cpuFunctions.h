#ifndef INC_6502EMULATOR_CPUFUNCTIONS_H
#define INC_6502EMULATOR_CPUFUNCTIONS_H

#include "constants.h"

void setDefaultParams(RunParams* params);
void reset(CPU* cpu, const Memory* memory);
void printStatus(const CPU* cpu);
void execute(CPU* cpu, Memory* memory, RunParams params);

#endif //INC_6502EMULATOR_CPUFUNCTIONS_H