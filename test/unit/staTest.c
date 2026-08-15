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

void test_sta_zeropage(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;

    memory.data[0] = inst.STA_ZP.opcode;
    memory.data[1] = 0x0F;

    execute(&cpu, &memory, inst.STA_ZP.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x000F]);
}

void test_sta_zeropage_x(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.X = 0x01;

    memory.data[0] = inst.STA_ZP_X.opcode;
    memory.data[1] = 0x0F;

    execute(&cpu, &memory, inst.STA_ZP_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x0010]);
}

void test_sta_absolute(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;

    memory.data[0] = inst.STA_ABS.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    execute(&cpu, &memory, inst.STA_ABS.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x1002]);
}

void test_sta_absolute_x(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.X = 0x02;

    memory.data[0] = inst.STA_ABS_X.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    execute(&cpu, &memory, inst.STA_ABS_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x1004]);
}

void test_sta_absolute_y(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.Y = 0x02;

    memory.data[0] = inst.STA_ABS_Y.opcode;
    memory.data[1] = 0x02;
    memory.data[2] = 0x10;

    execute(&cpu, &memory, inst.STA_ABS_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x1004]);
}

void test_sta_indexed_indirect(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.X = 0x02;

    memory.data[0] = inst.STA_IN_X.opcode;
    memory.data[1] = 0x02;

    execute(&cpu, &memory, inst.STA_IN_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x04]);
}

void test_sta_indirect_indexed(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;
    cpu.X = 0x02;

    memory.data[0] = inst.STA_IN_Y.opcode;
    memory.data[1] = 0x02;

    execute(&cpu, &memory, inst.STA_IN_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[0x04]);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_sta_zeropage);
    RUN_TEST(test_sta_zeropage_x);
    RUN_TEST(test_sta_absolute);
    RUN_TEST(test_sta_absolute_x);
    RUN_TEST(test_sta_absolute_y);
    RUN_TEST(test_sta_indexed_indirect);
    RUN_TEST(test_sta_indirect_indexed);

    return UNITY_END();
}