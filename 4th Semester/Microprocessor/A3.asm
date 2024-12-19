.model small
.stack
.data
    val1 db ?
    val2 db ?
    sum db ?
    msg1 db 0dh, 0ah, "Enter first digit: $"
    msg2 db 0dh, 0ah, "Enter second digit: $"
    msg3 db 0dh, 0ah, "Sum of two numbers: $"

.code
main proc
    mov ax, @data
    mov ds, ax

    ; Read first digit
    mov dx, offset msg1
    mov ah, 9
    int 21h

    mov ah, 1
    int 21h
    sub al, 30h  ; Convert ASCII digit to binary
    mov val1, al

    ; Read second digit
    mov dx, offset msg2
    mov ah, 9
    int 21h

    mov ah, 1
    int 21h
    sub al, 30h  ; Convert ASCII digit to binary
    mov val2, al

    ; Add the digits
    mov al, val1
    add al, val2
    add al, 30h  ; Convert sum to ASCII

    ; Store the sum
    mov sum, al

    ; Display the sum
    mov dx, offset msg3
    mov ah, 9
    int 21h

    mov dl, sum
    mov ah, 2
    int 21h

    ; Exit the program
    mov ah, 4Ch
    int 21h
main endp
end main
