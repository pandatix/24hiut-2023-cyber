	.file	"casmir.c"
	.intel_syntax noprefix
# GNU C17 (GCC) version 12.2.1 20230201 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 12.2.1 20230201, GMP version 6.2.1, MPFR version 4.2.0, MPC version 1.3.1, isl version isl-0.25-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -masm=intel -mtune=generic -march=x86-64
	.text
	.section	.rodata
.LC0:
	.string	"Usage : ./casmir <FLAG>"
	.align 8
.LC1:
	.string	"Bien joue vous pouvez validez avec le flag %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 32	#,
	mov	DWORD PTR -20[rbp], edi	# argc, argc
	mov	QWORD PTR -32[rbp], rsi	# argv, argv
# casmir.c:6:     if (argc != 2) {
	cmp	DWORD PTR -20[rbp], 2	# argc,
	je	.L2	#,
# casmir.c:7:         printf("Usage : ./casmir <FLAG>\n");
	lea	rax, .LC0[rip]	# tmp131,
	mov	rdi, rax	#, tmp131
	call	puts@PLT	#
# casmir.c:8:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L2:
# casmir.c:10:     char *flag = argv[1];
	mov	rax, QWORD PTR -32[rbp]	# tmp132, argv
	mov	rax, QWORD PTR 8[rax]	# tmp133, MEM[(char * *)argv_52(D) + 8B]
	mov	QWORD PTR -8[rbp], rax	# flag, tmp133
# casmir.c:14:     if(strlen(flag) != 18)
	mov	rax, QWORD PTR -8[rbp]	# tmp134, flag
	mov	rdi, rax	#, tmp134
	call	strlen@PLT	#
# casmir.c:14:     if(strlen(flag) != 18)
	cmp	rax, 18	# _1,
	je	.L4	#,
# casmir.c:15:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L4:
# casmir.c:17:     if(flag[0] != 0x32)
	mov	rax, QWORD PTR -8[rbp]	# tmp135, flag
	movzx	eax, BYTE PTR [rax]	# _2, *flag_53
# casmir.c:17:     if(flag[0] != 0x32)
	cmp	al, 50	# _2,
	je	.L5	#,
# casmir.c:18:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L5:
# casmir.c:19:     if(flag[1] != 0x34)
	mov	rax, QWORD PTR -8[rbp]	# tmp136, flag
	add	rax, 1	# _3,
	movzx	eax, BYTE PTR [rax]	# _4, *_3
# casmir.c:19:     if(flag[1] != 0x34)
	cmp	al, 52	# _4,
	je	.L6	#,
# casmir.c:20:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L6:
# casmir.c:21:     if(flag[2] != 0x48)
	mov	rax, QWORD PTR -8[rbp]	# tmp137, flag
	add	rax, 2	# _5,
	movzx	eax, BYTE PTR [rax]	# _6, *_5
# casmir.c:21:     if(flag[2] != 0x48)
	cmp	al, 72	# _6,
	je	.L7	#,
# casmir.c:22:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L7:
# casmir.c:23:     if(flag[3] != 0x49)
	mov	rax, QWORD PTR -8[rbp]	# tmp138, flag
	add	rax, 3	# _7,
	movzx	eax, BYTE PTR [rax]	# _8, *_7
# casmir.c:23:     if(flag[3] != 0x49)
	cmp	al, 73	# _8,
	je	.L8	#,
# casmir.c:24:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L8:
# casmir.c:25:     if(flag[4] != 0x55)
	mov	rax, QWORD PTR -8[rbp]	# tmp139, flag
	add	rax, 4	# _9,
	movzx	eax, BYTE PTR [rax]	# _10, *_9
# casmir.c:25:     if(flag[4] != 0x55)
	cmp	al, 85	# _10,
	je	.L9	#,
# casmir.c:26:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L9:
# casmir.c:27:     if(flag[5] != 0x54)
	mov	rax, QWORD PTR -8[rbp]	# tmp140, flag
	add	rax, 5	# _11,
	movzx	eax, BYTE PTR [rax]	# _12, *_11
# casmir.c:27:     if(flag[5] != 0x54)
	cmp	al, 84	# _12,
	je	.L10	#,
# casmir.c:28:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L10:
# casmir.c:29:     if(flag[6] != '{')
	mov	rax, QWORD PTR -8[rbp]	# tmp141, flag
	add	rax, 6	# _13,
	movzx	eax, BYTE PTR [rax]	# _14, *_13
# casmir.c:29:     if(flag[6] != '{')
	cmp	al, 123	# _14,
	je	.L11	#,
# casmir.c:30:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L11:
# casmir.c:31:     if((flag[7] ^ 'A') != 117)
	mov	rax, QWORD PTR -8[rbp]	# tmp142, flag
	add	rax, 7	# _15,
	movzx	eax, BYTE PTR [rax]	# _16, *_15
# casmir.c:31:     if((flag[7] ^ 'A') != 117)
	cmp	al, 52	# _16,
	je	.L12	#,
# casmir.c:32:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L12:
# casmir.c:33:     if((flag[8] - '0') != 5)
	mov	rax, QWORD PTR -8[rbp]	# tmp143, flag
	add	rax, 8	# _17,
	movzx	eax, BYTE PTR [rax]	# _18, *_17
# casmir.c:33:     if((flag[8] - '0') != 5)
	cmp	al, 53	# _18,
	je	.L13	#,
