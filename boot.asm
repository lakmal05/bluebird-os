; Bluebird OS Bootloader
; File: boot/boot.asm

[org 0x7c00]

start:
    mov si, message
    call print_string

    jmp $

print_string:
    mov ah, 0x0e

.next_char:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next_char

.done:
    ret

message db "Welcome to Bluebird OS!", 0

times 510-($-$$) db 0
dw 0xaa55
