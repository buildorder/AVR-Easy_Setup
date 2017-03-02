/*
 * easy_tc.h
 *
 * Created: 2017-02-20 오후 5:02:41
 *  Author: kms014
 */ 


#ifndef EASY_TC_H_
#define EASY_TC_H_

#include <avr/io.h>

#define TIMER0_OVF_INTERRUPT 0x01

#define CLOCK_SET_BIT 0x07

enum waveform_generation_mode
{
	NORMAL,
	PHASE_CORRECT,
	CTC,
	FAST_PWM
};

enum clock_select
{
	NO_CLOCK,
	CLOCK_1,
	CLOCK_8,
	CLOCK_64,
	CLOCK_256,
	CLOCK_1024,
	FALLING_EXTERNAL_CLOCK,
	RISING_EXTERNAL_CLOCK	
};


void timer_init(uint8_t clock_frequency);

#endif /* EASY_TC_H_ */