#ifndef __PWM_H__
#define __PWM_H__

/**
 * @brief Function to generate PWM output
 *
 * @param ADC_value Output digital value from ADC
 * @return uint8_t Returns the temperature value in decimal corresponding to the PWM output
 */
uint8_t PWM(uint16_t adc_value);


#endif 
