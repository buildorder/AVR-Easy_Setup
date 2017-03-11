AVR-Easy_Setup Document
=
프로젝트 설명
-
###이게 무엇인가?
AVR-Easy_Setup은 AVR을 다루면서 쉽게 여러 모듈과 기능들을 Setup하고 사용하여 개발 시간을 단축시키기 위해 있습니다.

###개발 환경
하드웨어 : Atmega328p를 기반으로 작성하였으며, 다른 Atmega시리즈 칩에는 약간의 수정을 하고 사용하면 됩니다.

컴파일러 : AVR-GCC



사용법
-
###USART
    void easy_uart_setup(uint32_t baudrate, uint32_t cpu_frequency)

#인자(Parameters)
>baudrate      : 통신 상대와 통신하는 속도를 설정합니다.

>cpu_frequency : 사용하는 MCU의 CLOCK의 값을 전달합니다. (ex : 16Mhz = 16000000)
