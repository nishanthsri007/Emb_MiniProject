#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED

void InitADC(void);

/**
 * @brief Reads analog value from the input channel and converts into digital value
 *
 * @param ch Analog channel number
 * @return uint16_t ADC output value
 */
uint16_t Read_ADC(uint8_t ch);


#endif // ADC_H_INCLUDED