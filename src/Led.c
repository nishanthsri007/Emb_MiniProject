#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned Seat_Status = 0;
volatile unsigned Switch_Status = 0;

void ports_init(void)
{
    sei();
    DDRB |= (1 << PB0); ///<Set B0 bit in DDRB register(to make it as output)

    DDRD &= ~(1 << PD0); ///<Clear D0 bit in DDRD register(to make it as input)
    DDRC &= ~(1 << PC6); ///<Clear C6 bit in DDRD register(to make it as input)
    PORTD |= (1 << PD0); ///<Set D0 bit in PORTD register(initial value 1)
    PORTC |= (1 << PC6); ///<Set C6 bit in PORTD register(initial value 1)

    PCICR |= (1 << PCIE2) | (1 << PCIE1);  ///<Enable Pin Change Interrupt for port C and port D
    PCMSK2 |= (1 << PCINT16);   ///<Set pin change interrupt for PC6
    PCMSK1 |= (1 << PCINT14);   ///<Set pin change interrupt for PD0

}

///ISR for state change in pin C6
ISR(PCINT1_vect)
{
    ///Check if PC6 is high
    if(!(PINC & (1 << PINC6)))
        Seat_Status = 1;  ///<Set variable
    else
        Seat_Status = 0;  ///<Clear variable
}

///ISR for state change in pin D0
ISR(PCINT2_vect)
{
    ///Check if PD0 is high
    if(!(PIND & (1 << PIND0)))
        Switch_Status = 1;  ///<Set variable
    else
        Switch_Status = 0;   ///<Clear variable
}
