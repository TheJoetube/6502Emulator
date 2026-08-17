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

void test_bit_zeropage(void) {
    cpu.A = 0xFF;

    memory.data[0] = inst.BIT_ZP.opcode;
    memory.data[1] = 0x0F;

    memory.data[0x000F] = 0x80;

    params.numCycles = inst.BIT_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.Z);
    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.V);
    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.N);

    setUp();

    cpu.A = 0x00;

    memory.data[0] = inst.BIT_ZP.opcode;
    memory.data[1] = 0x0F;

    memory.data[0x000F] = 0x40;

    params.numCycles = inst.BIT_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.Z);
    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.V);
    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.N);
}

void test_bit_absolute(void) {
    cpu.A = 0xFF;

    memory.data[0] = inst.BIT_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = 0x80;

    params.numCycles = inst.BIT_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.Z);
    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.V);
    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.N);

    setUp();

    cpu.A = 0x00;

    memory.data[0] = inst.BIT_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = 0x40;

    params.numCycles = inst.BIT_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.Z);
    TEST_ASSERT_EQUAL_HEX8(0x01, cpu.status.V);
    TEST_ASSERT_EQUAL_HEX8(0x00, cpu.status.N);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_bit_zeropage);
    RUN_TEST(test_bit_absolute);

    return UNITY_END();
}