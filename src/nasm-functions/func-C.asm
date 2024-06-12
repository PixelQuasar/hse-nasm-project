section .note.GNU-stack

section .text
global func_c
; f(x) = 1 / (2 - x) + 6
func_c:
    push ebp
    mov ebp, esp
    sub esp, 8
    mov dword[esp], 2
    mov dword[esp + 4], 6
    finit
    fld1
    fild dword[esp]
    fld qword[esp + 16]
    fsub
    fdiv
    fild dword[esp + 4]
    fadd
    leave
    ret

global func_c_der
; f(x) = 1 / (x^2 - 4x + 4)
func_c_der:
    push ebp
    mov ebp, esp
    sub esp, 4
    mov dword[esp], 4
    finit
    fld1
    fld qword[esp + 12]
    fld qword[esp + 12]
    fmul
    fld qword[esp + 12]
    fild dword[esp]
    fmul
    fsub
    fild dword[esp]
    fadd
    fdiv
    leave
    ret
