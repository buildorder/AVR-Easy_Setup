USART
=

####함수
    void easy_uart_setup(uint32_t baudrate, uint32_t cpu_frequency)

####인자(Parameters)
1. baudrate      : 통신 상대와 통신하는 속도를 설정합니다.
2. cpu_frequency : 사용하는 MCU의 CLOCK의 값을 전달합니다. (ex : 16Mhz = 16000000)

####설명
stdin과 stdout을 사용하기 위해 이 함수를 사용합니다.

STREAM을 생성하여 stdin과 stdout을 연결합니다.

이로서, printf와 scanf등 stdin과 stdout을 사용하는 함수를 사용할 수 있습니다.
