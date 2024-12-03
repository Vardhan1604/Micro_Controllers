#include "LPC21xx.h"


void delay( int num)
{
	while(--num);
}
int main(void) {
		
    IODIR0 |= (1 << 26);  // FIODIR register, bit 26 set to 1 (output)

    // Step 3: Blink the LED
    while (1) {
        // Turn LED ON
        IODIR0 = (1 << 26);  // FIOSET register, bit 26 set to 1 (LED on)
        delay(500000);  // Delay

        // Turn LED OFF
       IODIR0 = (1 << 26);  // FIOCLR register, bit 26 set to 0 (LED off)
        delay(500000);  // Delay
    }
}
