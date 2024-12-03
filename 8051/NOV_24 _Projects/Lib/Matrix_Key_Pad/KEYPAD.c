
#include "KEYPAD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay/Delay.h"
#include "GPIO.h"

unsigned char KeyPad_Lockup_Table[4][4] = {{'1', '2', '3', 'A'},
                                           {'4', '5', '6', 'B'},
                                           {'7', '8', '9', 'C'},
                                           {'*', '0', '#', 'D'}};
unsigned char Row, Col;

unsigned char KeyPad_SCAN()
{

    //  a =  Keypad_Port;

    KeyPad_Port = 0x0F;
    KeyPad_Port = KeyPad_Port & 0x0F;

    if (KeyPad_Port == 0x0E)
    {
        Delay_1ms(10);
        Row = 0;
    }
    else if (KeyPad_Port == 0x0D)
    {
        Delay_1ms(10);
        Row = 1;
    }
    else if (KeyPad_Port == 0x0B)
    {
        Delay_1ms(10);
        Row = 2;
    }
    else if (KeyPad_Port == 0x07)
    {
        Delay_1ms(10);
        Row = 3;
    }
    else
    {
        return 0x00;
    }

    KeyPad_Port = 0xF0;
    KeyPad_Port = KeyPad_Port & 0xF0;

    if (KeyPad_Port == 0xE0)
    {
        Delay_1ms(10);
        Col = 0;
    }
    else if (KeyPad_Port == 0xD0)
    {
        Delay_1ms(10);
        Col = 1;
    }
    else if (KeyPad_Port == 0xB0)
    {
        Delay_1ms(10);
        Col = 2;
    }
    else if (KeyPad_Port == 0x70)
    {
        Delay_1ms(10);
        Col = 3;
    }
    else
    {
        return 0x00;
    }

    return KeyPad_Lockup_Table[Row][Col];
}