#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer


    P1DIR |= BIT0; // Tells the processor that we want to write
    P1OUT |= BIT0;

    while (1) // INFINITE LOOP
            {
               P1OUT ^= (BIT0);  // Exclusive OR so that every time it loops it alternates between being on and off.
               __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
            }
    return 0;
}
