[BITS 64]

    global strcasecmp

    section .text
    extern puts

strcasecmp:

    push rbp
    mov rbp, rsp

    mov rcx, rsi
    mov rdx, rdi
    looper:
        cmp byte[rdx], 0
            je diffrdx
        cmp byte[rcx], 0
            je diffrcx
        xor rdi, rdi
        mov dil, byte[rdx]
        call lower
        mov r8, rax
        xor rdi, rdi
        mov dil, byte[rcx]
        call lower
        mov rsi, rax
        mov rdi, r8
        cmp dil, sil
            jne diff
        inc rdx
        inc rcx
        jmp looper

    diff:
        mov rsi, 0

        mov rdi, 0
        mov dil, byte[rdx]
        call lower
        mov rsi, rax

        mov rdi, 0
        mov dil, byte[rcx]
        call lower
        sub rsi, rax
        mov rax, rsi
        jmp end

    diffrdx:
        cmp byte[rcx], 0
            jne diff
        mov rax, 0
        jmp end

    diffrcx:
        cmp byte[rdx], 0
            jne diff
        mov rax, 0
        jmp end

    end:
        mov rsp, rbp
        pop rbp
    ret


lower:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rax, rdi
    cmp rdi, 65
        jge higha
    jmp enddeux

    higha:
        cmp rdi, 90
            jle lowz
        jmp enddeux
    lowz:
        add rax, 32
        jmp enddeux

    enddeux:
        mov rsp, rbp
        pop rbp
    ret

