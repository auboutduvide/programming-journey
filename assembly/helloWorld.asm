global _main
extern _printf

section .data
    msg db "hello from assembly!", 10, 0

section .text

_main:
    sub rsp, 8
    lea rdi, [rel msg]
    call _printf
    add rsp, 8
    mov rax, 0
    ret