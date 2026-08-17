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

void test_ldy_immediate(void)
{
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDY_IM.opcode;
    memory.data[1] = checkValue;

    params.numCycles = inst.LDY_IM.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}

void test_ldy_zeropage(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDY_ZP.opcode;
    memory.data[1] = 0x0F;
    memory.data[0x000F] = checkValue;

    params.numCycles = inst.LDY_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}
void test_ldy_zeropage_x(void) {
    const Byte checkValue = 0x10;

    cpu.X = 0x01;

    memory.data[0] = inst.LDY_ZP_X.opcode;
    memory.data[1] = 0x01;
    memory.data[0x0002] = checkValue;

    params.numCycles = inst.LDY_ZP_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}

void test_ldy_absolute(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDY_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = checkValue;

    params.numCycles = inst.LDY_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}

void test_ldy_absolute_x(void) {
    const Byte checkValue = 0x10;

    cpu.X = 0x92;

    memory.data[0] = inst.LDY_ABS_X.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = checkValue;

    params.numCycles = inst.LDY_ABS_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.Y);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_ldy_immediate);
    RUN_TEST(test_ldy_zeropage);
    RUN_TEST(test_ldy_zeropage_x);
    RUN_TEST(test_ldy_absolute);
    RUN_TEST(test_ldy_absolute_x);

    return UNITY_END();
}