@Sri Subhash Pathuri
@UTA-Id: 1001733778
@CSE 2312-003

@Lab Assignment 3s

.global sortDecendingInPlace
.global sumF32
.global prodF64
.global dotpF64
.global maxF32
.global absSumF64
.global sqrtSumF64
.global getDirection
.global getAddNo
.global getCity

.text

@1. extern void sortDecendingInPlace (int16_t x[], uint32_t count);
@                R0                           R0          R1
@Input Array contains the values to be sorted in the descending order
@The array which be the output will contains the elements sorted in descending order

sortDecendingInPlace: 
	PUSH {R2-R6,LR}
	MOV R2,R0 
	@ stores the starting addressof the arrray
	MOV R3, R1 
	@ saves the number of elments i another register

sDinPlace_initial:
	MOV R0, R2
	MOV R1, R3
	MOV R6, #0 
	@ if the desired element is not found at the sorted position
	LDRSH R4, [R0], #2
	@ Below: decrementing the counter for the function to continue till it reaches the end
	SUB R1, R1, #1
	
sDinPlace_loop:
	LDRSH R5, [R0]
	CMP R4, R5
	BLT sDinPlace_exchange
	B sDinPlace_confirm
	
sDinPlace_exchange:
	MOV R6, #1
	STRH R4, [R0]
	SUB R0, R0, #2
	STRH R5, [R0]
	ADD R0, R0, #2
	@Swapping the values in each phase so that the elements positioned in descending order
	B sDinPlace_confirm
	
sDinPlace_confirm:
	SUB R1, R1, #1
	CMP R1, #0
	LDRSH R4,[R0],#2@ we are loading the values from the address
	BNE sDinPlace_loop
	
	CMP R6, #0
	BEQ sDinPlace_end
	B sDinPlace_initial
	
sDinPlace_end:
	POP {R2-R6,PC}
	BX LR

@__________________________________________________________

@2. extern float sumF32(float x[], uint32_t count);
@							R0           R1
@ this function returns the collective sum of elements present in the input array of floating point values
@ this function returns the result of multiplications of element in an array

sumF32:
	MOV R2, #0
	MOV R3, #0
	VMOV S0, R2

f32_loop: 
	CMP R1,#0
	BEQ f32_end
	
	VLDR.F32 S1,[R0]
	VADD.F32 S0,S0,S1
	SUB R1,R1,#1
	ADD R0,R0,#4 @ bcz it is a floating point value and the size is 4 * 8=32 bytes
	B f32_loop
f32_end:
BX LR
	
@__________________________________________________________

@3. extern double prodF64(double x[], uint32_t count);
prodF64:
	MOV R2, #0
	VMOV D0,R2, R2
	VLDR.F64 D0, [R0]
	SUB R1, R1, #1
	ADD R0, R0, $8
	
f64_loop:	 
	CMP R1, #0
	BEQ f64_end
	
	VLDR.F64 D1,[R0]
	VMUL.F64 D0, D0, D1
	SUB R1, R1, #1
	ADD R0, R0, #8
	B f64_loop
	
f64_end:	
	BX LR

@_________________________________________________________	

@4. extern double dotpF64(double x[], double y[], uint32_t count);
dotpF64: 
	MOV R3, #0 
	VMOV D2, R3, R3
	VLDR.F64 D0, [R0]
	VLDR.F64 D1, [R1]
	VMUL.F64 D0, D0, D1
	SUB R2, R2, #1
	ADD R0, R0, #8
	ADD R1, R1, #8
dF64_loop:
	CMP R2,#0
	BEQ dF64_end
	
	VLDR.F64 D1, [R0]
	VLDR.F64 D2, [R1]
	VMUL.F64 D1, D1, D2
	VADD.F64 D0, D0, D1
	SUB R2, R2, #1
	ADD R0, R0, #8
	ADD R1, R1, #8 
	B dF64_loop
	
dF64_end:
	BX LR

@___________________________________________________________

@5. extern float maxF32(float x[], uint32_t count);
maxF32:
	VLDR.F32 S0, [R0]
	SUB R1, R1, #1
	ADD R0, R0, #4
	B mF32_loop
	
mF32_loop:
	CMP R1, #0
	BEQ mF32_coda
	SUB R1, R1, #1
	VLDR.F32 S1, [R0]
	ADD R0, R0, #4
	VCMP.F32 S0, S1
	VMOVGT.F32 S0, S1
	B mF32_loop

mF32_coda:
	BX LR
	
@___________________________________________________________

@6. extern double absSumF64 (double x[], uint32_t count);
absSumF64:
	MOV R2, #0
	VMOV D0, R2, R2
	VMOV D1, R2, R2

abs_loop:
	CMP R1, #0
	BEQ abs_coda
	VLDR.F64 D1,[R0]
	VADD.F64 D0, D0, D1
	SUB R1, R1, #1
	ADD R0, R0, #8
	B abs_loop
	
abs_coda:
	VABS.F64 D0, D0
	BX LR

@___________________________________________________________

@7. extern double sqrtSumF64(double x[], uint32_t count);
sqrtSumF64:
	MOV R2, #0
	VMOV D0, R2, R2
	VMOV D1, R2, R2
	
sqS_loop:
	CMP R1, #0
	BEQ sqS_end
	VLDR.F64 D1, [R0]
	VADD.F64 D0,D0,D1
	SUB R1,R1, #1
	ADD R0,R0, #8
	B sqS_loop

sqS_end:
	VSQRT.F64 D0, D0
	BX LR

@_______________________________________________________________

@8. extern char getDirection (BUSINESS business[], uint32_t index);
@                                   R0                  R1 
getDirection:
	MOV R3, #120
	MUL R2, R1, R3
	ADD R0, R0, #44
	ADD R0, R0, R2 
	LDR R0, [R0]
	BX LR

@___________________________________________________________

@9. extern uint32_t getAddNo (BUSINESS business[], uint32_t index);
@                                   R0                R1
getAddNo:
	MOV R3,#120
	MUL R2, R1, R3
	ADD R0, R0, #40
	ADD R0,R0, R2 
	LDR R0, [R0]
	BX LR
	
@______________________________________________________________

@10. extern char * getCity(BUSINESS business[], uint32_t index);
getCity:
MOV R2, #120
MUL R3, R1, R2
ADD R0, R0, #78
ADD R0, R3
BX LR

