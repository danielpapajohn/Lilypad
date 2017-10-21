/**********************************************************************************
* © 2007 Microchip Technology Inc.
*
* FileName:        Eg1_BlinkLED.c
* Dependencies:    p24fj64ga002.h
* Processor:       PIC24FJ64GA002
* Compiler:        MPLAB® C30 v3
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip,s 
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP,S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
*******************************************************************************************
*
*
* ADDITIONAL NOTES:  In this example program characters pressed on the keyboard are sent to
* the device via usb. The device replicates the character back to the PC enclosed in quotes. 
* Also this program blinks all four LEDs at 250ms by using timer 1. 
*
*******************************************************************************************/ 

#include "p24fj64ga002.h"
// the above include path may be different for each user.  If a compile
// time error appears then check the path for the file above and edit
// the include statement above.

#define XTFREQ          7372800         		//On-board Crystal frequency
#define PLLMODE         2               		//On-chip PLL setting
#define FCY             XTFREQ*PLLMODE        //Instruction Cycle Frequency

#define BAUDRATE         9600       
#define BRGVAL          ((FCY/BAUDRATE)/16)-1 

#define HIGH 0
#define LOW  1

#define INPUT 1
#define OUTPUT 0

//turn off JTAG to get the RB10 and RB11 pins working as general IO
_CONFIG1
(
    JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1
    & FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS8192
);

int main(void)
{
    
    
	CLKDIVbits.RCDIV = 0;

	//RPINR18bits.U1RXR = 9;	// Make Pin RP9 U1RX
	//RPOR4bits.RP8R = 3;		// Make Pin RP8 U1TX


	PADCFG1 = 0xFF;			// Make analog pins digital 

	LATB = 0x0000;
	//TRISB = 0x0FFF;			// Configure LED pins as output
    TRISBbits.TRISB15 = OUTPUT;
    TRISBbits.TRISB14 = OUTPUT;
    TRISBbits.TRISB13 = OUTPUT;
    TRISBbits.TRISB12 = OUTPUT;
    
    TRISBbits.TRISB6 = INPUT;
    TRISBbits.TRISB7 = INPUT;
    TRISBbits.TRISB10 = INPUT;
    TRISBbits.TRISB11 = INPUT;

    LATBbits.LATB15 = LOW;
    LATBbits.LATB14 = LOW;
    LATBbits.LATB13 = LOW;
    LATBbits.LATB12 = LOW;
    
	/*TMR1 = 0;				// Clear timer 1
	PR1 = 0xFF09;			// Interrupt every 250ms
	IFS0bits.T1IF = 0;		// Clear interrupt flag
	IEC0bits.T1IE = 1;		// Set interrupt enable bit
	T1CON = 0x8030;			// Fosc/4, 1:256 prescale, start TMR1


	TRISB = 0x0300;
	U1BRG  = BRGVAL;
	U1MODE = 0x8000; 		// Reset UART to 8-n-1, alt pins, and enable 
	U1STA  = 0x0440; 		// Reset status register and enable TX & RX


	_U1RXIF=0;					// Clear UART RX Interrupt Flag*/
	

    
	while(1)
	{
		/*int a;
		while (_U1RXIF==0);			// Wait and Receive One Character
		a = U1RXREG;
		while(!U1STAbits.TRMT);
		U1TXREG = '"';
		while(!U1STAbits.TRMT);		// Echo Back Received Character with quotes
		U1TXREG = a;
		while(!U1STAbits.TRMT);
		U1TXREG = '"';
		while(!U1STAbits.TRMT);
		U1TXREG = ' '; 	
		_U1RXIF=0;					// Clear UART RX Interrupt Flag
        */
        
        
        unsigned genesisUp = PORTBbits.RB6;
        unsigned genesisDown = PORTBbits.RB7;
        unsigned genesisLeft = PORTBbits.RB10;
        unsigned genesisRight = PORTBbits.RB11;
        
        LATBbits.LATB12 = genesisUp;
        LATBbits.LATB13 = genesisDown;
        LATBbits.LATB14 = genesisLeft;
        LATBbits.LATB15 = genesisRight;
    }
return 0;
}


/*void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0;		// clear interrupt flag
	
	//LATB ^= 0x8000;			//Toggle LED's
}*/


