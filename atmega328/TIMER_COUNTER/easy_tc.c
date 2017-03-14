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

void set_pwm_pin_mode(uint8_t output_pin, uint8_t output_pin_shift)
{
	//SET TCCR0A => COM0A[1:0] = bit[7:6]
	//				COM0B[1:0] = bit[5:4]
	
	//CLEAR TARGET (COM0A or COM0B) 
	TCCR0A &= ~output_pin;
	
	//Shift value is set by output_pin's value (COM0A or COM0B)
	TCCR0A |= NON_INVERTING << output_pin_shift;
}

void set_prescale(uint8_t prescale)
{
	//Set TCCR0B => CS0[2:0] 
	 
	//Clear prescaler and Set prescaler
	TCCR0B &= ~CLOCK_SET_BIT;
	TCCR0B |= prescale;
}

void set_overflow_intterupt_enable()
{
	//Set TIMSK0 => TOIE = bit[0]
	TIMSK0 |= OVERFLOW_INTERRUPT_ENABLE;
	
	//Set SREG => I = bit[7]
	sei();
}

int32_t easy_set_overflow_frequency(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency)
{
	// This function is special.
	// This function set how many happen overflow in 1 second.
	// overflow_frequency mean how many happen overflow in 1 second.
	
	// Match enum clock_select's prescale with real presacle value.
	// (0x01)CLOCK_1 => 1 ... (0x02)CLOCK_8 => 8 ... (0x03)CLOCK_64 => 64 ...
	
	switch(prescale)
	{
		case CLOCK_1 :
			prescale = 1;
			break;
			
		case CLOCK_8 :
			prescale = 8;
			break;
		
		case CLOCK_64 :
			prescale = 64;
			break;
			
		case CLOCK_1024 :
			prescale = 1024;
			break;
			
		default:
			return -2;
	}
	
	double tcnt_value = 256 - ( clock_frequency / prescale / overflow_frequency);

	// if the decimal point not exist, effective value.
	if( (uint32_t)tcnt_value - tcnt_value == 0 )
	{
		printf("%d\n", (uint8_t)tcnt_value);
		TCNT0 = (uint8_t)tcnt_value;
		return (uint8_t)tcnt_value;
	}
	
	else
		return -1;
}

int32_t easy_timer_intterupt_setup(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency)
{
	/* TCCR0A */
	set_waveform_mode(NORMAL);
	/* TCCR0A */
	
	/* TCCR0B */
	set_prescale(prescale);
	/* TCCR0B */
	
	return easy_set_overflow_frequency(clock_frequency, prescale, overflow_frequency);
}

void easy_pwm_setup(uint8_t output_pin, uint8_t ocr_value)
{
	/* TCCR0A */
	set_waveform_mode(PHASE_CORRECT);
	/* TCCR0A */
	
	/* TCCR0B */
	set_prescale(CLOCK_64);
	/* TCCR0B */
	
	switch(output_pin)
	{
		case OC0A :
			OCR0A = ocr_value;
			set_pwm_pin_mode(output_pin, COM0A_SHIFT);
			break;
			
		case OC0B : 
			OCR0B = ocr_value;
			set_pwm_pin_mode(output_pin, COM0B_SHIFT);
			break;
	}
}