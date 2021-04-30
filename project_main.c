/*
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "Led.h"
#include "PWM.h"
#include "UART.h"

int main()
{
	uint16_t temp = 0;
	int LED = 0;

    ///Call initializing functions
	InitADC();
        Led_Actuator();

    while(1)
    {
        ///Check for switch status and turn on/off the LED
	    if(Seat_Status == 1 && Switch_Status == 1)
        {
            PORTB |= (1 << PB0);
            LED = 1;
        }
        else
        {
            PORTB &= ~(1 << PB0);
        }

        if(LED == 1)
        {
            temp = PWM(Read_ADC(0));          ///<Read ADC input and generate appropriate PWM output
            USARTWriteChar(temp);            ///<Write temperature value to serial monitor
            _delay_ms(200);
        }
        else
        {
            PWM(2000);               ///<Function call for no PWM output
        }
    }
    return 0;
}


