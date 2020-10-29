; Luke Underwood
; 10/26/2020
; CS301
; CS301 - Project
; InventoryAndShop
; Assembly file containing main program loop

section .text
bits 64

extern printMenu
extern getIntC
extern printErrMsg
extern printInventory
extern buyMenu
extern sellMenu

global mainMenu
mainMenu:

    ; preserve function parameters
    push rdi ; player
    push rsi ; shop

loopStart:

    ; print the menu for the user12
    call printMenu

    ; set up for getInt
    mov rdi, promptMsg
    mov rsi, inputNum

    call getIntC
    
    ; if the input succeeded, jump
    cmp rax, 0
    jg inputSucceeded

    ; else jump to inputFailed (below)
    jmp inputFailed

inputSucceeded:

    ;move the player and shop pointers from stack to use
    mov rax, [inputNum]
    pop rsi ; rsi = shop
    pop rdi ; rdi = player

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
    ; end the function, returns void
    ret

section .data
promptMsg:
    dq 'Enter the number next to your desired choice:', 0

inputNum:
    dd 0