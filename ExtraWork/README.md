#Extra Work - Variable blinking speeds

Code included below:


include <msp430.h> 

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;  //ENABLE GPIO

        P1REN |= BIT1;//Enable Resistor

        P1DIR &= ~BIT1; // Set read
        P1DIR |= BIT0;  // Set write to LED 1
        P2DIR |= BIT0;  // Set write to LED 2
        P1OUT &= ~BIT0; // Set the LED off
        P1OUT |= BIT1;  // Set pull-up resistor
        P2OUT &= ~BIT0; // Set LED 2 off.

        int count = 0; //Keep track of button presses.



        while(1)
        {




            int value = P1IN & BIT1;    // Ensure the value of the port input is the same as the input
                if(value == 0)         // Check for button press
                {
                    if(count == 2) count = 0; //loops number.
                    else count = count +1;

                }
                 if(count == 0)
                    {
                        P1OUT ^= BIT0; // Turn off if button isnt pressed
                        P2OUT ^= BIT0;
                        __delay_cycles(100000);
                    }
                 else if(count == 1)
                                    {
                                        P1OUT ^= BIT0; // Turn off if button isnt pressed
                                        P2OUT ^= BIT0;
                                        __delay_cycles(1000000);
                                    }
                 else if(count == 2)
                                    {
                                        P1OUT ^= BIT0; // Turn off if button isnt pressed
                                        P2OUT ^= BIT0;
                                        __delay_cycles(10000000);
                                    }







        }

}


Bascially I use the count variable to keep track of how many times the button was pressed.
Everytime it's pressed count is increased by 1. 
When count changes the __delay_cycles also changes.
Had some issues with button bouncing, as well as the slowest setting.
Since I'm using polling instead of interrupts here I have to wait for the blink to loop before the button press will go through. 
Obviously using interrupts would work much better for something like this.
