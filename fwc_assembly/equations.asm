
.include "/home/student/assembly/m328Pdef.inc"

; COMPLIMENT 

ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output

ldi r16,0b00000000	;w=0

mov A,rcall comp

ldi r20, 0b00000010	;counter = 2

rcall loopw		;calling the loopw routine

out PORTD,r16		;writing output to pins 2,3,4,5

ldi r17, 0b00111100
out DDRD,r17

ldi r17, 0b00000001
out PortD,

Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r16			;left shift
	dec r20			;counter --
	brne	loopw	;if counter != 0
	ret

;comp routine begins
comp:
	mov r0,r16			;using r0 for computations
	ldi r16,0b00000001	;loading 1
	
	eor r16,r0			;A'=A XOR 1
	ret 				;returning from comp
