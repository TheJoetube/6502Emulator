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

void test_stx_zeropage(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;

    memory.data[0] = inst.STX_ZP.opcode;
    memory.data[1] = 0x0F;

    params.numCycles = inst.STX_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x000F]);
}

void test_stx_zeropage_y(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;
    cpu.Y = 0x01;

    memory.data[0] = inst.STX_ZP_Y.opcode;
    memory.data[1] = 0x0F;

    params.numCycles = inst.STX_ZP_Y.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x0010]);
}

void test_stx_absolute(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;

    memory.data[0] = inst.STX_ABS.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    params.numCycles = inst.STX_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x1002]);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_stx_zeropage);
    RUN_TEST(test_stx_zeropage_y);
    RUN_TEST(test_stx_absolute);

    return UNITY_END();
}