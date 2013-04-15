[BITS 64]
    global strchr

    section .text

strchr:
    push rbp
    mov rbp, rsp

    mov rax, 0x0
    mov rdx, rdi
    looper:
        cmp byte[rdx], 0
            je end
        cmp byte[rdx], sil
            je find
    continue:
        inc rdx
        jmp looper

    find:
        mov rax, rdx
        jmp end
    end:
        mov rsp, rbp
        pop rbp

    ret
