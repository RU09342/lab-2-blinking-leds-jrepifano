#include <msp430g2231.h>

void main(void) // Not returning anything so this will remain as a void.
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= (BIT0); // Tells the processor that we want to write to pins P1.0
    while (1) // INFINITE LOOP
    {
       P1OUT ^= (BIT0);  // Exclusive OR so that every time it loops it alternates between being on and off.
       __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
    }
}