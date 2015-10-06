	.file	"hash.c"
	.comm	_select, 4, 2
	.comm	_size, 80, 5
	.comm	_array, 80, 5
	.text
	.globl	_initialise
	.def	_initialise;	.scl	2;	.type	32;	.endef
_initialise:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L2
L3:
	movl	-4(%ebp), %eax
	movl	$0, _array(,%eax,4)
	movl	-4(%ebp), %eax
	movl	$0, _size(,%eax,4)
	incl	-4(%ebp)
L2:
	cmpl	$9, -4(%ebp)
	jle	L3
	leave
	ret
	.globl	_hfunction
	.def	_hfunction;	.scl	2;	.type	32;	.endef
_hfunction:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	_select, %eax
	cmpl	$1, %eax
	jne	L5
	movl	8(%ebp), %eax
	movl	$10, %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	jmp	L6
L5:
	fildl	8(%ebp)
	fldl	LC0
	fmulp	%st, %st(1)
	fnstcw	-22(%ebp)
	movw	-22(%ebp), %ax
	movb	$12, %ah
	movw	%ax, -24(%ebp)
	fldcw	-24(%ebp)
	fistpl	-4(%ebp)
	fldcw	-22(%ebp)
	fildl	8(%ebp)
	fldl	LC0
	fmulp	%st, %st(1)
	fildl	-4(%ebp)
	fsubrp	%st, %st(1)
	fstps	-8(%ebp)
	flds	-8(%ebp)
	flds	LC1
	fmulp	%st, %st(1)
	fstps	-8(%ebp)
	flds	-8(%ebp)
	fldcw	-24(%ebp)
	fistpl	-4(%ebp)
	fldcw	-22(%ebp)
	movl	-4(%ebp), %eax
L6:
	leave
	ret
	.globl	_generate
	.def	_generate;	.scl	2;	.type	32;	.endef
_generate:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	_rand
	movl	$900000, %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	addl	$100000, %eax
	leave
	ret
	.section .rdata,"dr"
LC3:
	.ascii "->\0"
LC4:
	.ascii "%d->\0"
	.text
	.globl	_display
	.def	_display;	.scl	2;	.type	32;	.endef
