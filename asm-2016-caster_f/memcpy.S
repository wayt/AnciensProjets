[BITS 64]

    global memcpy

    section .text

memcpy:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    mov rcx, rsi
    looper:
        cmp rdx, 0
            je end

        mov byte sil, [rcx]
        mov byte[rdi], sil
        inc rdi
        inc rcx
        dec rdx
        jmp looper

    end:
        mov rsp, rbp
        pop rbp
    ret
