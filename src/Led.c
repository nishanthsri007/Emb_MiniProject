#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned Seat_Status = 0;
volatile unsigned Switch_Status = 0;

void Led_Actuator(void)
{
    sei();
    DDRB |= (1 << PB0);                      ///<Set B0 bit in DDRB register

    DDRD &= ~(1 << PD0);                     ///<Clear D0 bit in DDRD register
    DDRC &= ~(1 << PC5);                     ///<Clear C5 bit in DDRD register
    PORTD |= (1 << PD0);                     ///<Set D0 bit in PORTD register
    PORTC |= (1 << PC5);                     ///<Set C5 bit in PORTD register

    PCICR |= (1 << PCIE2) | (1 << PCIE1);    ///<Enable Pin Change Interrupt for port C and port D
    PCMSK1 |= (1 << PCINT13);                ///<Set pin change interrupt for PC5
    PCMSK2 |= (1 << PCINT16);                ///<Set pin change interrupt for PD0

}

///ISR for state change in pin C5
ISR(PCINT1_vect)
{
    ///Check if PC5 is high
    if(!(PINC & (1 << PINC5)))
        Seat_Status = 1;                     ///<Set variable
    else
        Seat_Status = 0;                     ///<Clear variable
}

///ISR for state change in pin D0
ISR(PCINT2_vect)
{
    ///Check if PD0 is high
    if(!(PIND & (1 << PIND0)))
        Switch_Status = 1;                   ///<Set variable
    else
        Switch_Status = 0;                   ///<Clear variable
}
