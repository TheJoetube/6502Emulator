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

void test_lda_immediate(void)
{
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDA_IM.opcode;
    memory.data[1] = checkValue;

    execute(&cpu, &memory, inst.LDA_IM.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_lda_zeropage(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDA_ZP.opcode;
    memory.data[1] = 0x0F;
    memory.data[0x000F] = checkValue;

    execute(&cpu, &memory, inst.LDA_ZP.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}
void test_lda_zeropage_x(void) {
    const Byte checkValue = 0x10;

    cpu.X = 0x01;

    memory.data[0] = inst.LDA_ZP_X.opcode;
    memory.data[1] = 0x01;
    memory.data[0x0002] = checkValue;

    execute(&cpu, &memory, inst.LDA_ZP_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_lda_absolute(void) {
    const Byte checkValue = 0x10;

    memory.data[0] = inst.LDA_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = checkValue;

    execute(&cpu, &memory, inst.LDA_ABS.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_lda_absolute_x(void) {
    const Byte checkValue = 0x10;

    cpu.X = 0x92;

    memory.data[0] = inst.LDA_ABS_X.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = checkValue;

    execute(&cpu, &memory, inst.LDA_ABS_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_lda_absolute_y(void) {
    const Byte checkValue = 0x10;

    cpu.Y = 0x92;

    memory.data[0] = inst.LDA_ABS_Y.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = checkValue;

    execute(&cpu, &memory, inst.LDA_ABS_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}


void test_lda_indexed_indirect(void) {
    const Byte checkValue = 0x10;

    cpu.X = 0x20;

    memory.data[0] = inst.LDA_IN_X.opcode;
    memory.data[1] = 0x40;

    memory.data[0x0060] = checkValue;

    execute(&cpu, &memory, inst.LDA_IN_X.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_lda_indirect_indexed(void) {
    const Byte checkValue = 0x10;

    cpu.Y = 0x20;

    memory.data[0] = inst.LDA_IN_Y.opcode;
    memory.data[1] = 0x40;

    memory.data[0x0060] = checkValue;

    execute(&cpu, &memory, inst.LDA_IN_Y.cycles);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_lda_immediate);
    RUN_TEST(test_lda_zeropage);
    RUN_TEST(test_lda_zeropage_x);
    RUN_TEST(test_lda_absolute);
    RUN_TEST(test_lda_absolute_x);
    RUN_TEST(test_lda_absolute_y);
    RUN_TEST(test_lda_indexed_indirect);
    RUN_TEST(test_lda_indirect_indexed);

    return UNITY_END();
}