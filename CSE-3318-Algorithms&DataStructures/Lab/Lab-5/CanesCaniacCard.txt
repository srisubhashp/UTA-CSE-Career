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

@ input: array (x) containing count entries
@ output: array (x), with the values sorted in descending order
@ void sortDecendingInPlace (int16_t x[], uint32_t count);
@ R0                                 R0            R1
sortDecendingInPlace:
	PUSH {R2-R6,LR}
	MOV R2, R0 @ save array beginning address
	MOV R3, R1 @ save count
sortDecendingInPlace_setup:
	MOV R0, R2
	MOV R1, R3
	MOV R6, #0 @ if element not found sorted
	LDRSH R4, [R0], #2
	SUB R1, R1, #1
sortDecendingInPlace_loop:
	LDRSH R5, [R0]
	CMP R4, R5
	BLT sortDecendingInPlace_swap
	B sortDecendingInPlace_check
sortDecendingInPlace_swap:
	MOV R6, #1
	STRH R4, [R0]
	SUB R0, R0, #2
	STRH R5, [R0]
	ADD R0, R0, #2
	B sortDecendingInPlace_check
sortDecendingInPlace_check:
	SUB R1, R1, #1
	CMP R1, #0
	LDRSH R4, [R0], #2
	BNE sortDecendingInPlace_loop
	CMP R6, #0
	BEQ sortDecendingInPlace_end
	B sortDecendingInPlace_setup
sortDecendingInPlace_end:
	POP {R2-R6,PC}
	BX LR

@ returns the sum of the elements in an array (x) containing count entries
@ float sumF32(float x[], uint32_t count)
@ S0                 R0            R1
sumF32:
	MOV R2, #0
	VMOV S0, R2
sumF32_loop:
	CMP R1, #0
	BEQ sumF32_end
	VLDR.F32 S1, [R0]
	VADD.F32 S0, S0, S1
	SUB R1, R1, #1
	ADD R0, R0, #4
	B sumF32_loop
sumF32_end:
	BX LR

@ returns the product of the elements in an array (x) containing count entries
@ double prodF64(double x[], uint32_t count)
@ D0                    R0            R1
prodF64:
	VLDR.F64 D0, [R0]
	SUB R1, R1, #1
	ADD R0, R0, #8
prodF64_loop:
	CMP R1, #0
	BEQ sumF32_end
	VLDR.F64 D1, [R0]
	VMUL.F64 D0, D0, D1
	SUB R1, R1, #1
	ADD R0, R0, #8
	B prodF64_loop
prodF64_end:
	BX LR
BX LR

@ returns the dot product of two arrays (x and y) containing count entries
@ double dotpF64(double x[], double y[], uint32_t count)
@ D0                    R0          R1            R2
dotpF64:
	MOV R3, #0
	VMOV D2, R3, R3
	VLDR.F64 D0, [R0]
	VLDR.F64 D1, [R1]
	VMUL.F64 D0, D0, D1
	SUB R2, R2, #1
	ADD R0, R0, #8
	ADD R1, R1, #8 
dotpF64_loop:
	CMP R2, #0
	BEQ dotpF64_end
	VLDR.F64 D1, [R0]
	VLDR.F64 D2, [R1]
	VMUL.F64 D1, D1, D2
	VADD.F64 D0, D0, D1
	SUB R2, R2, #1
	ADD R0, R0, #8
	ADD R1, R1, #8
	B dotpF64_loop
dotpF64_end:
	BX LR

@ returns the maximum value in the array (x) containing count entries
@ float maxF32(float x[], uint32_t count)
@ S0                 R0            R1
maxF32:
	VLDR.F32 S0, [R0]
	SUB R1, R1, #1
	ADD R0, R0, #4
	B maxF32_loop
maxF32_loop:
	CMP R1, #0
	BEQ maxF32_end
	SUB R1, R1, #1
	VLDR.F32 S1, [R0]
	ADD R0, R0, #4
	VCMP.F32 S0, S1
	VMOVGT.F32 S0, S1
	B maxF32_loop
maxF32_end:
	BX LR

@ input: array (x) containing count double entries
@ output: the absolute value of the sum of the elements in array (x) containing count entries
@ double absSumF64 (double x[], uint32_t count)
@ D0                       R0            R1
absSumF64:
	MOV R2, #0
	VMOV D0, R2, R2
	VMOV D1, R2, R2
absSumF64_loop:
	CMP R1, #0
	BEQ absSumF64_end
	VLDR.F64 D1, [R0]
	VADD.F64 D0, D0, D1
	SUB R1, R1, #1
	ADD R0, R0, #8
	B absSumF64_loop
absSumF64_end:
	VABS.F64 D0, D0
	BX LR

@ input: array (x) containing count double entries
@ output: the square root of the sum of the elements in array (x) containing count entries
@ double sqrtSumF64(double x[], uint32_t count)
@ D0                       R0            R1
sqrtSumF64:
	MOV R2, #0
	VMOV D0, R2, R2
	VMOV D1, R2, R2
sqrtSumF64_loop:
	CMP R1, #0
	BEQ sqrtSumF64_end
	VLDR.F64 D1, [R0]
	VADD.F64 D0, D0, D1
	SUB R1, R1, #1
	ADD R0, R0, #8
	B sqrtSumF64_loop
sqrtSumF64_end:
	VSQRT.F64 D0, D0
	BX LR

@ input: array of BUSINESS structs and index of BUSINESS
@ output: street direction of BUSINESS (e.g., ‘N’, ‘S’, ‘E’, ‘W’)
@ char getDirection (BUSINESS business[], uint32_t index)
@ R0                          R0                   R1
getDirection:
    MOV R3, #120
    MUL R2, R1, R3
    ADD R0, R0, #44
	ADD R0, R0, R2
    LDR R0, [R0]
    BX LR

@ input: array of BUSINESS structs and index of BUSINESS
@ output: address number of business
@ uint32_t getAddNo (BUSINESS business[], uint32_t index)
@ R0                          R0                   R1
getAddNo:
    MOV R3, #120
    MUL R2, R1, R3
    ADD R0, R0, #40
	ADD R0, R0, R2
    LDR R0, [R0]
    BX LR

@ input: array of BUSINESS structs and index of BUSINESS
@ output: city name of BUSINESS
@ char * getCity(BUSINESS business[], uint32_t index)
@ R0                      R0                   R1
getCity:
    MOV R3, #120
    MUL R2, R1, R3
    ADD R0, R0, #78
    ADD R0, R0, R2
    BX LR
