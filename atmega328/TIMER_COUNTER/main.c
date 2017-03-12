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
 
int main(void)
{
	int i;
	DDRD = 0xFF;
	
	//easy_uart_setup(BAUD_RATE_57600, F_CPU);
	easy_pwm_setup(OC0B, 0);
	
	while(1)
	{
		for (i=0;i<256;i++)
		{
			easy_pwm_setup(OC0B, i);
			_delay_ms(20);
		}
	};
}
