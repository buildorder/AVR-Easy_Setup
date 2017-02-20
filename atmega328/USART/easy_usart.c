#include "easy_usart.h"

void easy_uart_setup(uint32_t baudrate, uint32_t cpu_frequency)
{
	uint32_t ubbr = caculate_ubbr(baudrate, cpu_frequency);
	set_ubbr(ubbr);
	
	set_send_character_size(DATA_8BIT);
	
	UCSR0B = (RXEN | TXEN);
	
	stdin = stdout = (FILE *)&full_stdio;	
}

uint32_t caculate_ubbr(uint32_t baudrate, uint32_t cpu_frequency)
{
	float ubbr = roundf( (float)cpu_frequency / ( 16 * baudrate) -1 ); 
	
	return (uint32_t)ubbr;
}

void set_ubbr(uint32_t ubbr)
{
	UBRR0H = (ubbr >> 8) & 0xFF;
	UBRR0L = ubbr & 0xFF;
}

void set_send_character_size(uint8_t character_size)
{
	UCSR0C |= character_size << 1;
}

int file_uart_tx(char ch, FILE *stream)
{
	if (ch == '\n')
		file_uart_tx('\r', stream);

	while (!(UCSR0A & UDRE));
	UDR0 = ch;
	
	return 0;
}

int file_uart_rx(FILE *stream)
{
	while (!(UCSR0A & RXC));
	
	return UDR0;
}