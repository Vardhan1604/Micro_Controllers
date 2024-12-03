#include <reg51.h>      // Include 8051 Register File
#include <stdio.h>      // Include standard I/O for string conversion

// LCD pins connected to 8051
sbit RS = P0^0;   // Register Select pin
sbit RW = P0^1;   // Read/Write pin
sbit EN = P0^2;   // Enable pin

// ADC pins connected to 8051 (e.g., P1 for ADC data, P3 for control)
///sbit ADC_CS = P3^4;  // Chip Select for ADC
sbit ADC_WR = P3^3;  // Write Pin for ADC
sbit ADC_RD = P3^2;  // Read Pin for ADC

void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 1275; j++);
    }
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(5);
    EN = 0;
}

void lcd_data(unsigned char data1) {
    P2 = data1;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(5);
    EN = 0;
}

void lcd_init() {
    lcd_cmd(0x02); // Initialize LCD in 4-bit mode
    lcd_cmd(0x28); // Set 2-line, 5x7 font
    lcd_cmd(0x0C); // Display ON, Cursor OFF
    lcd_cmd(0x06); // Auto increment cursor
    lcd_cmd(0x01); // Clear display
    delay(5);
}

unsigned char read_adc() {
    unsigned char adc_value = 0;
    
    //ADC_CS = 0;      // Enable ADC
    ADC_WR = 0;      // Start conversion
    delay(1);
    ADC_WR = 1;
    
    ADC_RD = 0;      // Read ADC result
    delay(1);
    adc_value = P1;  // Read ADC data from port P1
    ADC_RD = 1;      // End reading
    
   // ADC_CS = 1;      // Disable ADC
    
    return adc_value;
}

void main() {
    unsigned char adc_value;
    float temperature;
	 int i;
    char display[10];
    
    lcd_init();      // Initialize the LCD
    
    while(1) {
        adc_value = read_adc();  // Read ADC value from LM35
        temperature = (adc_value * 5.0 / 255.0) * 100.0;  // Convert to temperature
        
        // Display temperature value on LCD
        sprintf(display, "Temp: %.2f C", temperature);
        
        lcd_cmd(0x80);  // Move cursor to the beginning of the first line
        for(i = 0; display[i] != '\0'; i++) {
            lcd_data(display[i]);
        }
        
        delay(1000);  // Delay 1 second before updating
    }
}
