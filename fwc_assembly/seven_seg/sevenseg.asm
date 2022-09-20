;using assembly language for 
;displaying number on
;seven segment display

.include "/home/student/assembly/m328Pdef.inc"

  
;Configuring pins 2-7 (PD2-PD7) of Arduino
;as output
  ldi r16,0b11111100
  out DDRD,r16
;Configuring pin 8 (PB0) of Arduino
;as output 
  ldi r16,0b00000001
  out DDRB,r16
;Writing the number 2 on the 
;seven segment display
  ldi r17,0b00000000
  out PortD,r17
  
  ldi r17,0b00000001
  out PortB,r17
  
  call wait
  
  ldi r17,0b11100100
  out PortD,r17
  
  ldi r17,0b00000001
  out PortB,r17
  
  call wait
  
  ldi r17,0b10010000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b11000000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b01100100
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b01001000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b00001000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b11100000
  out PortD,r17
  
  ldi r17,0b00000001
  out PortB,r17
  
  call wait
  
  ldi r17,0b00000000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
  ldi r17,0b01100000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
  
  call wait
  
wait:
;push r16
;push r17
;push r18
ldi r16,0x20
ldi r17,0x00
ldi r18,0x00
w0:
	dec r18
	brne w0
	dec r17
	brne w0
	dec r16
	brne w0
;pop r18
;pop r17
;pop r16
ret
  
Start:
  rjmp Start
