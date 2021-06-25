.global getName
.global getZip

.text

@ R0 = &business[0].taxId,     R1 = index -> R0 = &business[index].name
getName:
    MOV R3, #120
    MUL R2, R1, R3 @ multiplication to go deep in the array
    ADD R0, R0, #4
    ADD R0, R0, R2
    BX LR
@ as we are returning a pointer, we dont need to dereference


@ R0 = &business[0].taxId, R1 = index -> R0 = zip
getZip:
    MOV R3, #120
    MUL R2, R1, R3
    ADD R0, R0, #116
	ADD R0, R0, R2
    LDR R0, [R0]
    BX LR
