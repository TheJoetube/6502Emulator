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

void test_and_im(void) {
    const Byte checkValue = 0b1000010;

    cpu.A = 0b10000000;

    memory.data[0] = inst.AND_IM.opcode;
    memory.data[1] = 0b10000000;

    execute(&cpu, &memory, inst.AND_IM.cycles);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.status.value);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_and_im);

    return UNITY_END();
}