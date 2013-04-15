[BITS 64]

    global strcspn

    section .text

strcspn:
    push rbp
    mov rbp, rsp

    mov rax, 0
    looper:
        xor rdx, rdx
        mov dl, byte[rdi]
        cmp dl, 0
            je end
        mov rcx, rsi
        inc rax
        subloop:
            cmp byte[rcx], 0
                je continue
            cmp dl, byte[rcx]
                je end
            inc rcx
            jmp subloop
        continue:
            inc rdi
            jmp looper

    end:
        mov rsp, rbp
        pop rbp
    ret
