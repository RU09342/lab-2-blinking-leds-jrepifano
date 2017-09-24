# Multiple Blink
Below is the code for multiple blink for the G2553.

include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= (BIT0 + BIT6); // Tells the processor that we want to write
        while (1) // INFINITE LOOP
        {
           P1OUT ^= (BIT0 + BIT6);  // Exclusive OR so that every time it loops it alternates between being on and off.
           __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
        }
}


The only difference between this and simple blink is adding the other LED bit. We can do this because BIT0 and BIT6 are actual base 10 numbers.

Again the only difference between this code and the code for all other boards is the pin assignments.
