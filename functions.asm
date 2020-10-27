; Luke Underwood
; 10/16/2020
; CS301
; CS301 - Project
; InventoryAndShop
; Assembly file containing various back-end functions

section .text

bits 64

global moveMoney
moveMoney:
    sub [rdi], rdx
    add [rsi], rdx
    ret
    