#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

void ports_init(void);

///Variable to indicate the seat occupancy
volatile unsigned Seat_Status;

///Variable to indicate the switch state
volatile unsigned Switch_Status;


#endif // LED_H_INCLUDED
