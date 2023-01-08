DATA SEGMENT
            ST1 DB 100 DUP(?)
            MSG1 DB "ENTER THE STRING $"
            MSG2 DB "REVERSED STRING $"
DATA ENDS

CODE SEGMENT
            ASSUME CS:CODE
            START:
                         MOV AX,DATA
                         MOV DS,AX
                         LEA DX,MSG1
                         MOV AH,09H
                         INT 21H
                         LEA SI,ST1
                         MOV CL,00H
           L1:
                         MOV AH,01H
                         INT 21H
                         CMP AL,0DH
                         JZ L2
                         INC CL
                         INC SI
                         MOV [SI],AL
                         INC SI
                         INC CL
                         JMP L1
          L2:
                         MOV DL,0AH
                         INT 21H
                         MOV DL,0DH
                         INT 21H
                         LEA DX,MSG2
                         MOV AH,09H
                         INT 21H
         L3:
                         MOV DL,[SI]
                         MOV AH,02H
                         INT 21H
                         DEC SI
                         DEC CL
                         CMP CL,00H
                         JNZ L3
                         MOV AH,4CH
                         INT 21H
CODE ENDS
END START
