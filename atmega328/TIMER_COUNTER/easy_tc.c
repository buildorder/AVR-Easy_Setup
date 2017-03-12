#include "easy_tc.h"

void set_waveform_mode(uint8_t waveform_mode)
{
	//Set TCCR0A  => WGM0[1:0] = bit[1:0]
	//*Except TCCR0B => WGM0[2]*
	
	//Clear waveform_mode and Set waveform_mode
	TCCR0A &= ~WAVE_GENERATION_MASK;
	TCCR0A |= waveform_mode;
	
	enum waveform_generation_mode wave_mode = waveform_mode;
}

void set_pwm_pin_mode(uint8_t output_pin)
{
	//SET TCCR0A => COM0A[1:0] = bit[7:6]
	//				COM0B[1:0] = bit[5:4]
	
	//CLEAR TARGET (COM0A or COM0B) 
	TCCR0A &= ~output_pin;
	
	//Shift value is set by output_pin's value (COM0A or COM0B)
	TCCR0A |= NON_INVERTING << (output_pin == OC0A ? COM0A_SHIFT : COM0B_SHIFT);
}

void set_prescale(uint8_t prescale)
{
	//Set TCCR0B => CS0[2:0] 
	 
	//Clear prescaler and Set prescaler
	TCCR0B &= ~CLOCK_SET_BIT;
	TCCR0B |= prescale;
}

void easy_timer_intterupt_setup(uint8_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency)
{
	/* TCCR0A */
	set_waveform_mode(NORMAL);
	/* TCCR0A */
}

void easy_pwm_setup(uint8_t output_pin, uint8_t ocr_value)
{
	/* TCCR0A */
	set_waveform_mode(FAST_PWM);
	set_pwm_pin_mode(output_pin);
	/* TCCR0A */
	
	/* TCCR0B */
	set_prescale(CLOCK_8);
	/* TCCR0B */
	
	OCR0B = ocr_value;
}