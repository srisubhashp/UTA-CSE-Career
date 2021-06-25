.global getName
.global getZip

.text

getName:
	ADD R0, R0, #4
	BX LR

getZip:  // why is that for Zip we have to explictly load the address..?

	ADD R0, R0, #116
	LDR R0, [R0]
	BX LR
