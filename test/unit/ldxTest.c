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

void test_ldx_immediate(void)
{
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDX_IM.opcode;
    memory.data[1] = checkValue;

    execute(&cpu, &memory, inst.LDX_IM.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

void test_ldx_zeropage(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDX_ZP.opcode;
    memory.data[1] = 0x0F;
    memory.data[0x000F] = checkValue;

    execute(&cpu, &memory, inst.LDX_ZP.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}
void test_ldx_zeropage_y(void) {
    const Byte checkValue = 0x10;

    cpu.Y = 0x01;

    memory.data[0] = inst.LDX_ZP_Y.opcode;
    memory.data[1] = 0x01;
    memory.data[0x0002] = checkValue;

    execute(&cpu, &memory, inst.LDX_ZP_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

void test_ldx_absolute(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDX_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = checkValue;

    execute(&cpu, &memory, inst.LDX_ABS.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

void test_ldx_absolute_y(void) {
    const Byte checkValue = 0x10;

    cpu.Y = 0x92;

    memory.data[0] = inst.LDX_ABS_Y.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = checkValue;

    execute(&cpu, &memory, inst.LDX_ABS_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_ldx_immediate);
    RUN_TEST(test_ldx_immediate);
    RUN_TEST(test_ldx_zeropage_y);
    RUN_TEST(test_ldx_absolute);
    RUN_TEST(test_ldx_absolute_y);

    return UNITY_END();
}