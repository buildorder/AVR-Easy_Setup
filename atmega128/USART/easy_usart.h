/*
 *		ORDER
 *		
 *		1. DEFINE
 *		2. STRUCT
 *		3. ENUM
 *		4. FUNCTION
 *		5. VARIABLE
 */

#ifndef EASY_USART_H_
#define EASY_USART_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define UART_REG    0xC0

//# BAUD RATE #
#define BAUD_RATE_2400    2400
#define BAUD_RATE_4800    4800
#define BAUD_RATE_9600    9600
#define BAUD_RATE_14400   14400
#define BAUD_RATE_19200   19200
#define BAUD_RATE_38400   38400
#define BAUD_RATE_57600   57600
#define BAUD_RATE_115200  115200
//# BAUD RATE #

#define RXC     0x80
#define TXC     0x40
#define UDRE    0x20

#define RXEN        0x10
#define TXEN        0x08

enum
{
	DATA_5BIT,
	DATA_6BIT,
	DATA_7BIT,
	DATA_8BIT
};
void easy_uart_setup(uint32_t baudrate, uint32_t cpu_frequency);

uint32_t caculate_ubbr(uint32_t baudrate, uint32_t cpu_frequency);
void set_ubbr(uint32_t ubbr);

void set_send_character_size(uint8_t character_size);

int file_uart_tx(char ch, FILE *stream);
int file_uart_rx(FILE *stream);

static const FILE full_stdio = FDEV_SETUP_STREAM(file_uart_tx, file_uart_rx, _FDEV_SETUP_RW);

#endif /* EASY_USART_H_ */