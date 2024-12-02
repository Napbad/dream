//
// Created by napbad on 11/16/24.
//

#ifndef D_BASIC_FUN_GEN_H
#define D_BASIC_FUN_GEN_H
#include "../common/global.h"
#include "codegen_inter.h"

namespace dap::inter_gen
{
/**
 * \brief Generates the function type for converting an integer to a character and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `int_to_char` function.
 *
 * This function defines the `int_to_char` conversion using LLVM's type system and creates an internal linkage function.
 * It truncates the integer to a character and returns the result.
 */
Function *genIntToChar(InterGenContext *ctx);

/**
 * \brief Generates the function type for converting a character to an integer and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `char_to_int` function.
 *
 * This function defines the `char_to_int` conversion using LLVM's type system and creates an internal linkage function.
 * It casts the character to an integer and returns the result.
 */
Function *genCharToInt(InterGenContext *ctx);

/**
 * Generates a function that can convert an integer with 32 bits to 8 bits.
 *
 * @param ctx The context for interactive generation, used to obtain necessary information.
 * @return A pointer to the generated function object.
 */
Function *genInt32To8(InterGenContext *ctx);

/**
 * \brief Generates the function type for converting a character to a string and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `char_to_str` function.
 *
 * This function defines the `char_to_str` conversion using LLVM's type system and creates an internal linkage function.
 * It allocates memory for a string of length 2, stores the character at the first position, and returns the string.
 */
Function *genCharToStr(InterGenContext *ctx);

/**
 * Generates the malloc function for dynamic memory allocation.
 *
 * @param ctx The intermediate generation context, used to store state and information during code generation.
 * @return A pointer to the generated malloc function.
 *
 * This function is responsible for generating a malloc function that can dynamically allocate memory at runtime.
 * It plays a crucial role in the code generation process by enabling dynamic memory management.
 */
Function *genMalloc(InterGenContext *ctx);

/**
 * Generates the free function for dynamic memory deallocation.
 *
 * @param ctx The intermediate generation context, used to store state and information during code generation.
 * @return A pointer to the generated free function.
 *
 * This function is responsible for generating a free function that can dynamically deallocate memory at runtime.
 * It plays a crucial role in the code generation process by enabling dynamic memory management.
 */
Function *genFree(InterGenContext *ctx);

/**
 * \brief Generates a value on the heap.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 *
 * This function defines the `genHeap` conversion using LLVM's type system and creates an internal linkage function.
 * It allocates memory for a value on the heap and returns the result.
 */
void genHeap(const InterGenContext *ctx);
} // namespace dap::inter_gen

#endif // D_BASIC_FUN_GEN_H