#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                    // to activate previously configured port settings

    P1DIR |= BIT0; // Tells the processor that we want to write
    P9DIR |= BIT7;
    P1OUT |= BIT0;
    P9OUT &= BIT7;

    while (1) // INFINITE LOOP
            {
               P1OUT ^= BIT0;  // Exclusive OR so that every time it loops it alternates between being on and off.
               P9OUT ^= BIT7;
               __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
            }
    return 0;
}
