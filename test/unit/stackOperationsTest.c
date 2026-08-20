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

void test_tsx_imp(void) {
    const Byte checkValue = 0xFF;

    cpu.SP = checkValue;
    cpu.X = 0x00;

    memory.data[0] = inst.TSX_IMP.opcode;

    params.numCycles = inst.TSX_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.X);
}

void test_txs_imp(void) {
    const Byte checkValue = 0xFC;

    cpu.X = checkValue;
    cpu.SP = 0xFF;

    memory.data[0] = inst.TXS_IMP.opcode;

    params.numCycles = inst.TXS_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.SP);
}

void test_pha_imp(void) {
    const Byte checkValue = 0x10;

    cpu.A = checkValue;

    memory.data[0] = inst.PHA_IMP.opcode;

    params.numCycles = inst.PHA_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[STACKSTART + cpu.SP+1]);
}

void test_php_imp(void) {
    const Byte checkValue = 0b0110111;

    cpu.status.value = checkValue;

    memory.data[0] = inst.PHP_IMP.opcode;

    params.numCycles = inst.PHP_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, memory.data[STACKSTART + cpu.SP+1]);
}

void test_pla_imp(void) {
    const Byte checkValue = 0x10;

    memory.data[STACKSTART + cpu.SP] = checkValue;
    cpu.SP -= 1;

    memory.data[0] = inst.PLA_IMP.opcode;

    params.numCycles = inst.PLA_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.A);
}

void test_plp_imp(void) {
    const Byte checkValue = 0b01100110;

    cpu.status.value = checkValue;
    memory.data[STACKSTART + cpu.SP] = checkValue;
    cpu.SP -= 1;
    cpu.status.value = 0;

    memory.data[0] = inst.PLP_IMP.opcode;

    params.numCycles = inst.PLP_IMP.cycles;
    execute(&cpu, &memory, params);

    TEST_ASSERT_EQUAL_HEX(checkValue, cpu.status.value);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_tsx_imp);
    RUN_TEST(test_txs_imp);
    RUN_TEST(test_pha_imp);
    RUN_TEST(test_php_imp);
    RUN_TEST(test_pla_imp);
    RUN_TEST(test_plp_imp);

    return UNITY_END();
}