# casmir.c:34:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L13:
# casmir.c:35:     if((flag[9] + 25 != 102))
	mov	rax, QWORD PTR -8[rbp]	# tmp144, flag
	add	rax, 9	# _19,
	movzx	eax, BYTE PTR [rax]	# _20, *_19
# casmir.c:35:     if((flag[9] + 25 != 102))
	cmp	al, 77	# _20,
	je	.L14	#,
# casmir.c:36:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L14:
# casmir.c:37:     if((flag[10] - '2') != '-')
	mov	rax, QWORD PTR -8[rbp]	# tmp145, flag
	add	rax, 10	# _21,
	movzx	eax, BYTE PTR [rax]	# _22, *_21
# casmir.c:37:     if((flag[10] - '2') != '-')
	cmp	al, 95	# _22,
	je	.L15	#,
# casmir.c:38:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L15:
# casmir.c:39:     if((flag[11] / 2) != 28)
	mov	rax, QWORD PTR -8[rbp]	# tmp146, flag
	add	rax, 11	# _23,
	movzx	eax, BYTE PTR [rax]	# _24, *_23
# casmir.c:39:     if((flag[11] / 2) != 28)
	sub	eax, 56	# _26,
# casmir.c:39:     if((flag[11] / 2) != 28)
	cmp	al, 1	# _26,
	jbe	.L16	#,
# casmir.c:40:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L16:
# casmir.c:41:     if((flag[12] * 2)!= 102)
	mov	rax, QWORD PTR -8[rbp]	# tmp147, flag
	add	rax, 12	# _27,
	movzx	eax, BYTE PTR [rax]	# _28, *_27
# casmir.c:41:     if((flag[12] * 2)!= 102)
	cmp	al, 51	# _28,
	je	.L17	#,
# casmir.c:42:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L17:
# casmir.c:43:     if((flag[13] - flag[14]) != 0)
	mov	rax, QWORD PTR -8[rbp]	# tmp148, flag
	add	rax, 13	# _29,
	movzx	edx, BYTE PTR [rax]	# _30, *_29
# casmir.c:43:     if((flag[13] - flag[14]) != 0)
	mov	rax, QWORD PTR -8[rbp]	# tmp149, flag
	add	rax, 14	# _31,
	movzx	eax, BYTE PTR [rax]	# _32, *_31
# casmir.c:43:     if((flag[13] - flag[14]) != 0)
	cmp	dl, al	# _30, _32
	je	.L18	#,
# casmir.c:44:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L18:
# casmir.c:45:     if(flag[14] != 't')
	mov	rax, QWORD PTR -8[rbp]	# tmp150, flag
	add	rax, 14	# _33,
	movzx	eax, BYTE PTR [rax]	# _34, *_33
# casmir.c:45:     if(flag[14] != 't')
	cmp	al, 116	# _34,
	je	.L19	#,
# casmir.c:46:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L19:
# casmir.c:47:     if(flag[15] != flag[12])
	mov	rax, QWORD PTR -8[rbp]	# tmp151, flag
	add	rax, 15	# _35,
	movzx	edx, BYTE PTR [rax]	# _36, *_35
# casmir.c:47:     if(flag[15] != flag[12])
	mov	rax, QWORD PTR -8[rbp]	# tmp152, flag
	add	rax, 12	# _37,
	movzx	eax, BYTE PTR [rax]	# _38, *_37
# casmir.c:47:     if(flag[15] != flag[12])
	cmp	dl, al	# _36, _38
	je	.L20	#,
# casmir.c:48:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L20:
# casmir.c:49:     if(flag[16] != (flag[15] + 63))
	mov	rax, QWORD PTR -8[rbp]	# tmp153, flag
	add	rax, 16	# _39,
	movzx	eax, BYTE PTR [rax]	# _40, *_39
	movsx	edx, al	# _41, _40
# casmir.c:49:     if(flag[16] != (flag[15] + 63))
	mov	rax, QWORD PTR -8[rbp]	# tmp154, flag
	add	rax, 15	# _42,
	movzx	eax, BYTE PTR [rax]	# _43, *_42
	movsx	eax, al	# _44, _43
# casmir.c:49:     if(flag[16] != (flag[15] + 63))
	add	eax, 63	# _45,
# casmir.c:49:     if(flag[16] != (flag[15] + 63))
	cmp	edx, eax	# _41, _45
	je	.L21	#,
# casmir.c:50:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L21:
# casmir.c:51:     if(flag[17] != '}')
	mov	rax, QWORD PTR -8[rbp]	# tmp155, flag
	add	rax, 17	# _46,
	movzx	eax, BYTE PTR [rax]	# _47, *_46
# casmir.c:51:     if(flag[17] != '}')
	cmp	al, 125	# _47,
	je	.L22	#,
# casmir.c:52:         return 1;
	mov	eax, 1	# _48,
	jmp	.L3	#
.L22:
# casmir.c:54:     printf("Bien joue vous pouvez validez avec le flag %s\n", flag);
	mov	rax, QWORD PTR -8[rbp]	# tmp156, flag
	mov	rsi, rax	#, tmp156
	lea	rax, .LC1[rip]	# tmp157,
	mov	rdi, rax	#, tmp157
	mov	eax, 0	#,
	call	printf@PLT	#
# casmir.c:56:     return 0;
	mov	eax, 0	# _48,
.L3:
# casmir.c:57: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.1 20230201"
	.section	.note.GNU-stack,"",@progbits
