
#include "Digital_Read.h"
#include "GPIO.h"

unsigned char Digital_Read(unsigned char Pin)
{
	if(Pin < 8)
	{
		if((P0 &(1<<Pin)) ==0 )
		{
			return 1;
    }
	}
	if(Pin > 9 && Pin < 18)
	{
		Pin -= 10;
		if((P1 &(1<<Pin)) ==0 )
		{
			return 1;
    }
	}
		if(Pin > 19 && Pin < 28)
	{
		Pin -= 20;
		if((P2 &(1<<Pin)) ==0 )
		{
			return 1;
    }
	}
		if(Pin > 29 && Pin < 38)
	{
		Pin -= 30;
		if((P3 & (1<<Pin)) ==0 )
		{
			return 1;
    }
  }
	return 0;
}