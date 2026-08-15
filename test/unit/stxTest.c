#include "unity.h"
#include "constants.h"
#include "cpuFunctions.h"
#include "instructionFunctions.h"

Memory memory;
CPU cpu;

void setUp(void)
{
    initInstructions();

    memory.data[RESVEC_LO] = 0x00;
    memory.data[RESVEC_HI] = 0x00;

    reset(&cpu, &memory);
}

void tearDown(void)
{
}

void test_stx_zeropage(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;

    memory.data[0] = inst.STX_ZP.opcode;
    memory.data[1] = 0x0F;

    execute(&cpu, &memory, inst.STX_ZP.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x000F]);
}

void test_stx_zeropage_y(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;
    cpu.Y = 0x01;

    memory.data[0] = inst.STX_ZP_Y.opcode;
    memory.data[1] = 0x0F;

    execute(&cpu, &memory, inst.STX_ZP_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x0010]);
}

void test_stx_absolute(void) {
    const Byte checkValue = 0x10;

    cpu.X = checkValue;

    memory.data[0] = inst.STX_ABS.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    execute(&cpu, &memory, inst.STX_ABS.cycles);

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