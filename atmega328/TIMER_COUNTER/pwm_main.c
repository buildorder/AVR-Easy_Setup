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
	easy_uart_setup(BAUD_RATE_9600, F_CPU);
	
	//SET PWM
	easy_pwm_setup(OC0A, 100);
	
	while(1);
}