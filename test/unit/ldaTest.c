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
    memory.data[0] = inst.LDA_IM.opcode;
    memory.data[1] = 0x10;

    execute(&cpu, &memory, inst.LDA_IM.cycles);

    TEST_ASSERT_EQUAL_HEX(0x10, cpu.A);
}

void test_lda_zeropage(void) {
    memory.data[0] = inst.LDA_ZP.opcode;
    memory.data[1] = 0x0F;
    memory.data[0x000F] = 0x10;

    execute(&cpu, &memory, inst.LDA_ZP.cycles);

    TEST_ASSERT_EQUAL_HEX(0x10, cpu.A);
}
void test_lda_zeropage_x(void) {
    cpu.X = 0x01;

    memory.data[0] = inst.LDA_ZP_X.opcode;
    memory.data[1] = 0x01;
    memory.data[0x0002] = 0x10;

    execute(&cpu, &memory, inst.LDA_ZP_X.cycles);

    TEST_ASSERT_EQUAL_HEX(0x10, cpu.A);
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_lda_immediate);
    RUN_TEST(test_lda_zeropage);
    RUN_TEST(test_lda_zeropage_x);

    return UNITY_END();
}