/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "constants.h"     /* Some user defined constants for code readability*/
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void DelayTimer1Init(void)
{ // Set up timer 1 for microsecond delay function
    T1CON = 0x0000; // Timer off, 16-bit, 1:1 prescale, gating off
}
void UsDelay(unsigned int udelay) {
    TMR1 = 0;
    PR1 = udelay * 15; // Number of ticks per microsecond
    IFS0bits.T1IF = 0; // Reset interrupt flag
    T1CONbits.TON = 1;
    while (!IFS0bits.T1IF); // Wait here for timeout
    T1CONbits.TON = 0;
}
int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    while(1)
    {
        //latch and read 'A'
        LATBbits.LATB6 = HIGH; //latch
        UsDelay(12);
        unsigned aButton = PORTBbits.RB10; //read data line
        LATBbits.LATB6 = LOW; //latch
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned bButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned selectButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned startButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned upButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned downButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned leftButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        LATBbits.LATB7 = HIGH; //pulse
        UsDelay(6);
        unsigned rightButton = PORTBbits.RB10; //read data line
        LATBbits.LATB7 = LOW; //pulse
        UsDelay(6);
        
        //write a, b, sel, start to LEDs
        LATBbits.LATB12 = aButton;
        LATBbits.LATB13 = bButton;
        LATBbits.LATB14 = selectButton;
        LATBbits.LATB15 = startButton;
        
        UsDelay(16000); //16 ms is about 60 Hz
    }
}



