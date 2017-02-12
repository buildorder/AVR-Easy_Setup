#include "easy_usart.h"

uint32_t caculate_ubbr(uint32_t baudrate, uint32_t cpu_frequency)
{
	float ubbr = roundf( (float)cpu_frequency / ( 16 * baudrate) -1 ); 
	
	return (uint32_t)ubbr;
}