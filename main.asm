; Luke Underwood
; 10/26/2020
; CS301
; CS301 - Project
; InventoryAndShop
; Assembly file containing main program loop

section .text
bits 64

extern printMenu
extern getInt
extern printErrMsg

global mainMenu
mainMenu:

    ; preserve function parameters
    push rdi ; player
    push rdx ; print player inventory
    push rcx ; buy menu
    push r8  ; sell menu

loopStart:

    ; print the menu for the user
    call printMenu

    ; set up for getInt
    mov rdi, [promptMsg]
    mov rsi, [inputNum]

    call getInt
    
    ; if the input succeeded, jump
    cmp rax, 0
    jg inputSucceeded

    ; else jump to inputFailed (below)
    jmp inputFailed

inputSucceeded:

    ; 1 = print player inventory
    cmp DWORD[inputNum], 1
    je printPlayerInv

    ; move the player into rdi
    ; putting this here to keep it DRY,
    ; since buy & sell both use it
    mov rdi, [rsp - 3*8]

    ; 2 = enter the buy menu
    cmp DWORD[inputNum], 2
    je buyMenu

    ; 3 = enter the sell menu
    cmp DWORD[inputNum], 3
    je sellMenu

    ; 0 = get out of here
    cmp DWORD[inputNum], 0
    je finish

inputFailed:
    ; if we found ourselves here, the input was bad
    call printErrMsg
    jmp loopStart

printPlayerInv:

    ; call the third thing on the stack
    ; this happens to be the player inv
    call [rsp - 2*8]
    jmp loopStart

buyMenu:

    ; call the second thing on the stack
    ; this happens to be the buy menu
    call [rsp - 8]
    jmp loopStart

sellMenu:

    ; call the first thing on the stack
    ; this happens to be the sell menu
    call [rsp]
    jmp loopStart

finish:
    ; clean up the stack
    add rsp, 4*8

    ; end the function, returns void
    ret

section .data
errMsg:
    dq "Invalid Input. Try Again.",0

promptMsg:
    dq "Enter the number next to your desired choice:", 0

inputNum:
    dd 0