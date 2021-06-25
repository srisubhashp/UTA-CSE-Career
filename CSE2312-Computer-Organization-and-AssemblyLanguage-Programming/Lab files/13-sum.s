.global sum

.text

@ uint16_t sum(uint16_t x[], uint16_t count);
@     R0			R0				R1

sum: @ R0 stores the first element of that particular array (2bytes) 
	MOV R2, R0 @ here as we are passing back a value, and not an R0 
	MOV R0, #0 
	
sum_loop:
	LDR R3, [R2], #4  @ pulling out of memory and storing it into R2
	ADD R0, R0, R3
	SUBS R1, R1, #1 @ i--
	BNE sum_loop
	BX LR

@ in a 16bit int, we are moving by 2 ( 2*8)=16 bits ; and for 32bit values, we are incrementing by (4*8)=32bits