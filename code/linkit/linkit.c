void linkitInit() {
	UART5_Init();
}

void UART5_Init() {
    // Enable UART5 clock
    RCC->APB1ENR |= RCC_APB1ENR_UART5EN;

    // Enable GPIO clocks for UART5 (GPIOC)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Configure PC12 as alternate function mode for UART5_TX
    GPIOC->MODER |= GPIO_MODER_MODER12_1; // Alternate function mode
    GPIOC->AFR[1] |= 0x8 << ((12 - 8) * 4); // AF8 for UART5_TX (PC12)

    // Configure PD2 as alternate function mode for UART5_RX
    GPIOD->MODER |= GPIO_MODER_MODER2_1; // Alternate function mode
    GPIOD->AFR[0] |= 0x8 << (2 * 4); // AF8 for UART5_RX (PD2)

    // Configure UART5 settings (baud rate, data bits, etc.)
    UART5->BRR = 1667; // For example, assuming 9600 baud rate (adjust as needed)
    UART5->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; // Enable UART5, transmitter, and receiver
}
