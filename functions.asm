; Luke Underwood
; 10/16/2020
; CS301
; CS301 - Project
; InventoryAndShop
; Assembly file containing various back-end functions

section .text

bits 64

extern overflowErr

global moveMoney
moveMoney:

    ; using commit/roll back to make sure no overflow happens...
    mov r8, [rdi]
    sub r8, rdx     ; subtract
    jc overflow     ; check for overflow
    mov [rdi], r8   ; commit change

    mov r9, [rsi] 
    add r9, rdx     ; add
    jc overflow     ; check for overflow
    mov [rsi], r9   ; commit change

    ; return 1 to signal a success
    mov rax, 1
    ret

    ; let the user know something went wrong, and return
    overflow:
        call overflowErr

        ; return 0 to signal a failure
        mov rax, 0
        ret
    