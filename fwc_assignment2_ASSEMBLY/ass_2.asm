
.include "/home/bhavani/Documents/arduino/assignment_2/m328Pdef.inc"

ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output



ldi r16,0b00000001	;initializing X
ldi r17,0b00000000	;initializing Y
ldi r18,0b00000001  ;initializing Z
;logical AND
and r16,r17		;X AND Y
;logical OR
and r17,r18     ;Y AND Z

or r16,r17      ;
;logical XOR
;eor r16,r17			;X XOR X

;following code is for displaying output
;shifting LSB in r16 to 2nd position
ldi r20, 0b00000010	;counter = 2

rcall loopw		;calling the loopw routine

out PORTD,r16		;writing output to pins 2,3,4,5


Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r16			;left shift
	dec r20			;counter --
	brne	loopw	;if counter != 0
	ret
	
