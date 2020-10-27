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
extern printInventory
extern buyMenu
extern sellMenu

global mainMenu
mainMenu:

    ; preserve function parameters
    push rdi ; player
    push rdx ; shop

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

    ;move the player and shop pointers from stack to use
    mov rdi, [rsp - 8]
    mov rdx, [rsp]

    ; 1 = print player inventory
    cmp DWORD[inputNum], 1
    je printPlayerInv

    ; 2 = enter the buy menu
    cmp DWORD[inputNum], 2
    je shopBuyMenu

    ; 3 = enter the sell menu
    cmp DWORD[inputNum], 3
    je shopSellMenu

    ; 0 = get out of here
    cmp DWORD[inputNum], 0
    je finish

inputFailed:
    ; if we found ourselves here, the input was bad
    call printErrMsg
    jmp loopStart

printPlayerInv:

    call printInventory
    jmp loopStart

shopBuyMenu:

    ; call the second thing on the stack
    ; this happens to be the buy menu
    call buyMenu
    jmp loopStart

shopSellMenu:

    ; call the first thing on the stack
    ; this happens to be the sell menu
    call sellMenu
    jmp loopStart

finish:
    ; clean up the stack
    add rsp, 2*8

    ; end the function, returns void
    ret

section .data
errMsg:
    dq "Invalid Input. Try Again.",0

promptMsg:
    dq "Enter the number next to your desired choice:", 0

inputNum:
    dd 0