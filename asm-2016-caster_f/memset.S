[BITS 64]
    
    global memset

    section .text

; rdi -> pointeur, rsi -> valeur, rdx -> taille
memset:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    looper:
        cmp rdx, 0
            je end
        dec rdx
        mov byte[rdi], sil
        inc rdi
        jmp looper
    
    end:
        mov rsp, rbp
        pop rbp
    
    ret
