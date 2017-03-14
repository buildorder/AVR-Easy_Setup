TIMER/COUNTER
=

오버플로우 주기 설정
-

#### 1-1. 함수
    int32_t easy_set_overflow_frequency(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency);

#### 1-2. 인자(Parameters)
1. clock_frequency    : 사용하는 MCU의 CLOCK의 값을 전달합니다. (ex : 16Mhz = 16000000)
2. prescale           : 사용할 분주비를 입력합니다.
3. overflow_frequency : 오버플로우를 1초 동안 몇번 실행할지 정합니다.

#### 1-3. 설명
이 함수를 통해 1초동안 원하는 만큼 오버플로우 인터럽트를 발생시킬 수 있습니다.

식을 통해 설정해야할 TCNT 값을 구하고 반환 해줍니다.

#### 1-4. 반환
-1 : 잘못된 값(설정할 수 없는 TCNT)

-2 : 잘못된 분주비(설정할 수 없는 PRESCALE)

그 이외의 값 : 정상적인 TCNT값

오버플로우 인터럽트 설정
-

#### 2-1. 함수
    int32_t easy_timer_intterupt_setup(uint32_t clock_frequency, uint8_t prescale, uint32_t overflow_frequency);

#### 2-2. 인자(Parameters)
1. clock_frequency    : 사용하는 MCU의 CLOCK의 값을 전달합니다. (ex : 16Mhz = 16000000)
2. prescale           : 사용할 분주비를 입력합니다.
3. overflow_frequency : 오버플로우를 1초 동안 몇번 실행할지 정합니다.

#### 2-3. 설명
작동모드(WGM)를 NORMAL 모드로 설정하고, 분주비(CS)를 설정한다.

인자를 가지고 easy_set_overflow_frequency() 함수를 호출한다.

#### 2-4. 반환
-1 : 잘못된 값(설정할 수 없는 TCNT)

-2 : 잘못된 분주비(설정할 수 없는 PRESCALE)

그 이외의 값 : 정상적인 TCNT값

PWM 파형 출력
-

#### 3-1. 함수
    void easy_pwm_setup(uint8_t output_pin, uint8_t ocr_value);

#### 3-2. 인자
1. output_pin : PWM 파형을 출력하고 싶은 핀을 선택합니다. (ex : OC0A, OC0B)
2. ocr_value  : OCR0(A, B) 값을 정합니다.

#### 3-3. 간략한 설명
기본적으로 PHASE_CORRECT 모드에 NON-INVERTING 모드로 작동하게 했습니다.

분주비는 64를 기본으로 합니다.
