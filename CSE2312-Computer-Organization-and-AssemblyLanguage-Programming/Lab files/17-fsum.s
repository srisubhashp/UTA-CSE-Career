.global fsum

.text

@It is important to assign the inital values of the registers to 0, before using them. 

@   D0              R0        R1
@ double fsum(double x[], uint32_t count);
@ R0 = address of array, R1 = count

fsum:
	MOV R2, #0
	@ Below, we cannot do the same thing in VFP as we do with other registers.
	@First R2 - the lower order bits of D0; & the second will be higher order bits of D0. Hence we have to copy R2 twice. 
	VMOV D0, R2, R2 @ Zero out all 64 
	
	@This is acting as a Cumulator
	
fsum_loop:
	CMP R1, #0 @ test counter
	BEQ fsum_end @ if counter is zero, jump to exit

	@This is a deviation of how we do this with the main processor 
	@Unlike the main CPu we have to be expplicit about the 

	VLDR.F64 D1, [R0] @ Load value at R0 into D1
	VADD.F64 D0, D0, D1 @ add the contents of D0 to D1.
	SUB R1, R1, #1 @ Decrement counter
	ADD R0, R0, #8 @ Move forward 64-bits. As memory is byte (8 bits) addressed.
	B fsum_loop

fsum_end:
	BX LR
