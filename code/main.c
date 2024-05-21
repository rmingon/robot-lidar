#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "motor/motor.h"
#include "lidar/lidar.h"
#include "linkit/linkit.h"
#include <stdio.h>

volatile uint32_t msTicks;

void SysTick_Handler(void) {
    msTicks++;
}

void Delay_ms(uint32_t ms) {
    uint32_t start = msTicks;
    while ((msTicks - start) < ms) {}
}

void ledInit() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}


int main(void) {
	SystemInit();
	SysTick_Config(SystemCoreClock / 1000);
	motorInit();


	lidarInit();
	lidarStart();

	linkitInit();

	while(1) {

		lidarSpeedMotor(20);
		Delay_ms(1000);

		lidarSpeedMotor(100);
		Delay_ms(2000);


		lidarStop();
		Delay_ms(5000);

		/*
		forward();
		Delay_ms(500);

		backward();
		Delay_ms(500);

		right();
		Delay_ms(500);

		left();
		Delay_ms(500);

		forwardRight();
		Delay_ms(500);

		forwardLeft();
		Delay_ms(500);

		backwardRight();
		Delay_ms(500);

		backwardLeft();
		Delay_ms(500);

		turningRight();
		Delay_ms(500);

		turningLeft();
		Delay_ms(500);

		lateralArcLeft();
		Delay_ms(500);

		lateralArcRight();
		Delay_ms(500);
		*/
	}
}
