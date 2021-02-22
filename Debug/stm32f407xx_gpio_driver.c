/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 20-Feb-2021
 *      Author: Training
 */
#include <stdint.h>
#include "stm32f407xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){

	if(pGPIOx == GPIOA){
		GPIOA_PCLK_EN();
	}else if (pGPIOx == GPIOB)
	{
		GPIOB_PCLK_EN();
	}
	else if (pGPIOx == GPIOC){
		GPIOC_PCLK_EN();
	}
	else if (pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
	else if (pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
	else if (pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}
	else if (pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}
	else if (pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
	else if (pGPIOx == GPIOI){
			GPIOI_PCLK_EN();
		}

}



void GPIO_init(GPIO_HANDLE_t *pGPIOHandle){

	uint32_t temp=0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<< (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinMode));
	//0x3 is 11
	pGPIOHandle->pGPIOx-> MODER  &= ~(0x3<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinMode));
	pGPIOHandle->pGPIOx-> MODER |=temp;

	//2. configure speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<< (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed));
	pGPIOHandle->pGPIOx->OSPEEDR |=temp;
	//3. pupd

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<< (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl));
	pGPIOHandle->pGPIOx->PUPDR |=temp;

	// 4. outype

	temp= (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<< pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType);
	pGPIOHandle->pGPIOx->OTYPER |=temp;

	//5. Alternate function low regster
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
	uint32_t temp1, temp2 = 0;
	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%9;
	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xf<<(4*temp2));
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFuncMode << (4*temp2));
	}
}

void GPIO_Deinit(GPIO_RegDef_t *pGPIOx ){
	if(pGPIOx == GPIOA){
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB){
	GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC){
		GPIOC_REG_RESET();
		}
	else if(pGPIOx == GPIOD){
		GPIOD_REG_RESET();
		}
	else if(pGPIOx == GPIOE){
		GPIOE_REG_RESET();
		}
	else if(pGPIOx == GPIOF){
		GPIOF_REG_RESET();
		}
	else if(pGPIOx == GPIOG){
		GPIOG_REG_RESET();
		}
	else if(pGPIOx == GPIOH){
		GPIOH_REG_RESET();
		}
	else if(pGPIOx == GPIOI){
		GPIOI_REG_RESET();
		}
}
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
uint8_t value;
value = (uint8_t) ((pGPIOx->IDR>>PinNumber)& 0x00000001);
return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = pGPIOx->IDR;
	return value;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value){
if(value==GPIO_PIN_SET){
	pGPIOx->ODR |= (1<<PinNumber);
}else{
	pGPIOx->ODR &= ~(1<<PinNumber);
}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value){
pGPIOx->ODR = value;

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (1<<PinNumber);
}



