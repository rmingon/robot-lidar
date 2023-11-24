void lidarInit() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;

	GPIO_Init(GPIOC, &GPIO_InitStruct);

	TIM3_PWM_Init();

	UART4_Init();

	lidarStop();
}

void lidarSpeedMotor(uint16_t dutyCycle) {
	TIM3->CCR3 = dutyCycle;
}

void lidarStop() {
	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);
}

void lidarStart() {
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
	GPIO_SetBits(GPIOC, GPIO_Pin_2);
}

void TIM3_PWM_Init() {

    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    GPIOC->MODER |= GPIO_MODER_MODER0_1;
    GPIOC->AFR[0] |= 0x2 << (0 * 4);

    TIM3->PSC = 1000 - 1;
    TIM3->ARR = 100 - 1;

    TIM3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
    TIM3->CCER |= TIM_CCER_CC3E;

    TIM3->CR1 |= TIM_CR1_CEN;
}

void UART4_Init() {
    RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= GPIO_MODER_MODER0_1;
    GPIOA->AFR[0] |= 0x8 << (0 * 4);// (PA0)

    GPIOA->MODER |= GPIO_MODER_MODER1_1;
    GPIOA->AFR[0] |= 0x8 << (1 * 4); // (PA1)

    UART4->BRR = SystemCoreClock / 128000; // DEFAULT YDLIDAR BAUD 128000
    UART4->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; // Enable UART4, transmitter, and receiver
}

void UART4_SendChar(char c) {
    // Wait until the transmit data register is empty
    while (!(UART4->SR & USART_SR_TXE))
        ;
    UART4->DR = c; // Transmit character
}

char UART4_ReceiveChar() {
    // Wait until data is received
    while (!(UART4->SR & USART_SR_RXNE))
        ;
    return UART4->DR; // Read received character
}
