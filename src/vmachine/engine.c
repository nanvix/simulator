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


R_instruction* r_inst;

/**
 * Check if these two parameters are equals.
 * @param tk1
 * @param tk2
 * */
static void match(char* tk1,char* tk2)
{
	if(!equals(tk1,tk2)) printf("%s",SYNTATIC_ERROR);
}

/*
* r_procedure_Function()
*/
static void r_procedure_Function()
{

}

/*
* r_procefure_Format()
*/
static void r_procedure_Format()
{

}

/*
 * First rule of grammar and Parsing tree
*/
static void r_procedure_S()
{
	if(equals(R_OPCODE,r_inst->opcode))
	{
		match(R_OPCODE,r_inst->opcode);
	}
	r_procedure_Format();
	r_pocedure_functionOpcode();
}

/**
 * Translate binary code MIPS32 in RV32.
 * Opening process of translate
 */
static void r_translator()
{
	r_procedure_S(r_inst);
}

/**
 * Select type of instruction.
 * Extract each word of instruction 
 * and redirects for each function corresponding
 * @param inst[] MIPS instruction of 32 bits
 * */
void select(char inst[])
{
		
	char* opcode = substring(inst,0,5);

	if(equals(opcode,R_OPCODE)){
		r_inst = init();

		r_inst->opcode = opcode;
		r_inst->rs = substring(inst,6,10);
		r_inst->rt = substring(inst,11,15);
		r_inst->rd = substring(inst,16,20);
		r_inst->shamt = substring(inst,21,25);
		r_inst->funct = substring(inst,26,31);
		r_translator();
	}
}

/**
 * The engine_run() function translates a binary code into another.
 */
word_t engine_run(uint32_t instruction)
{
	char string_instruction[32];
	itoa(instruction,string_instruction,10);
	select(string_instruction);

	return (instruction);
}
