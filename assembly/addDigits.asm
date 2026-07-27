global _main
extern _printf
extern _scanf

section .data
    inputFormat db "%d", 0
    outputFormat db "Wynik: %d", 10, 0

section .bss
    number1 resd 1
    number2 resd 1   

section .text  

_main:
    lea rdi, [rel inputFormat]
    lea rsi, [rel number1]
    xor eax, eax
    call _scanf

    lea rdi, [rel inputFormat]
    lea rsi, [rel number2]
    xor eax, eax
    call _scanf

    mov eax, [rel number1]
    add eax, [rel number2]

    mov esi, eax
    lea rdi, [rel outputFormat]
    xor eax, eax
    call _printf

    mov eax, 0
    ret
