.global length
.global cat

.text

@ uint32_t length(char str[]);
@    R0					R0
length:
	MOV R1, R0
	MOV R0, #0
loop:
	LDRB R2, [R1], #1 @ post-index, i++
	CMP R2, #0 @ null-terminator
	BEQ backToC
	ADD R0, R0, #1
	B loop
	
backToC:
	BX LR


@ char * cat(char dest[], char src[]);
@      R0		R0			R1
cat:
	MOV R2, R0 @ R0 is still being held with the char dest[], and we are just oing all the manipulation by copuing it into R2
cat_loop1:
	LDRB R3, [R2], #1 @ post-index, i++
	CMP R3, #0 @ Check for null-terminator
	BNE cat_loop1  @ we will reach the end of the dest string 
	SUB R2, R2, #1
cat_loop2:
	LDRB R3, [R1], #1  @ As we came to know the end of the array, we care going to coppy what is in R1, beginning in that address. 
	STRB R3, [R2], #1  @ STRB command is read from the left to right.[ Jump off where the first string ends, and then copy the item present in [R2]
	CMP R3, #0 @ Check for null-terminator in the second string 
	BNE cat_loop2
	BX LR
