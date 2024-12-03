#include "Seven_Segment.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "GPIO.h"

unsigned char Seven[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};

void Seven_Segment()
{
    unsigned int number;
    unsigned thousands,hundreds,tens,units,l;
    for (number = 0; number <= 100; number++) 
	{
			   thousands = (number / 1000)%10;
         hundreds = (number / 100) % 10; 
         tens = (number / 10) % 10;      
         units = number % 10; 
			
        for (l = 0;l  <= 100; l++)
				{
						 
					Seg1 = 1; Seg2 = 0; Seg3 = 0; Seg4 = 0; 
					P1 = Seven[thousands]; 
					Delay_1ms(1); 

					Seg1 = 0; Seg2 = 1; Seg3 = 0; Seg4 = 0;
					P1 = Seven[hundreds];
					Delay_1ms(1);

					Seg1 = 0; Seg2 = 0; Seg3 = 1; Seg4 = 0; 
					P1 = Seven[tens]; 
					Delay_1ms(1); 

					Seg1 = 0; Seg2 = 0; Seg3 = 0; Seg4 = 1; 
					P1 = Seven[units]; 
					Delay_1ms(1);
				}
    }
}