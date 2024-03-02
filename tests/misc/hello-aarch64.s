	.arch armv8-a
	.file	"hello.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"Hello from ARM with sum %ld\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB6:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	mov	x0, 7
	str	x0, [sp, 24]
	mov	x0, 8
	str	x0, [sp, 32]
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 32]
	add	x0, x1, x0
	str	x0, [sp, 40]
	ldr	x1, [sp, 40]
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	printf
	mov	w0, 0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
