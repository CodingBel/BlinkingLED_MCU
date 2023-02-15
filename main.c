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

void main (void)
{
	TRISCbits.TRISC0 = 0;			// Make PORTC0 an output port 
	LATCbits.LATC0 	 = 0; 			// Initialize PORTC0 to zero 
	
	while (1)						// An infinite loop 
	{
		LATCbits.LATC0 	 = 1;		// Turn on LED for a while 
 		Delay10KTCYx(100);			// A Delay of 1 seconds @ 4MHz
 		
 		/* assuming that we are using a clock frequency of 4MHz, 
 		   1TCY = 1 / (4MHz /4), in this case 1TCY = 1us (one microseconds)
 		*/
 		
		LATCbits.LATC0 	 = 0;		// Turn off LED for a while
		Delay10KTCYx(100);			// A Delay of 1 seconds @ 4MHz
	}
}

