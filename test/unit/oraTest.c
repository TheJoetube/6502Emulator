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

void test_ora_im(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;

    memory.data[0] = inst.EOR_IM.opcode;
    memory.data[1] = 0b01111001;

    params.numCycles = inst.EOR_IM.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_zeropage(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;

    memory.data[0] = inst.EOR_ZP.opcode;
    memory.data[1] = 0x0F;

    memory.data[0x000F] = 0b01111001;

    params.numCycles = inst.EOR_ZP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_zeropage_x(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;
    cpu.X = 0x01;

    memory.data[0] = inst.EOR_ZP_X.opcode;
    memory.data[1] = 0x01;

    memory.data[0x0002] = 0b01111001;

    params.numCycles = inst.EOR_ZP_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_absolute(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;

    memory.data[0] = inst.EOR_ABS.opcode;
    memory.data[1] = 0x34;
    memory.data[2] = 0x12;

    memory.data[0x1234] = 0b01111001;

    params.numCycles = inst.EOR_ABS.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_absolute_x(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;
    cpu.X = 0x92;

    memory.data[0] = inst.EOR_ABS_X.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = 0b01111001;

    params.numCycles = inst.EOR_ABS_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_absolute_y(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;
    cpu.Y = 0x92;

    memory.data[0] = inst.EOR_ABS_Y.opcode;
    memory.data[1] = 0x00;
    memory.data[2] = 0x20;

    memory.data[0x2092] = 0b01111001;

    params.numCycles = inst.EOR_ABS_Y.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_indexed_indirect(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;
    cpu.X = 0x20;

    memory.data[0] = inst.EOR_IN_X.opcode;
    memory.data[1] = 0x40;

    memory.data[0x0060] = 0b01111001;

    params.numCycles = inst.EOR_IN_X.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

void test_ora_indirect_indexed(void) {
    const Byte checkValue = 0b11111111;

    cpu.A = 0b10000110;
    cpu.Y = 0x20;

    memory.data[0] = inst.EOR_IN_Y.opcode;
    memory.data[1] = 0x40;

    memory.data[0x0060] = 0b01111001;

    params.numCycles = inst.EOR_IN_Y.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX8(checkValue, cpu.A);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_ora_im);
    RUN_TEST(test_ora_zeropage);
    RUN_TEST(test_ora_zeropage_x);
    RUN_TEST(test_ora_absolute);
    RUN_TEST(test_ora_absolute_x);
    RUN_TEST(test_ora_absolute_y);
    RUN_TEST(test_ora_indexed_indirect);
    RUN_TEST(test_ora_indirect_indexed);

    return UNITY_END();
}