#Extra Work 2 - Alternating LED colors.


nclude <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;  //ENABLE GPIO

        P1REN |= BIT1;//Turn on pullup resistor

        P1DIR &= ~BIT1; // Set read
        P1DIR |= BIT0;  // Set write to LED 1
        P2DIR |= BIT0;  // Set write to LED 2
        P1OUT &= ~BIT0; // Set the LED off
        P1OUT |= BIT1;
        P2OUT &= ~BIT0;

        int count = 0;



        while(1)
        {




            int value = P1IN & BIT1;    // Ensure the value of the port input is the same as the input
                if(value == 0)         // Check for button press
                {
                    if(count == 1) count = 0;
                    else count = count +1;

                }
                 if(count == 0)
                    {
                        P1OUT ^= BIT0; // Turn off if button isnt pressed

                        __delay_cycles(100000);
                    }
                 else if(count == 1)
                                    {

                                        P2OUT ^= BIT0;
                                        __delay_cycles(100000);
                                    }






        }

}

Works basically the same way as Extra work 1. 
This time when count increments, it changes which LED is on using XOR.
