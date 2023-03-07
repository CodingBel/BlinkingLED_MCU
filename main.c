/*
* In Most PIC MCUs, an Instruction cycle takes 4 clock cycles 
* 1 Clock cycle is denoted as 1 TCY 
* So 1 TCY in a typical PIC MCU is the inverse of 
* The clock frequency / 4 
*/

#include <p18f4520.h>
#include <delays.h>

#pragma config LVP = OFF			// Disable Low Volatage Programming 
#pragma config WDT = OFF			// Disable Watch Dog Timer 
#pragma config OSC = HS				// Use an External Crystal Oscillator 

void Blinking (unsigned char);
void DebounceDelay (void); 

void Blinking (unsigned char Speed)
{
	LATCbits.LATC0 	 = 1;		// Turn on LED for a while 
	Delay100TCYx(Speed * 10);
	
	LATCbits.LATC0 	 = 0;		// Turn on LED for a while 
	Delay100TCYx(Speed * 10);
} 

void DebounceDelay (void)
{
	Delay10KTCYx (30); 
} 

void main (void)
{
	unsigned char Count = 1; 
	
	TRISCbits.TRISC0 = 0;			// Make PORTC0 an output port 
	LATCbits.LATC0 	 = 0; 			// Initialize PORTC0 to zero 
	
	TRISDbits.TRISD0 = 1; 			// Make PortD0 an input port 
	
	while (1)						// An infinite loop 
	{
		if (PORTDbits.RD0 == 1)
		{
			DebounceDelay (); 
			
			Count += 1; 
			
			if (Count > 5)
				Count = 1; 
		}
		
		switch (Count)
		{
			case 1: 
				Blinking (1); 
			break;
			
			case 2: 
				Blinking (2); 
			break;
			
			case 3: 
				Blinking (3); 
			break;
			
			case 4: 
				Blinking (4); 
			break;
			
			case 5: 
				Blinking (5); 
			break; 
			
			default: 
				Blinking (1); 
			break; 
		}
	}
}

