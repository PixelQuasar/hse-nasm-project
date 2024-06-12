section .note.GNU-stack

section .text
global func_b
; f(x) = -2x + 14
func_b:
    push ebp
    mov ebp, esp
    sub esp, 8
    mov dword[esp], -2 ; a
    mov dword[esp + 4], 14 ; b
    finit
    fld qword[esp + 16]
    fild dword[esp]
    fmul
    fild dword[esp + 4]
    fadd
    leave
    ret

global func_b_der
; f(x) = -2
func_b_der:
    push ebp
    mov ebp, esp
    sub esp, 4
    mov dword[esp], -2
    finit
    fild dword[esp]
    leave
    ret
