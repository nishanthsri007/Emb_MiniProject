#ifndef __LED_H__
#define __LED_H__

void Led_Actuator(void);

///Variable to indicate the seat occupancy
volatile unsigned Seat_Status;

///Variable to indicate the switch state
volatile unsigned Switch_Status;


#endif // LED_H_INCLUDED
