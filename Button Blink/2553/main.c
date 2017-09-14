#include <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

        P1REN |= BIT3;//Turn on pullup resistor

        P1DIR &= ~BIT3; // Set read for pin 1.3
        P1DIR |= BIT0;  // Set write to LED 1
        P1DIR |= BIT6;  // Set write to LED 2
        P1OUT &= ~(BIT0 + BIT6);  // Set the LED off

        while(1)
        {
            int value = P1IN & BIT3;    // Ensure the value of the port 1 input is the same as the input BIT3
                if(value == 0)         // Check for button press
                {
                    P1OUT ^= (BIT0 + BIT6);  // Turn on LEDs if button is pressed
                    __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
                }
                else
                {
                    P1OUT &= ~(BIT0 + BIT6); // Turn off if button isnt pressed
                }

        }

}
