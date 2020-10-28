; Luke Underwood
; 10/26/2020
; CS301
; CS301 - Project
; InventoryAndShop
; Assembly file containing main program loop

promptMsg:
    dq 'Enter the number next to your desired choice:', 0

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
    extern printMenu
    call printMenu

    ; set up for getInt
    mov rdi, [promptMsg]
    ; we will put the outputted number on the stack (for now)
    sub rsp, 8
    mov rdx, [rsp]

    call getInt
    
    ; if the input succeeded, jump
    cmp rax, 0
    jg inputSucceeded

    ; else jump to inputFailed (below)
    jmp inputFailed

inputSucceeded:

    ;move the player and shop pointers from stack to use
    pop rax ; rax = number returned
    mov rdi, [rsp - 8]
    mov rdx, [rsp]

    ; 1 = print player inventory
    cmp rax, 1
    je printPlayerInv

    ; 2 = enter the buy menu
    cmp rax, 2
    je shopBuyMenu

    ; 3 = enter the sell menu
    cmp rax, 3
    je shopSellMenu

    ; 0 = get out of here
    cmp rax, 0
    je finish

inputFailed:
    ; if we found ourselves here, the input was bad
    call printErrMsg
    jmp loopStart

printPlayerInv:

    call printInventory
    jmp loopStart

shopBuyMenu:

    call buyMenu
    jmp loopStart

shopSellMenu:

    call sellMenu
    jmp loopStart

finish:
    ; clean up the stack
    add rsp, 2*8

    ; end the function, returns void
    ret