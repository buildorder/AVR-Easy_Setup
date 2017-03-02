#include "easy_tc.h"

void timer_init(uint8_t clock_frequency)
{
	TCCR0B |= (CLOCK_SET_BIT & clock_frequency);
	
	TIMSK0 |= TIMER0_OVF_INTERRUPT;
}