[BITS 64]

    global strcmp

    section .text

strcmp:

    push rbp
    mov rbp, rsp

    mov rcx, rsi
    looper:
        cmp byte[rdi], 0
            je diffrdi
        cmp byte[rcx], 0
            je diffrcx
        mov byte sil, [rcx]
        cmp byte[rdi], sil
            jne diff
        inc rdi
        inc rcx
        jmp looper

    diff:
        mov rsi, 0
        mov sil, byte[rdi]
        mov rdi, 0
        mov dil, byte[rcx]
        sub rsi, rdi
        mov rax, rsi
        jmp end

    diffrdi:
        cmp byte[rcx], 0
            jne diff
        mov rax, 0
        jmp end

    diffrcx:
        cmp byte[rdi], 0
            jne diff
        mov rax, 0
        jmp end

    end:
        mov rsp, rbp
        pop rbp
    ret

