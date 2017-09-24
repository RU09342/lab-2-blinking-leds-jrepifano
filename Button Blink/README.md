# Button Blink
Below is the code used for the G2253:

include <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
		

        P1REN |= BIT3;//Turn on pullup resistor

        P1DIR &= ~BIT3; // Set read
        P1DIR |= BIT0;  // Set write to LED 1
        P1DIR |= BIT6;  // Set write to LED 2
        P1OUT &= ~(BIT0 + BIT6);  // Set the LED off

        while(1)
        {
            int value = P1IN & BIT3;    // Ensure the value of the port input is the same as the input
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

Same deal as before for blinking the LEDs.
This time I had to use Or = PXREN (Pin X resistor enable) to tell the microprocessor I want a pull-up resistor.
On some of the borads like the 2311, you also need to do PXOUT |= *buttonpin* to tell it that you want a pull-up.
In my while loop I set an integer 'value' = P1IN & BIT3.
This will take that base 10 number and make it into a binary number, so that I can use this vairable as an argument in my if statement.
The if statement checks if the button is pressed down, then it will bink the LED.
If the button isn't pressed down the LEDs won't light up.
