#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= (BIT0 + BIT6); // Tells the processor that we want to write to pins P1.0 and P1.6
        while (1) // INFINITE LOOP
        {
           P1OUT ^= (BIT0 + BIT6);  // Exclusive OR so that every time it loops it alternates between being on and off.
           __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
        }
}
