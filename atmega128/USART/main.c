/*
 * main.c
 *
 * Created: 2017-02-12 ¿ÀÈÄ 9:04:32
 *  Author: kms014
 */ 
#define F_CPU   16000000.0

#include <util/delay.h>
#include "easy_usart.h"


void loop(void)
{
	char buffer[100];
	
	printf("INPUT : ");
	scanf("%s", buffer);
	printf("%s\n", buffer);

}

int main(void)
{
	easy_uart_setup(BAUD_RATE_14400, F_CPU);

	while (1)
	{
		loop();
	}
}