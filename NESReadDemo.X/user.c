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

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "user.h"            /* variables/params used by user.c */
#include "constants.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
    //set LED pins as output
    TRISBbits.TRISB15 = OUTPUT;
    TRISBbits.TRISB14 = OUTPUT;
    TRISBbits.TRISB13 = OUTPUT;
    TRISBbits.TRISB12 = OUTPUT;
    
    //set NES latch to output
    TRISBbits.TRISB6 = OUTPUT;
    //set NES pulse to output
    TRISBbits.TRISB7 = OUTPUT;
    
    //set NES data line as input
    TRISBbits.TRISB10 = INPUT;
    
    /* Initialize peripherals */
    //initialize LEDS as off
    LATBbits.LATB15 = LOW;
    LATBbits.LATB14 = LOW;
    LATBbits.LATB13 = LOW;
    LATBbits.LATB12 = LOW;
    
    //initialize latch and pulse as off
    LATBbits.LATB6 = LOW;
    LATBbits.LATB7 = LOW;
}

