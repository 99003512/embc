/*
 * stmp32f407xx_gpio_driver.h
 *
 *  Created on: 24-Feb-2021
 *      Author: Karthik Manoj
 */

#ifndef INC_STMP32F407XX_GPIO_DRIVER_H_
#define INC_STMP32F407XX_GPIO_DRIVER_H_

#include "stmp32f407xx.h"


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPu;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;

	uint8_t GPIO_PinAltFuncMode;

}GPIO_PinConfig_t;


typedef struct
{
GPIO_RegDef_t *pGPIOx;
GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_HANDLE_t;

#define GPIO_PIN_NO_0    0
#define GPIO_PIN_NO_1    1
#define GPIO_PIN_NO_2    2
#define GPIO_PIN_NO_3    3
#define GPIO_PIN_NO_4    4
#define GPIO_PIN_NO_5    5
#define GPIO_PIN_NO_6    6
#define GPIO_PIN_NO_7    7
#define GPIO_PIN_NO_8    8
#define GPIO_PIN_NO_9    9
#define GPIO_PIN_NO_10   10
#define GPIO_PIN_NO_11   11
#define GPIO_PIN_NO_12   12
#define GPIO_PIN_NO_13   13
#define GPIO_PIN_NO_14   14
#define GPIO_PIN_NO_15   15



#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OP		1

//speed of GPIOx

#define GPIO_MODE_IN	     0
#define GPIO_MODE_OUT        1
#define GPIO_MODE_ALTFN      2
#define GPIO_MODE_ANALOG     3

#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3



#define GPIO_NO_PUPD  		0
#define GPIO_NO_PU  		1
#define GPIO_NO_PD  		2



//to control clock
void GPIO_PeriClockControl(GPIO_RegDef_t *pGIPOx, uint8_t EnorDi);




void GPIO_init(GPIO_HANDLE_t *pGPIOHandle);

void GPIO_Deinit(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGIPOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGIPOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGIPOx, uint8_t PinNumber);







#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
#endif /* INC_STMP32F407XX_GPIO_DRIVER_H_ */
