[BITS 64]

    global strstr
    extern strlen
    extern strncmp

    section .text

strstr:
    push rbp
    mov rbp, rsp

    push rdi
    mov rdi, rsi
    call strlen wrt ..plt
    mov rdx, rax
    pop rdi
    mov rax, 0x0
    cmp rdx, 0
        je end
    looper:
        cmp byte[rdi], 0
            je end
        xor rcx, rcx
        mov cl, byte[rsi]
        cmp byte[rdi], cl
            je trycmp
    continue:
        inc rdi
        jmp looper
    
    trycmp:
        push rax
        push rdi
        push rsi
        call strncmp wrt ..plt
        mov rcx, rax
        pop rsi
        pop rdi
        pop rax
        cmp rcx, 0
            je found
        jmp continue
    
    found:
        mov rax, rdi
        jmp end
        
    end:
        mov rsp, rbp
        pop rbp
    ret
