/*
 * MIT License
 *
 * Copyright(c) 2011-2020 The Maintainers of Nanvix
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NDEBUG

#include <arch/mips32.h>
#include <asm/inst.h>
#include <utils.h>

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include "../test.h"

/* Import definitions. */
extern uint32_t arch_mips32_encode (const char *asmcmd);

#define assertEquals(x, y) assert((x) == (y))

void test_parse_Uint32(void)
{
	uint32_t expected_int = 3;

	assertEquals(atoi32("00011"), expected_int);
}

void test_encode_r_instruction(void)
{
	char *instr = "add s0, s1, s2";

	assertEquals(
		arch_mips32_encode(instr),
		(uint32_t)(INST_ADD_OPCODE << 26) |
		(REG_S1_NUM << 21)                |
		(REG_S2_NUM << 16)                |
		(REG_S0_NUM << 11)                |
		(0 << 6)                          |
		(INST_ADD_FUNCT << 0)
	);
}

void test_encode_mult(void)
{
	char *instr = "mult s0, s1";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_MULT_OPCODE << 26) |
		(REG_S0_NUM << 21)                 |
		(REG_S1_NUM << 16)                 |
		(0 << 11)                          |
		(0 << 6)                           |
		(INST_MULT_FUNCT << 0)
	);
}

void test_encode_div(void)
{
	char *instr = "div s0, s1";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_DIV_OPCODE << 26) |
		(REG_S0_NUM << 21)                |
		(REG_S1_NUM << 16)                |
		(0 << 11)                         |
		(0 << 6)                          |
		(INST_DIV_FUNCT << 0)
	);
}

void test_encode_sll(void)
{
	char *instr = "sll s0, s1, 1";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_SLL_OPCODE << 26) |
		(0 << 21)                         |
		(REG_S1_NUM << 16)                |
		(REG_S0_NUM << 11)                |
		(1 << 6)                          |
		(INST_SLL_FUNCT << 0)
	);
}

void test_encode_srl(void)
{
	char *instr = "srl s0, s1, 1";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_SRL_OPCODE << 26) |
		(0 << 21)                         |
		(REG_S1_NUM << 16)                |
		(REG_S0_NUM << 11)                |
		(1 << 6)                          |
		(INST_SRL_FUNCT << 0)
	);
}

void test_encode_jr(void)
{
	char *instr = "jr s0";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_JR_OPCODE << 26) |
		(REG_S0_NUM << 21)     |
		(0 << 16)              |
		(0 << 11)              |
		(0 << 6)               |
		(INST_JR_FUNCT << 0)
	);
}

void test_encode_i_instruction(void)
{
	char *instr = "addi s0, s1, 1";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_ADDI_OPCODE << 26) |
		(REG_S1_NUM << 21)                 |
		(REG_S0_NUM << 16)                 |
		(1 << 0)
	);
}

void test_encode_lw(void)
{
	char *instr = "lw s0, 4(s1)";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_LW_OPCODE << 26) |
		(REG_S1_NUM << 21)               |
		(REG_S0_NUM << 16)               |
		(4 << 0)
	);
}

void test_encode_sw(void)
{
	char *instr = "sw s0, 4(s1)";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_SW_OPCODE << 26) |
		(REG_S1_NUM << 21)               |
		(REG_S0_NUM << 16)               |
		(4 << 0)
	);
}

void test_encode_j_instruction(void)
{
	char *instr = "j 1024";

	assertEquals(arch_mips32_encode(instr),
		(uint32_t)(INST_J_OPCODE << 26) |
		(1024 << 0)
	);

}

struct test mips32_tests_api[] = {
	{ test_parse_Uint32,         "Parse binary string to uint32"},
	{ test_encode_r_instruction, "encode add " },
	{ test_encode_mult,          "encode mult" },
	{ test_encode_div,           "encode div " },
	{ test_encode_sll,           "encode sll " },
	{ test_encode_srl,           "encode srl " },
	{ test_encode_jr,            "encode jr  " },
	{ test_encode_i_instruction, "encode addi" },
	{ test_encode_lw,            "encode lw  " },
	{ test_encode_sw,            "encode sw  " },
	{ test_encode_j_instruction, "encode j   " },
	{ NULL,                       NULL         },
};

void test_mips32(void)
{
	for(int i = 0; mips32_tests_api[i].test_fn != NULL; i++)
{
		mips32_tests_api[i].test_fn();
		printf("[assembler][mips32][api] %s [passed]\n", mips32_tests_api[i].name);
	}
}

#endif /* !NDEBUG */
