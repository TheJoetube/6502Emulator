#include "unity.h"
#include "constants.h"
#include "cpuFunctions.h"
#include "instructionFunctions.h"

Memory memory;
CPU cpu;
RunParams params;

void setUp(void)
{
    initInstructions();

    memory.data[RESVEC_LO] = 0x00;
    memory.data[RESVEC_HI] = 0x00;

    reset(&cpu, &memory);

    setDefaultParams(&params);
}

void tearDown(void)
{
}

void test_sty_zeropage(void) {
    const Byte checkValue = 0x10;

    cpu.Y = checkValue;

    memory.data[0] = inst.STY_ZP.opcode;
    memory.data[1] = 0x0F;

    params.numCycles = inst.STY_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x000F]);
}

void test_sty_zeropage_x(void) {
    const Byte checkValue = 0x10;

    cpu.Y = checkValue;
    cpu.X = 0x01;

    memory.data[0] = inst.STY_ZP_X.opcode;
    memory.data[1] = 0x0F;

    params.numCycles = inst.STY_ZP_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x0010]);
}

void test_sty_absolute(void) {
    const Byte checkValue = 0x10;

    cpu.Y = checkValue;

    memory.data[0] = inst.STY_ABS.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    params.numCycles = inst.STY_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x1002]);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_sty_zeropage);
    RUN_TEST(test_sty_zeropage_x);
    RUN_TEST(test_sty_absolute);

    return UNITY_END();
}