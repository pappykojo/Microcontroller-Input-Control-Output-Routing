Project README - Microcontroller Input Control and Output Routing using Code Composer Studio

Project Developer:

Name: Oteng Tano Kojo
Index Number: 3038220
Degree: BSc. Computer Engineering


Development Environment:  Code Composer Studio (CCS) v12


Original Question (found on page 218 in the slides)

Write an 8051 C program to get a byte of data form P0. If it is less than 100, send it to P1; otherwise, send it to P2.Solution:
#include <reg51.h>
void main(void)
{
unsigned char mybyte;
P0=0xFF; //make P0 input port
while (1)
{
mybyte=P0; //get a byte from P0
if (mybyte<100)
P1=mybyte; //send it to P1
else
P2=mybyte; //send it to P2}}


 Compiler Configuration

The project workspace directory is set to "D:/Installed Applications/CodeComposerStudios Workspace".
The project uses two main compiler parts:

1. C:/Program Files/Texas Instruments
2. C:/ti

The compiler optimization setting is set to "Global Optimizations" for efficient code execution.

The "include search paths" for the project are as follows:

1. ${CCS_BASE_ROOT}/msp430/include
2. ${PROJECT_ROOT}
3. ${CG_TOOL_ROOT}/include



This code is designed for a microcontroller that is pin-compatible with the 8051 family. This means that the pin configuration and functionality of this microcontroller are similar to the widely-used 8051 microcontroller family. Therefore, code written for the 8051 microcontroller can be easily adapted to work with this specific microcontroller without significant modifications to the hardware connections.
The code provided does not use the traditional `<reg51.h>` header file, which is commonly associated with the 8051 family. Instead, it uses the `<msp430.h>` header file. The reason for this is that the microcontroller being used in this case belongs to the MSP430 family.

The MSP430 is a family of microcontrollers developed by Texas Instruments (TI). It is known for its low-power consumption, making it suitable for battery-operated and energy-efficient applications. The MSP430 family has a different architecture and peripheral set compared to the 8051 family. As a result, the traditional 8051-specific header file `<reg51.h>` is not applicable in this case.

The provided code initializes the microcontroller and sets up its I/O ports to control external devices. The main loop continuously reads the state of Pin P1.0 (corresponding to P0 in the original code) and stores it in the variable `mybyte`. Based on the value of `mybyte`, the code controls the output states of Port 1 (P1) and Port 2 (P2).
The code starts by disabling the Watchdog Timer (`WDTCTL = WDTPW | WDTHOLD;`) to prevent unintentional resets. The Watchdog Timer is a feature in MSP430 microcontrollers that can reset the device if not periodically refreshed. By disabling it, the code ensures that the microcontroller will not reset unexpectedly.

The code configures all the pins of Port 1 (P1) and Port 2 (P2) as output pins (`P1DIR = 0xFF;` and `P2DIR = 0xFF;` respectively). It also sets the initial output of both ports to 0 (`P1OUT = 0x00;` and `P2OUT = 0x00;`).
Pin P1.0 (P0 in the original code) is set as an input (`P1DIR &= ~BIT0;`). This means that P1.0 will be used to read external input signals.


The code enters an infinite loop (`while(1)`) where it continuously reads the value of P1.0 (`mybyte = P1IN;`). If the value of `mybyte` is less than 100, it sets the output of Port 1 (P1) to the value of `mybyte`. Otherwise, if `mybyte` is 100 or greater, it sets the output of Port 2 (P2) to the value of `mybyte`.

