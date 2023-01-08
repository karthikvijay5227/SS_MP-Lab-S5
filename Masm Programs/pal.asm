DATA SEGMENT
string DB 10 DUP("$")
MSG1 DB 10,13,"PALINDROME $"
MSG2 DB 10,13,"NOT PALINDROME $"
DATA ENDS


CODE SEGMENT
	ASSUME CS:CODE,DS:DATA
	START:MOV AX,DATA
	MOV DS,AX
	lea dx, string
	mov ah, 0ah
	int 21h

	lea di, string+2
	lea si, [di]
	mov cl, string[1]
	sub cl, 1
	add si, cx
	shr cx, 1

	checkPal:
	mov al, [di]
	mov dl, [si]
	cmp al, dl
	jne printNotPal
	inc di
	dec si
	loop checkPal

	printPal:
	lea dx, MSG1
	jmp print

	printNotPal:
	lea dx, MSG2

	print:
	mov ah, 9h
	int 21h

	mov ah, 0
	int 16h
	mov ah,4ch
	int 21h
CODE ENDS
END START
