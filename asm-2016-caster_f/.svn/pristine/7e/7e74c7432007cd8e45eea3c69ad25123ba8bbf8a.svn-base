[BITS 64]

    global strpbrk

    section .text

strpbrk:
    push rbp
    mov rbp, rsp

    mov rax, 0x0
    looper:
        xor rdx, rdx
        mov dl, byte[rdi]
        cmp dl, 0
            je end
        mov rcx, rsi
        subloop:
            cmp byte[rcx], 0
                je continue
            cmp dl, byte[rcx]
                je found
            inc rcx
            jmp subloop
        continue:
            inc rdi
            jmp looper

    found:
        mov rax, rdi
        jmp end

    end:
        mov rsp, rbp
        pop rbp
    ret
