#ifndef INC_6502EMULATOR_CPUFUNCTIONS_H
#define INC_6502EMULATOR_CPUFUNCTIONS_H

#include "constants.h"

/**
 * Loads a memory struct with the contents of a file.
 * @param fileName Path to a bin file
 * @param memory A pointer to a Memory struct to fill
 */
void fillMemory(const char* fileName, Memory* memory);

/**
 * Sets the params struct to default values.
 * @param params A pointer to a Params struct
 */
void setDefaultParams(RunParams* params);

/**
 * Reset sequence for the CPU.
 * @param cpu A pointer to a CPU struct
 * @param memory A pointer to a Memory struct
 */
void reset(CPU* cpu, const Memory* memory);

/**
 * Prints information about the cpu.
 * @param cpu A pointer to a CPU struct
 */
void printStatus(const CPU* cpu);

/**
 * Executes instructions according to params and memory.
 * @param cpu A pointer to a CPU struct
 * @param memory A pointer to a Memory struct
 * @param params A pointer to a Params struct
 */
void execute(CPU* cpu, Memory* memory, RunParams params);

#endif //INC_6502EMULATOR_CPUFUNCTIONS_H