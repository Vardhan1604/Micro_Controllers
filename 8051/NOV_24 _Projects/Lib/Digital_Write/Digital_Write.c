#include "Digital_Write.h"
#include "GPIO.h"

void Digital_Write(unsigned char Pin, unsigned char State)
{
    if (Pin < 8)
    {
        if (State == HIGH)
        {
            P0 |= (1 << Pin);
        }
        else if (State == LOW)
        {
            P0 &= ~(1 << Pin);
        }
    }
    if (Pin > 9 && Pin < 18)
    {
			Pin -= 10;
        if (State == HIGH)
        {
            P1 |= (1 << Pin);
        }
        else if (State == LOW)
        {
            P1 &= ~(1 << Pin);
        }
        if (Pin > 19 && Pin < 28)
        {
					Pin -= 20;
            if (State == HIGH)
            {
                P2 |= (1 << Pin);
            }
            else if (State == LOW)
            {
                P2 &= ~(1 << Pin);
            }
        }
        if (Pin > 29 && Pin < 38)
        {
					Pin -= 30;
            if (State == HIGH)
            {
                P3 |= (1 << Pin);
            }
            else if (State == LOW)
            {
                P3 &= ~(1 << Pin);
            }
        }
    }
		
	}