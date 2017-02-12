#ifndef EASY_USART_H_
#define EASY_USART_H_

#include <avr/io.h>
#include <stdint.h>
#include <math.h>

//# BAUD RATE #
#define BAUD_RATE_2400    2400
#define BAUD_RATE_4800    4800
#define BAUD_RATE_9600    9600
#define BAUD_RATE_14400   14400
#define BAUD_RATE_19200   19200
#define BAUD_RATE_38400   38400
#define BAUD_RATE_57600   57600
#define BAUD_RATE_115200  115200
//#BAUD RATE #

#define RXEN        0x10
#define TXEN        0x08

enum
{
	DATA_5BIT,
	DATA_6BIT,
	DATA_7BIT,
	DATA_8BIT
};

uint32_t caculate_ubbr(uint32_t baudrate, uint32_t cpu_frequency);

void set_ubbr(uint32_t ubbr);
void set_send_character_size(uint8_t character_size);

#endif /* EASY_USART_H_ */