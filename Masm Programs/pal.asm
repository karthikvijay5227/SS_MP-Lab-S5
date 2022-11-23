print macro s
        mov ah, 09h
        mov dx, offset s
        int 21h
endm
data segment
        msg db 'Enter a string: $'
        msg_y db 'String is a palindrome!$'
        msg_n db 'String is not a palindrome!$'
        nl db 0dh, 0ah,'$'
        str db 50 dup('$')
data ends
code segment
        assume ds:data, cs:code
        start:
        mov ax, data
        mov ds, ax
        mov es, ax
        print msg
        mov ah, 01h
        mov si, offset str
        mov cx, 0000h
        LOOP1:
                int 21h
                cmp al, 0dh
                jz STOP1
                mov [si], al
                inc si
                inc cx
                jmp LOOP1
        STOP1:
        dec si
        mov di, offset str
        mov ax, cx
        mov cl, 02h    
        div cl
        mov cl, al
        LOOP2:
                cmp cl, 00h
                jz PAL
                mov ah, [si]
                cmp ah, [di]
                jnz NOTPAL
                dec si
                inc di
                dec cl
                jmp LOOP2
        PAL:
                print nl
                print msg_y
                jmp SKIP
        NOTPAL:
                print nl
                print msg_n
        SKIP:
        mov ah, 4ch
        int 21h
code ends
end start