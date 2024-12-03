
#include "Uart.h"


void main() {
    Uart_Init(110);      // Initialize the UART with a baud rate of 110
    while(1) {
        Uart_Tx(0x55);  // Transmit the byte 0x55 continuously
    }
}