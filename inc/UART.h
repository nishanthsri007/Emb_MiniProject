#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

void USARTInit(void);

/**
 * @brief Function to read character from the serial input buffer
 *
 * @return char 8 bit character read from the serial communication
 */
char USARTReadChar(void);

/**
 * @brief Function to write character to the serial output buffer
 *
 * @param data 8 bit data to be written to the serial output buffer
 */
void USARTWriteChar(char data);

#endif // UART_H_INCLUDED
