[BITS 64]

    global strlen

    section .text

strlen:
    push rbp
    mov rbp, rsp

    mov rax, 0 ; init la valeur de retour a 0
    begin:
        cmp byte[rdi], 0 ; comparaison du caractere actuelle de rdi avec 0 ('\0')
            je end ; jump si egale
        inc rax ; increment la valeur de retour
        inc rdi ; increment le pointeur vers notre chaine
        jmp begin ; jump dans tout les cas

    end:
        mov rsp, rbp
        pop rbp
    ret ; return
