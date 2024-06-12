section .note.GNU-stack

section .text
global func_a
; f(x) = ln(x)
func_a:
    push ebp
    mov ebp, esp
    finit
    fldln2
    fld qword[esp + 8]
    fyl2x
    leave
    ret

global func_a_der
; f(x) = 1/x
func_a_der:
    push ebp
    mov ebp, esp
    finit
    fld1
    fld qword[esp + 8]
    fdiv
    leave
    ret
