#include <msp430.h>

void main(void)
{
    unsigned char mybyte;

    WDTCTL = WDTPW | WDTHOLD; // Stop Watchdog Timer
    P1DIR = 0xFF; // Set all pins of Port 1 (P1) as outputs
    P2DIR = 0xFF; // Set all pins of Port 2 (P2) as outputs
    P1OUT = 0x00; // Set all pins of P1 to 0 initially
    P2OUT = 0x00; // Set all pins of P2 to 0 initially

    P1DIR &= ~BIT0; // Set P1.0 as an input (P0 in the original code)

    while (1)
    {
        mybyte = P1IN; // Read a byte from P1.0 (P0 in the original code)

        if (mybyte < 100)
            P1OUT = mybyte; // Send it to P1 (P1 in the original code)
        else
            P2OUT = mybyte; // Send it to P2 (P2 in the original code)
    }
}
