#include <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

        P1REN |= BIT1;//Turn on pullup resistor

        P1DIR &= ~BIT1; // Set read
        P1DIR |= BIT0;  // Set write to LED 1
        P4DIR |= BIT7;  // Set write to LED 2
        P1OUT &= ~BIT0;  // Set the LED off
        P4OUT &= ~BIT7;

        while(1)
        {
            int value = P1IN & BIT1;    // Ensure the value of the port input is the same as the input
                if(value == 0)         // Check for button press
                {
                    P1OUT ^= BIT0;  // Turn on LEDs if button is pressed
                    P4OUT ^= BIT7;
                    __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
                }
                else
                {
                    P1OUT &= ~BIT0; // Turn off if button isnt pressed
                    P4OUT &= ~BIT7;
                }

        }

}
