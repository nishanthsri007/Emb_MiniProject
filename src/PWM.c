#include <avr/io.h>
#include <util/delay.h>

uint8_t PWM(uint16_t adc_value)
{
    DDRB |= (1 << PB1);  ///<Set PB1 bit in DDRB

    
    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << CS11) | (1 << CS10);
    uint8_t temp = 0;

    if(adc_value >= 0 && adc_value <= 200)
    {
        OCR1A = 200;   ///<20% dutycycle
        temp = 20;
        _delay_ms(200);
    }
    else if(adc_value >= 210 && adc_value <= 500)
    {
        OCR1A = 400;   ///<40% dutycycle
        temp = 25;
        _delay_ms(200);
    }
    else if(adc_value >= 510 && adc_value <= 700)
    {
        OCR1A = 700;   ///<70% dutycycle
        temp = 29;
        _delay_ms(200);
    }
    else if(adc_value >= 710 && adc_value <= 1024)
    {
        OCR1A = 900;   ///<95% dutycycle
        temp = 33;
        _delay_ms(200);
    }
    else
        OCR1A = 0;   ///<0% dutycycle

    return temp;
}
