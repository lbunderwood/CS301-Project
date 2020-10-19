section .text

bits 64

global moveMoney
moveMoney:
    sub [rdi], rdx
    add [rsi], rdx
    ret
    