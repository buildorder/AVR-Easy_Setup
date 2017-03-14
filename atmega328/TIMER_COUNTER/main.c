/*
 * main.c
 *
 * Created: 2017-02-12 ¿ÀÈÄ 9:04:32
 *  Author: kms014
 */ 
#define F_CPU   16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "easy_usart.h"
#include "easy_tc.h"
 
 int cnt, now_time, tcnt_value;
 
int main(void)
{
	easy_uart_setup(BAUD_RATE_9600, F_CPU);
	tcnt_value = easy_timer_intterupt_setup(F_CPU, CLOCK_64, 1000);
	set_overflow_intterupt_enable();
	
	while(1);
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = tcnt_value;
	cnt++;
	
	if( cnt == 999 )
	{
		now_time++;
		cnt = 0;
		printf("TIME : %d\n", now_time);
	}
}
