//
// Created by napbad on 11/1/24.
//

#ifndef SYS_FUN_GEN_H
#define SYS_FUN_GEN_H
#include "src/core/parser/node.h"
#include "codegen_inter.h"
namespace dap::inter_gen
{
void genSysFun(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `write` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `write` function.
 *
 * This function defines the `write` system call using LLVM's type system and creates an external linkage function.
 */
Function *genSysWrite(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `fsync` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `fsync` function.
 *
 * This function defines the `fsync` system call using LLVM's type system and creates an external linkage function.
 */
Function *genSysFSync(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `read` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `read` function.
 *
 * This function defines the `read` system call using LLVM's type system and creates an external linkage function.
 */
Function *genSysRead(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `open` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `open` function.
 *
 * Refer to the definition of the Linux low-level open system call: int open(const char *pathname, int flags, mode_t
 * mode);
 */
Function *genSysOpen(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `close` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `close` function.
 *
 * Refer to the definition of the Linux low-level close system call: int close(int fd);
 */
Function *genSysClose(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `fork` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `fork` function.
 *
 * Refer to the definition of the Linux low-level fork system call: pid_t fork();
 */
Function *genSysFork(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `execve` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `execve` function.
 *
 * Refer to the definition of the Linux low-level execve system call: int execve(const char *filename, char *const
 * argv[], char *const envp[]);
 */
Function *genSysExecve(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `wait` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `wait` function.
 *
 * Refer to the definition of the Linux low-level wait system call: pid_t wait(int *status);
 */
Function *genSysWait(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `mmap` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `mmap` function.
 *
 * Refer to the definition of the Linux low-level mmap system call: void *mmap(void *addr, size_t length, int prot, int
 * flags, int fd, off_t offset);
 */
Function *genSysMmap(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `munmap` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `munmap` function.
 *
 * Refer to the definition of the Linux low-level munmap system call: int munmap(void *addr, size_t length);
 */
Function *genSysMunmap(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `socket` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `socket` function.
 *
 * Refer to the definition of the Linux low-level socket system call: int socket(int domain, int type, int protocol);
 */
Function *genSysSocket(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `bind` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `bind` function.
 *
 * Refer to the definition of the Linux low-level bind system call: int bind(int socket, const struct sockaddr *address,
 * socklen_t address_len);
 */
Function *genSysBind(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `listen` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `listen` function.
 *
 * Refer to the definition of the Linux low-level listen system call: int listen(int socket, int backlog);
 */
Function *genSysListen(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the systemic call `accept` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `accept` function.
 *
 * Refer to the definition of the Linux low-level accept system call: int accept(int socket, struct sockaddr *address,
 * socklen_t *address_len);
 */
Function *genSysAccept(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `connect` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `connect` function.
 *
 * Refer to the definition of the Linux low-level connect system call: int connect(int socket, const struct sockaddr
 * *address, socklen_t address_len);
 */
Function *genSysConnect(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `brk` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `brk` function.
 *
 * Refer to the definition of the Linux low-level brk system call: int brk(void *addr);
 */
Function *genSysBrk(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the system call `sbrk` and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created system call `sbrk` function.
 *
 * Refer to the definition of the Linux low-level sbrk system call: void *sbrk(intptr_t increment);
 */
Function *genSysSbrk(const InterGenContext *ctx);


/**
 * \brief Generates the function type for the `_init` function and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `_init` function.
 *
 * This function defines the `_init` function using LLVM's type system and creates an external linkage function.
 */
Function *genInit(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the `_fini` function and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `_fini` function.
 *
 * This function defines the `_fini` function using LLVM's type system and creates an external linkage function.
 */
Function *genFini(const InterGenContext *ctx);

/**
 * \brief Generates the function type for the `exit` function and creates the function.
 *
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \return The created `exit` function.
 *
 * This function defines the `exit` function using LLVM's type system and creates an external linkage function.
 */
Function *genExit(const InterGenContext *ctx);


/**
 * \brief Handles the system call by generating the appropriate LLVM IR.
 *
 * \param call A pointer to the call Expression representing the system call.
 * \param ctx A pointer to the intermediate generation context, used to get the LLVM context and module information.
 * \param fun A pointer to the function where the system call is being handled.
 * \return The generated call instruction.
 *
 * This function processes the system call and generates the corresponding LLVM IR instructions.
 */
CallInst *handleSys(const parser::CallExpr *call, InterGenContext *ctx, Function *fun);
} // namespace dap::inter_gen

#endif // SYS_FUN_GEN_H
