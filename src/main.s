	.file	"main.cpp"
	.text
	.p2align 4
	.globl	_Zli2_sPKcm
	.type	_Zli2_sPKcm, @function
_Zli2_sPKcm:
.LFB16:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movl	%esi, %edx
	ret
	.cfi_endproc
.LFE16:
	.size	_Zli2_sPKcm, .-_Zli2_sPKcm
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB34:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$2, %edx
	movl	$1, %edi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	6(%rsp), %rsi
	movl	$2608, %eax
	movw	%ax, 6(%rsp)
	call	write@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L6
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 10.2.0-5ubuntu1~20.04) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
