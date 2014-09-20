;##
; Author: Yuriy Nazarov
;##

section .data

section .text

global puts
puts:
	push rbp
	mov  rbp, rsp

	mov  rsi, rdi ;pointer

;strlen
	xor  al, al   ;'\0'
	xor  rcx, rcx
	not  rcx
	cld
repne scasb
	not  rcx
	dec  rcx

	mov  rdi, 1   ;STDOUT
	mov  rdx, rcx ;len
	mov  rax, 1   ;sys_write
	syscall

	pop rbp
	ret
