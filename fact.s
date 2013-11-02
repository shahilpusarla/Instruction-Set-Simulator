.LC0:
	.string	"%d" 
.LC1:
	.string	"The factorial is %d"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	$1, 24(%esp)
	leal	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$1, 20(%esp)
	jmp	.L2
.L3:
	movl	24(%esp), %eax
	imull	20(%esp), %eax
	movl	%eax, 24(%esp)
	addl	$1, 20(%esp)
.L2:
	movl	28(%esp), %eax
	cmpl	%eax, 20(%esp)
	jle	.L3
	movl	$.LC1, %eax
	movl	24(%esp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
