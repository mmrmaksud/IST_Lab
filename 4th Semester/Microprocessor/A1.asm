.MODEL SMALL
.STACK

.DATA
    MESSAGE DB 0DH, 0AH, 'Enter a character: $'
    RESULT DB 0DH, 0AH, 'Converted character: $'
    CHAR DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Display message asking for input
    MOV DX, OFFSET MESSAGE
    MOV AH, 09H
    INT 21H

    ; Read character from the user
    MOV AH, 01H
    INT 21H
    MOV CHAR, AL

    ; Check if the character is lowercase
    CMP CHAR, 'a'
    JB NOT_LOWER
    CMP CHAR, 'z'
    JA NOT_LOWER

    ; Convert lowercase to uppercase
    SUB CHAR, 32

    ; Jump to display result
    JMP DISPLAY_RESULT

NOT_LOWER:
    ; Check if the character is uppercase
    CMP CHAR, 'A'
    JB DISPLAY_RESULT
    CMP CHAR, 'Z'
    JA DISPLAY_RESULT

    ; Convert uppercase to lowercase
    ADD CHAR, 32

DISPLAY_RESULT:
    ; Display the converted character
    MOV DX, OFFSET RESULT
    MOV AH, 09H
    INT 21H

    MOV DL, CHAR
    MOV AH, 02H
    INT 21H

    ; Exit the program
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
