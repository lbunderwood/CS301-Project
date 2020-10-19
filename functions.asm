section .text

bits 64

global moveMoney
moveMoney:
    sub [rdi], rsi
    add [rdi + 8], rsi
    ret
    