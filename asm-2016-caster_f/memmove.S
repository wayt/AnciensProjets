[BITS 64]

    global memmove

    section .text

memmove:
    push rbp
    mov rbp, rsp

    
    mov rsp, rbp
    pop rbp

    ret
