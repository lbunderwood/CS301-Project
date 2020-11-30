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
extern lootMenu
extern resetShop

global mainMenu
mainMenu:

    ; preserve function parameters
    push rdi ; player = rsp + 16
    push rsi ; shop = rsp + 8
    push rdx ; lootable = rsp

loopStart:

    ; print the menu for the user
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

    ; 1 = print player inventory
    cmp rax, 1
    je printPlayerInv

    ; 2 = enter the buy menu
    cmp rax, 2
    je shopSellMenu

    ; 3 = enter the sell menu
    cmp rax, 3
    je shopBuyMenu

    ; 4 = reset the shop
    cmp rax, 4
    je reset

    ; 5 = open a lootable
    cmp rax, 5
    je loot

    ; 0 = get out of here
    cmp rax, 0
    je finish

inputFailed:
    ; if we found ourselves here, the input was bad
    call printErrMsg
    jmp loopStart

printPlayerInv:

    mov rsi, [rsp + 8] ; rsi = shop
    mov rdi, [rsp + 16] ; rdi = player
    call printInventory
    jmp loopStart
    
shopSellMenu:

    mov rsi, [rsp + 8] ; rsi = shop
    mov rdi, [rsp + 16] ; rdi = player
    call sellMenu
    jmp loopStart

shopBuyMenu:

    mov rsi, [rsp + 8] ; rsi = shop
    mov rdi, [rsp + 16] ; rdi = player
    call buyMenu
    jmp loopStart

reset:

    mov rdi, [rsp + 8] ; rdi = shop
    call resetShop
    jmp loopStart

loot:

    mov rsi, [rsp] ; rsi = lootable
    mov rdi, [rsp + 16] ; rdi = player
    call lootMenu
    jmp loopStart

finish:
    ; reset stack, equivalent to 3x pop
    add rsp, 24
    ; exit function, returns void
    ret

section .data
promptMsg:
    dq 'Enter the number next to your desired choice:', 0

inputNum:
    dd 0