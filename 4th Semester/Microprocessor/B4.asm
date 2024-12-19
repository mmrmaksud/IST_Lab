.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'enter elements: $'
MSG2 DB 'AFTER SORTING: $'
ARR DB 100 dup (0)
.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX
MOV AH, 9
lea DX, MSG1    ; DISPLAY MSG1
INT 21H

XOR CX, CX
MOV AH, 1
INT 21H    ; first input
XOR SI, SI   

WHILE_:
    CMP AL, 0dH    ; compare input with CR
    
    JE END_WHILE
    MOV ARR[SI], AL   ; move input into array
    INC SI    ;SI+1
    INC CX
    MOV AH, 2
    MOV DL, ' '    ; display space
    INT 21h
    MOV AH, 1
    INT 21H
JMP WHILE_

END_WHILE:
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
JCXZ EXIT
    LEA SI, ARR
    MOV BX, CX
CALL BUBBLE_SORT

MOV AH, 9
LEA DX, MSG2
INT 21H
XOR SI,SI
TOP:
    MOV AH, 2
    MOV DL, ARR[SI]
    INT 21H
    MOV DL, ' '
    INT 21H
    INC SI
    LOOP TOP
EXIT:
    MOV AH, 4CH
    INT 21H
    MAIN ENDP

BUBBLE_SORT PROC
    ; this procedure will sort the array in ascending order
    ; input : SI=offset address of the array
    ;       : BX=array size
    ; output: Sorted Array
    
    PUSH AX    ; push AX onto the STACK
    PUSH BX    ; push BX onto the STACK
    PUSH CX    ; push CX onto the STACK
    PUSH DX    ; push DX onto the STACK
    PUSH DI    ; push DI onto the STACK
    
    MOV AX, SI
    MOV CX, BX
    DEC CX

@OUTER_LOOP:
    MOV BX, CX
    MOV SI, AX
    MOV DI, AX
    INC DI
    
    @INNER_LOOP:
     MOV DL, [SI]
     CMP DL, [DI]
       JNG @SKIP_EXCHANGE
       
       XCHG DL, [DI]
       MOV [SI], DL
       @SKIP_EXCHANGE:
       INC SI
       INC DI
       DEC BX
    JNZ @INNER_LOOP
  LOOP @OUTER_LOOP
  
  POP DI
  POP DX
  POP CX
  POP BX
  POP AX
  
  RET
  
  BUBBLE_SORT ENDP

END MAIN
