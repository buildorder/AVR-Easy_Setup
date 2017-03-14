/*
 *		ORDER
 *		
 *		1. DEFINE
 *		2. STRUCT
 *		3. ENUM
 *		4. FUNCTION
 *		5. VARIABLE
 */

#ifndef EASY_TC_H_
#define EASY_TC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "easy_usart.h"

/* TCCR0A => COM0A[1:0] == bit[7:6] */
#define OC0A 0xC0 // PD6
#define COM0A_MASK   0xC0
#define COM0A_SHIFT  6

	/* COMA_NON_PWM */
	#define DISSCONNECT 0
	#define TOGGLE 1
	#define CLEAR 2
	#define SET 3
	/* COMA_NON_PWM */
	
	/* COMA_FAST_PWM */
	#define DISSCONNECT 0
	//TCCR0B => WGM02 == bit[3] ... If WGM02 is '0' OC0A Dissconnected, or '1' Toggle
	#define DISSCONNECT_OR_TOGGLE 1
	#define NON_INVERTING 2
	#define INVERTING 3
	/* COMA_FAST_PWM */
	
	/* COMA_PHASE_CORRECT_PWM */
	#define DISSCONNECT 0
	//TCCR0B => WGM02 == bit[3] ... If WGM02 is '0' OC0A Dissconnected, or '1' Toggle
	#define DISSCONNECT_OR_TOGGLE 1
	#define NON_INVERTING 2
	#define INVERTING 3
	/* COMA_PHASE_CORRECT_PWM */
	
/* TCCR0A => COM0A[1:0] == bit[7:6] */


/* TCCR0A => COM0B[1:0] == bit[5:4] */
#define OC0B 0x30 // PD5
#define COM0B_MASK   0x30
#define COM0B_SHIFT  4

	/* COMB_NON_PWM */
	#define DISSCONNECT 0
	#define TOGGLE 1
	#define CLEAR 2
	#define SET 3
	/* COMB_NON_PWM */
	
	/* COMB_FAST_PWM */
	#define DISSCONNECT 0
	#define RESERVED 1
	#define NON_INVERTING 2
	#define INVERTING 3
	/* COMB_FAST_PWM */
	
	/* COMB_PHASE_CORRECT_PWM */
	#define DISSCONNECT 0
	#define RESERVED 1	
	#define NON_INVERTING 2
	#define INVERTING 3
	/* COMB_PHASE_CORRECT_PWM */

/* TCCR0A => COM0B[1:0] == bit[5:4] */

/* TIMSK0 */
#define OCB_MACTH_INTERRUPT_ENABLE 0x04
#define OCA_MACTH_INTERRUPT_ENABLE 0x02
#define OVERFLOW_INTERRUPT_ENABLE 0x01
/* TIMSK0 */

#define WAVE_GENERATION_MASK   0x03
enum waveform_generation_mode
{
	NORMAL,
	PHASE_CORRECT,
	CTC,
	FAST_PWM
};

#define CLOCK_SET_BIT 0x07
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

/* TCCR0A */
void set_waveform_mode(uint8_t waveform_mode);
void set_pwm_pin_mode(uint8_t output_pin, uint8_t output_pin_shift);
/* TCCR0A */

/* TCCR0B */
void set_prescale(uint8_t prescale);
/* TCCR0B */

void set_overflow_intterupt_enable();
int32_t easy_set_overflow_frequency(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency);
int32_t easy_timer_intterupt_setup(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency);
void easy_pwm_setup(uint8_t output_pin, uint8_t ocr_value);

extern enum waveform_generation_mode wave_mode;
#endif /* EASY_TC_H_ */