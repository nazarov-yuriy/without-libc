;##
; Author: Yuriy Nazarov
;##

section .data

section .text

global exit
exit:
	mov rdi, rax
	mov rax, 60
	syscall
	ret
