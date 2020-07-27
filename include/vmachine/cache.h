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

#ifndef VMACHINE_CHACHE_H_
#define VMACHINE_CHACHE_H_

	#include <vmachine/types.h>

	/**
	 * @brief Initializes a cache.
	 */
	extern void cache_init(void);

	/**
	 * @brief Reads an instruction from the instruction cache.
	 *
	 * @param addr Target address.
	 *
	 * @returns The instruction at the specified address.
	 */
	extern word_t icache_read(addr_t addr);

	/**
	 * @brief Reads a word from the data cache.
	 *
	 * @param addr Target address.
	 *
	 * @returns The word at the specified address.
	 */
	extern word_t dcache_read(addr_t addr);

	/**
	 * @brief Writes a word to the data cache.
	 *
	 * @param addr Target address.
	 * @param Data to store.
	 */
	extern void dcache_write(void);

#endif /* VMACHINE_CHACHE_H_ */
