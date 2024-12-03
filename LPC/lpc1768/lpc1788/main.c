#include "LPC177x_8x.h"   // Include the appropriate header for your LPC microcontroller

#define LED_PIN 0       // P0_0 pin

void delay(int count)
{
    volatile int i;
    for(i = 0; i < count; i++) {
        // simple delay loop
    }
}

int main(void)
{
    // Step 1: Configure GPIO pin as output
    LPC_GPIO0->DIR |= (1 << LED_PIN);  // Set P0_0 as output (1 = output, 0 = input)

    while(1)
    {
        // Step 2: Toggle the LED (turn it on and off)
        LPC_GPIO0->SET = (1 << LED_PIN);  // Set P0_0 high (turn LED on)
        delay(1000000);                   // Wait for a while

        LPC_GPIO0->CLR = (1 << LED_PIN);  // Clear P0_0 (turn LED off)
        delay(1000000);                   // Wait for a while
    }

    //return;
}
