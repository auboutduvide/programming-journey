global _main
extern _scanf
extern _printf

section .data
    msg db "Czesc, witaj", 10, 0
    prompt db "Podaj liczbe: ", 0
    format_in db "%d", 0
    format_out db "Wpisales liczbe: %d", 10, 0

section .bss
    input_val resd 1

section .text

_main:
    push rbp
    mov rbp, rsp

    lea rdi, [rel msg]
    xor eax, eax
    call _printf

    lea rdi, [rel prompt]
    xor eax, eax
    call _printf

    lea rdi, [rel format_in]
    lea rsi, [rel input_val]
    xor eax, eax
    call _scanf

    lea rdi, [rel format_out]
    mov esi, [rel input_val]
    xor eax, eax
    call _printf
    
    xor eax, eax
    pop rbp
    ret