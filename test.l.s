	.text
	.file	"IR Generator"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	movl	$0, -44(%rsp)
	.p2align	4, 0x90
.LBB0_1:                                # %for
                                        # =>This Inner Loop Header: Depth=1
	movslq	-44(%rsp), %rax
	leal	1(%rax), %ecx
	cmpq	$10, %rax
	movl	$1, -40(%rsp,%rax,4)
	movl	%ecx, -44(%rsp)
	jl	.LBB0_1
# %bb.2:                                # %afterfor
	xorl	%eax, %eax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function

	.section	".note.GNU-stack","",@progbits
