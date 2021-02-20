/*
 * 001led_toggle.c
 *
 *  Created on: 20-Feb-2021
 *      Author: Training
 */
#include "stm32f4xx.h"

#include "stm32f407xx_gpio_driver.h"
#include<stdint.h>




	void delay(void){
		for(uint8_t d=0;d<500000; d++);

	}



	int main(void){
		GPIO_HANDLE_t GpioLed;
		GpioLed.pGPIOx= GPIOD;
		GpioLed.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_12;
		GpioLed.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_OUT;
		GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;
		GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PD;
		GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
		GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_init(GPIOD);
		while(1){
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);



		}



	return 0;

	}


