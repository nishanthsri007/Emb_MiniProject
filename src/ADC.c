#include <avr/io.h>

void InitADC(void)
{
    ADMUX |= (1 << REFS0);                                  ///<5V internal reference voltage
    ADCSRA = (1 << ADEN);                                   ///<SET ADC Enable bit
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);   ///<Set Prescalar to 128
    ADMUX &= 0xf8;                                          ///<Clear last 3 bits for channel selection
}

uint16_t Read_ADC(uint8_t ch)
{
    ch &= 0b00000111;                                      ///<Taking the last 3 bits from received parameter
    ADMUX |= ch;                                           ///<Selecting the input channel
    ADCSRA |= (1 << ADSC);                                 ///<Starting ADC conversion
    while(!(ADCSRA & (1 << ADIF)));                        ///<Waiting for the end of conversion
    ADCSRA |= (1 << ADIF);
    return ADC;
}
