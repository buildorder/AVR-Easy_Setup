#include "easy_usart.h"

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
	UCSR0C = character_size << 1;
}