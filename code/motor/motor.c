#include "motor.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

void motorInit() {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	stop();
}


void stop() {
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);
}

void forward() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_9);
    GPIO_SetBits(GPIOA, GPIO_Pin_10);
    GPIO_SetBits(GPIOB, GPIO_Pin_13);
    GPIO_SetBits(GPIOB, GPIO_Pin_15);
}

void backward() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    GPIO_SetBits(GPIOA, GPIO_Pin_11);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void left() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    GPIO_SetBits(GPIOA, GPIO_Pin_10);
    GPIO_SetBits(GPIOB, GPIO_Pin_13);
    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void right() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_9);
    GPIO_SetBits(GPIOA, GPIO_Pin_11);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    GPIO_SetBits(GPIOB, GPIO_Pin_15);
}

void forwardRight() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_9);
    GPIO_SetBits(GPIOB, GPIO_Pin_15);
}

void forwardLeft() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_10);
    GPIO_SetBits(GPIOB, GPIO_Pin_13);
}

void backwardRight() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_11);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void backwardLeft() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void turningRight() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    GPIO_SetBits(GPIOA, GPIO_Pin_10);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    GPIO_SetBits(GPIOB, GPIO_Pin_15);
}

void turningLeft() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_9);
    GPIO_SetBits(GPIOA, GPIO_Pin_11);
    GPIO_SetBits(GPIOB, GPIO_Pin_13);
    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void lateralArcRight() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    GPIO_SetBits(GPIOA, GPIO_Pin_10);
}

void lateralArcLeft() {
	stop();
    GPIO_SetBits(GPIOA, GPIO_Pin_9);
    GPIO_SetBits(GPIOA, GPIO_Pin_11);
}
