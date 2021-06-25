@Sri Subhash Pathuri; UTA ID - 1001733778

.global add32
.global sub64
.global minU16
.global minS32
.global isLessThanU16
.global isLessThanS16
.global shiftLeftU16
.global shiftU32
.global shiftU32
.global shiftS8
.global isEqualU32
.global isEqualS8

.text

@ extern uint64_t add32(uint32_t x, uint32_t y); // returns x + y
@            R1:R0,         R0        R1

add32: 
	ADDS R0,R0,R1
	MOV R1,#0
	ADC R1,#0
	BX LR
@1-------------------------------------------------------------------------

@ extern uint64_t sub64(uint64_t x, uint64_t y); // returns x - y
@                R1:R0,      R1:R0,    R3:R2
sub64:
	SUBS R0,R0,R2	
	SBC R1,R1,R3
	BX LR
@2--------------------------------------------------------------------------
	
@ extern uint16_t minU16(uint16_t x, uint16_t y); // returns the minimum of x, y
@                   R0,         R0,    R1

minU16:
	CMP R1,R0
	MOVCC R0,R1
	BX LR
@3------------------------------------------------------------

@ extern int32_t minS32(int32_t x, int32_t y); // returns the minimum of x, y
@               R0,           R0       R1
minS32:
	CMP R1,R0
	MOVLT R0,R1
	BX LR
@4------------------------------------------------------------
	
@extern bool isLessThanU16(uint16_t x, uint16_t y); // returns 1 if x < y, 0 else
@                     R0        R0        R1
isLessThanU16:
	CMP R0,R1
	MOVCC R0, #1
	MOVCS R0, #0
	BX LR

@5--------------------------------------------------------------------
@extern bool isLessThanS16(int16_t x, int16_t y); // returns 1 if x < y, 0 else

isLessThanS16:
	CMP R0,R1
	MOVLT R0, #1
	MOVGT R0, #0
	BX LR
@6--------------------------------------------------------------------------

@extern uint16_t shiftLeftU16 (uint16_t x, uint16_t p); // returns x << p = x * 2p for p = 0 .. 31
@                     R0           R0            R1
shiftLeftU16:
	MOV R0,R0, LSL R1
	BX LR
@7-------------------------------------------------------------------------

@extern uint32_t shiftU32(uint32_t x, int32_t p); // return x * 2p for p = -31 .. 31
@extern int8_t shiftS8(int8_t x, int8_t p); // return x * 2p for p = -31 .. 31
@            R0               R0            R1
shiftU32:
shiftS8:
	CMP R1,#0
	MOVPL R0,R0, LSL R1
	NEGMI R1,R1
	MOVMI R0,R0, ASR R1
	BX LR
@8,9-----------------------------------------------------------------------------


@extern bool isEqualU32(uint32_t x, uint32_t y); // returns 1 if x = y, 0 if x != y
@extern bool isEqualS8(int8_t x, int8_t y); // returns 1 if x = y, 0 if x != y
@                R0          R0           R1
isEqualU32:
isEqualS8:
	CMP R1,R0
	MOVEQ R0, #1
	MOVNE R0, #0
	BX LR

@extern bool isEqualS8(int8_t x, int8_t y); // returns 1 if x = y, 0 if x != y


