#include "unity.h"
#include "constants.h"
#include "cpuFunctions.h"
#include "instructionFunctions.h"

Memory memory;
CPU cpu;
RunParams params;

void setUp(void)
{
    memory.data[RESVEC_LO] = 0x00;
    memory.data[RESVEC_HI] = 0x00;

    reset(&cpu, &memory);

    setDefaultParams(&params);
}

void tearDown(void)
{
}

void test_tax_imp(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.X = 0x00;

    memory.data[0] = inst.TAX_IMP.opcode;

    params.numCycles = inst.TAX_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

void test_tay_imp(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.Y = 0x00;

    memory.data[0] = inst.TAY_IMP.opcode;

    params.numCycles = inst.TAY_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}

void test_txa_imp(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;
    cpu.A = 0x00;

    memory.data[0] = inst.TXA_IMP.opcode;

    params.numCycles = inst.TXA_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_tya_imp(void) {
    const Byte checkValue = 0x10;

    cpu.Y = checkValue;
    cpu.A = 0x00;

    memory.data[0] = inst.TYA_IMP.opcode;

    params.numCycles = inst.TYA_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_tax_imp);
    RUN_TEST(test_tay_imp);
    RUN_TEST(test_txa_imp);
    RUN_TEST(test_tya_imp);

    return UNITY_END();
}