.section .text
.globl _start
_start:
    # Call main()
    call main

    # Exit with main's return value
    # Move return value to %edi (exit code)
    mov %eax, %edi
    # syscall: exit
    mov $60, %eax
    syscall