_display:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L10
L15:
	movl	-12(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L13
	movl	$LC3, (%esp)
	call	_puts
	jmp	L12
L14:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -16(%ebp)
L13:
	cmpl	$0, -16(%ebp)
	jne	L14
	movl	$10, (%esp)
	call	_putchar
L12:
	incl	-12(%ebp)
L10:
	cmpl	$9, -12(%ebp)
	jle	L15
	leave
	ret
	.globl	_insert
	.def	_insert;	.scl	2;	.type	32;	.endef
_insert:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_hfunction
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	_size(,%eax,4), %eax
	testl	%eax, %eax
	jne	L17
	movl	-12(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, _size(,%eax,4)
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-16(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, _array(,%eax,4)
	jmp	L16
L17:
	movl	-12(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	1(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, _size(,%eax,4)
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	_array(,%eax,4), %edx
	movl	-16(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	-12(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, _array(,%eax,4)
L16:
	leave
	ret
	.globl	_search
	.def	_search;	.scl	2;	.type	32;	.endef
_search:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_hfunction
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	%eax, -4(%ebp)
	jmp	L20
L23:
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L21
	movl	8(%ebp), %eax
	jmp	L22
L21:
	movl	-4(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -4(%ebp)
L20:
	cmpl	$0, -4(%ebp)
	jne	L23
	movl	$-1, %eax
L22:
	leave
	ret
	.section .rdata,"dr"
LC5:
	.ascii "the sizes of slots are:\12\0"
LC6:
	.ascii "%d\12\0"
	.text
	.globl	_sizedisplay
	.def	_sizedisplay;	.scl	2;	.type	32;	.endef
_sizedisplay:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$LC5, (%esp)
	call	_puts
	movl	$0, -12(%ebp)
	jmp	L25
L26:
	movl	-12(%ebp), %eax
	movl	_size(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	incl	-12(%ebp)
L25:
	cmpl	$9, -12(%ebp)
	jle	L26
	movl	$10, (%esp)
	call	_putchar
	leave
	ret
	.section .rdata,"dr"
LC7:
	.ascii "element not found in table\0"
	.text
	.globl	_deletenode
	.def	_deletenode;	.scl	2;	.type	32;	.endef
_deletenode:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_hfunction
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	testl	%eax, %eax
	jne	L30
	movl	$LC7, (%esp)
	call	_puts
	jmp	L27
L33:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	je	L38
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -12(%ebp)
L30:
	cmpl	$0, -12(%ebp)
	jne	L33
	jmp	L32
L38:
	nop
L32:
	cmpl	$0, -12(%ebp)
	jne	L34
	movl	$LC7, (%esp)
	call	_puts
	jmp	L27
L34:
	movl	-16(%ebp), %eax
	movl	_array(,%eax,4), %eax
	cmpl	-12(%ebp), %eax
	jne	L35
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	cmpl	$1, %eax
	jne	L36
	movl	-16(%ebp), %eax
	movl	$0, _array(,%eax,4)
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	-1(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, _size(,%eax,4)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	jmp	L27
L36:
	movl	-16(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	8(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, _array(,%eax,4)
	movl	-16(%ebp), %eax
	movl	_array(,%eax,4), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	-1(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, _size(,%eax,4)
	jmp	L27
L35:
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	jne	L37
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	$0, 8(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	-1(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, _size(,%eax,4)
	jmp	L27
L37:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	-12(%ebp), %edx
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	movl	_size(,%eax,4), %eax
	leal	-1(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, _size(,%eax,4)
L27:
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC8:
	.ascii "initialising hash table\0"
	.align 4
LC9:
	.ascii "which hash funtion do you want ? \0"
	.align 4
LC10:
	.ascii "1. key % 10\12"
	.ascii "2.step of 10*( (key*A) mod 1)\12\0"
LC11:
	.ascii "%d\0"
	.align 4
LC12:
	.ascii "\12status of the table after inserting 20 random numbers into the table\0"
LC13:
	.ascii "\12\0"
	.align 4
LC14:
	.ascii "1.insert a registration number\0"
	.align 4
LC15:
	.ascii "2.delete a registration number\0"
	.align 4
LC16:
	.ascii "3.search for a registration number\0"
	.align 4
LC17:
	.ascii "4.display the sizes of hash table slots\0"
	.align 4
LC18:
	.ascii "5.display the entire hash table\0"
LC19:
	.ascii "6.exit\0"
LC20:
	.ascii "enter a number to insert\0"
LC21:
	.ascii "enter a number to delete\0"
LC22:
	.ascii "number to search? : \0"
LC23:
	.ascii "element is in hash table\0"
LC24:
	.ascii "its not there in hash table\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$LC8, (%esp)
	call	_puts
	call	_initialise
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_printf
	movl	$_select, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	$0, 28(%esp)
	jmp	L40
L41:
	call	_generate
	movl	%eax, (%esp)
	call	_insert
	incl	28(%esp)
L40:
	cmpl	$19, 28(%esp)
	jle	L41
	movl	$LC12, (%esp)
	call	_puts
	call	_display
	movl	$LC13, (%esp)
	call	_puts
	jmp	L50
L52:
	nop
L50:
	movl	$LC14, (%esp)
	call	_puts
	movl	$LC15, (%esp)
	call	_puts
	movl	$LC16, (%esp)
	call	_puts
	movl	$LC17, (%esp)
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	movl	$LC19, (%esp)
	call	_puts
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	cmpl	$1, %eax
	jne	L42
	movl	$LC20, (%esp)
	call	_puts
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	_insert
	movl	$10, (%esp)
	call	_putchar
	movl	$10, (%esp)
	call	_putchar
	jmp	L52
L42:
	movl	24(%esp), %eax
	cmpl	$2, %eax
	jne	L44
	movl	$LC21, (%esp)
	call	_puts
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	_deletenode
	movl	$10, (%esp)
	call	_putchar
	movl	$10, (%esp)
	call	_putchar
	jmp	L52
L44:
	movl	24(%esp), %eax
	cmpl	$3, %eax
	jne	L45
	movl	$LC22, (%esp)
	call	_printf
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_scanf
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	_search
	movl	20(%esp), %edx
	cmpl	%edx, %eax
	jne	L46
	movl	$LC23, (%esp)
	call	_puts
	jmp	L52
L46:
	movl	$LC24, (%esp)
	call	_puts
	jmp	L52
L45:
	movl	24(%esp), %eax
	cmpl	$4, %eax
	jne	L47
	call	_sizedisplay
	jmp	L52
L47:
	movl	24(%esp), %eax
	cmpl	$5, %eax
	jne	L48
	call	_display
	jmp	L52
L48:
	movl	24(%esp), %eax
	cmpl	$6, %eax
	jne	L52
	nop
	movl	$0, %eax
	leave
	ret
	.section .rdata,"dr"
	.align 8
LC0:
	.long	-1202590843
	.long	1071875358
	.align 4
LC1:
	.long	1092616192
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
