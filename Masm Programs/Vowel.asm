DATA SEGMENT 
STRING DB 100 DUP(?)
MSG1 DB "ENTER A STRING: $"
MSG2 DB 0DH, 0AH, "NO. OF VOWELS_FOUNDS: $"
VOWELS DW 0 
DATA ENDS
CODE SEGMENT 
   ASSUME CS:CODE,DS:DATA
   START:
    
     MOV AX, DATA
     MOV DS, AX
     MOV ES, AX
     
     MOV AH, 9
     LEA DX, MSG1
     INT 21H
     
     LEA DI, STRING
 
     MOV AH, 1
     READ:
     INT 21H
     CMP AL, 0DH
     JE ENDOFSTRING
     STOSB
     JMP READ
     
     ENDOFSTRING:
     MOV AL, "$"
     STOSB
     
     XOR BX, BX
     
     COUNT:
     MOV AL, STRING[BX]
     CMP AL, "$"
     JE EXIT
     CMP AL, "a"
     JE VOWEL_FOUND
     CMP AL, "e"
     JE VOWEL_FOUND
     CMP AL, "i"
     JE VOWEL_FOUND
     CMP AL, "o"
     JE VOWEL_FOUND
     CMP AL, "u"
     JE VOWEL_FOUND
     CMP AL, "A"
     JE VOWEL_FOUND
     CMP AL, "E"
     JE VOWEL_FOUND
     CMP AL, "I"
     JE VOWEL_FOUND
     CMP AL, "O"
     JE VOWEL_FOUND
     CMP AL, "U"
     JE VOWEL_FOUND      
     INC BX
     JMP COUNT
     
     VOWEL_FOUND:
     MOV CX, VOWELS
     INC CX
     MOV VOWELS, CX
     INC BX 
     JMP COUNT     
         
     EXIT:
     
     MOV AH, 9
     LEA DX, MSG2
     INT 21H
     
     MOV AH, 2
     MOV DX, VOWELS
     ADD DX, 30H
     INT 21H
     
     MOV AH,4CH
     INT 21H
     
CODE ENDS
END START
