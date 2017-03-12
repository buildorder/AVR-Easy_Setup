AVR-Easy_Setup Document
=
1.프로젝트 설명
-
###1-1. 이게 무엇인가?
AVR-Easy_Setup은 AVR을 다루면서 쉽게 여러 모듈과 기능들을 Setup하고 사용하여 개발 시간을 단축시키기 위해 있습니다.

###1-2. 개발 환경
1. 하드웨어 : Atmega328p를 기반으로 작성하였으며, 다른 Atmega시리즈 칩에는 약간의 수정을 하고 사용하면 됩니다.
2. 컴파일러 : AVR-GCC

2.사용법
-
###2-1. USART
    void easy_uart_setup(uint32_t baudrate, uint32_t cpu_frequency)

####2-1-1. 인자(Parameters)
1. baudrate      : 통신 상대와 통신하는 속도를 설정합니다.
2. cpu_frequency : 사용하는 MCU의 CLOCK의 값을 전달합니다. (ex : 16Mhz = 16000000)

####2-1-2. 간략한 설명
stdin과 stdout을 사용하기 위해 이 함수를 사용합니다.

STREAM을 생성하여 stdin과 stdout을 연결합니다.

이로서, printf와 scanf등 stdin과 stdout을 사용하는 함수를 사용할 수 있습니다.

###2-2. TIMER/COUNTER
    void easy_pwm_setup(uint8_t output_pin, uint8_t ocr_value);

####2-2-1. 인자(Parameters)
1. output_pin : PWM 파형을 출력하고 싶은 핀을 선택합니다. (ex : OC0A, OC0B)
2. ocr_value  : OCR0(A, B) 값을 정합니다.

####2-2-2. 간략한 설명
기본적으로 PHASE_CORRECT 모드에 NON-INVERTING 모드로 작동하게 했습니다.

분주비는 64를 기본으로 합니다.

####2-2-3. 추가/수정 해야할 것
1. 이슈참조
2. PWM핀 모두 지원 (현재 OC0A, OC0B만 지원)
