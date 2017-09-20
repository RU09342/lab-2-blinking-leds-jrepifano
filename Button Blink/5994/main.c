#include <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;  //ENABLE GPIO

        P5REN |= BIT5;//Turn on pullup resistor

        P5DIR &= ~BIT5; // Set read for pin
        P1DIR |= BIT0;  // Set write to LED 1
        P1DIR |= BIT1;  // Set write to LED 2
        P1OUT &= ~(BIT0 + BIT1);  // Set the LED off
		P5OUT |= BIT5;

        while(1)
        {
            int value = P5IN & BIT5;    // Ensure the value of the port input is the same as the input
                if(value == 0)         // Check for button press
                {
                    P1OUT ^= (BIT0 + BIT1);  // Turn on LEDs if button is pressed
                    __delay_cycles(100000);  // Delays the clock so that the blinking is actually visible
                }
                else
                {
                    P1OUT &= ~(BIT0 + BIT1); // Turn off if button isnt pressed
                }

        }

}
