#ifndef EASY_USART_H_
#define EASY_USART_H_

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

uint32_t caculate_ubbr(uint32_t baudrate, uint32_t cpu_frequency);

#endif /* EASY_USART_H_ */