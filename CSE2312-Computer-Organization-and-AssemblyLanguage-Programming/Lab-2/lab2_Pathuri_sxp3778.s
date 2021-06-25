@Sri Subhash Pathuri
@UTA-Id: 1001733778
@CSE 2312-003

.global stringCopy
.global stringCat
.global sumS32
.global sumS16
.global sumU32_64
.global countNegative
.global countNonNegative
.global countMatches
.global returnMax
.global returnMin

.text 

@Q1        R0                  R0          R1                 
@extern void stringCopy(char* strTo, char* strFrom); // copies strFrom to strTo
stringCopy:
	LDRB R2,[R1], #1
	STRB R2,[R0], #1
	CMP R2,#0
	BNE stringCopy
	BX LR

@----------------------------------------------------------
@Q2            R0               R0            R1
@extern void stringCat(char* strFrom, char* strTo); // adds strFrom to end of strTo
stringCat:
	MOV R2,R1
cat_loop1:
	LDRB R3,[R2],#1
	CMP R3,#0
	BNE cat_loop1
	SUB R2,R2,#1
cat_loop2:
	LDRB R3,[R0],#1
	STRB R3,[R2],#1
	CMP R3,#0
	BNE cat_loop2
	MOV R0,R2
	BX LR
@------------------------------------------------------------
@Q3       R0                  R0         R1
@extern int32_t sumS32(int32_t x[], int32_t count);
sumS32:
	MOV R2, R0
	MOV R0,#0

sumS32loop:
	CMP R1,#0
	BEQ sectionEnd
	LDR R4,[R2],#4
	ADD R0,R4
	SUB R1,R1,#1
	B sumS32loop

sectionEnd:
	BX LR

@------------------------------------------------------------
@Q4            R0            R0        R1        
@extern int32_t sumS16(int16_t x[], int32_t count);
sumS16:
	MOV R2, R0
	MOV R0,#0

sumS16loop:
	CMP R1,#0
	BEQ sectionEnd2
	LDRSB R4,[R2],#2
	ADD R0,R4
	SUB R1,R1,#1
	B sumS16loop

sectionEnd2:
	BX LR

@-------------------------------------------------------------
@Q5      R1:R0                  R0                R1
@extern uint64_t sumU32_64(uint32_t x[], uint32_t count);
sumU32_64:
	MOV R2,R0
	MOV R3,R1 
	MOV R0,#0
	MOV R1,#0
sumU32_64_loop:
	CMP R3,#0
	BEQ end3
	LDR R4,[R2],#4
	ADDS R0,R0,R4
	ADC R1,R1,#0
	SUBS R3,R3,#1
	B sumU32_64_loop
end3: 
	BX LR

@----------------------------------------------------------------
@Q6        R0                         R0            R1
@extern uint32_t countNegative (int16_t x[], uint32_t count);
countNegative:
	MOV R2,R0
	MOV R0,#0
	
	B loop_negative
loop_negative:
	LDRSB R3,[R2],#2
	CMP R3,#0
	ADDMI R0,R0,#1
	SUB R1,R1,#1
	CMP R1,#0
	BNE loop_negative
	BX LR
@---------------------------------------------------------------	
@Q7              R0                      R0          R1
@extern uint32_t countNonNegative (int16_t x[], uint32_t count);
countNonNegative:
	MOV R2,R0
	MOV R0,#0
	
	B loop_nonNegative
loop_nonNegative:
	LDRSB R3,[R2],#2
	CMP R3,#0
	ADDPL R0,R0,#1
	SUB R1,R1,#1
	CMP R1,#0
	BNE loop_nonNegative
	BX LR

@----------------------------------------------------------
@Q8         R0                    R0            R1
@extern uint32_t countMatches(char str[], char toMatch);
countMatches:
	MOV R2,R0
	MOV R0,#0
	
	B loop_countMatches
loop_countMatches:
	LDRB R3,[R2],#1
	CMP R3,#0
	BEQ end4
	CMP R3,R1
	ADDEQ R0,R0,#1
	B loop_countMatches
end4:
	BX LR

@--------------------------------------------------------
@Q10             R0                 R0           R1
@extern int32_t returnMin(int16_t x[], uint32_t count);
returnMin:
	MOV R2,R0
	LDRSH R0,[R2],#2
	SUB R1,R1,#1
	B loop_returnMin
loop_returnMin:
	CMP R1,#0
	
	BEQ end6
	SUB R1,R1,#1
	LDRSH R3,[R2],#2
	CMP R3,R0
	MOVLT R0,R3
	B loop_returnMin
	
end6:
	BX LR
	
@----------------------------------------------------------
@Q9              R0            R0           R1
@extern int32_t returnMax(int16_t x[], uint32_t count);
returnMax:
	MOV R2,R0
	MOV R0,#0
	LDRSH R3,[R2],#2
	SUB R1,R1,#1
	B loop_returnMax
loop_returnMax:
	CMP R3,#0
	BEQ end5
	CMP R3,R0
	MOVGT R0,R3
	LDRSH R3,[R2],#2
	SUB R1,R1,#1
	CMP R1,#0
	
	BNE loop_returnMax
	
end5:
	BX LR

