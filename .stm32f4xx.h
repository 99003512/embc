
#ifndef STM32F4XX_H
#define STM32F4XX_H

#include <stdint.h>

//defining memory definition

#define SRAM1_BASE_ADDR 0x20000000U
#define SRAM2_BASE_ADDR 0x2001C000U
#define FLASH_BASE_ADDR 0x08000000U

#define ROM_BASE_ADDR  0x1FFF0000U
#define __vo volatile
//defining peripheral base addresses

#define APB1_BASEADDR  0x40000000U
#define APB2_BASEADDR  0x40010000U
#define AHB1_BASEADDR  0x40020000U
#define RCC_BASEADDR   (AHB1_BASEADDR + 0x3800)
//defining the peripherals hanging onto ahb1 bus

#define GPIOA_BASEADDR  (AHB1_BASEADDR + 0x000U)
#define GPIOB_BASEADDR  (AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR  (AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR  (AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR  (AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR  (AHB1_BASEADDR + 0X1400U)
#define GPIOG_BASEADDR  (AHB1_BASEADDR + 0X1800U)
#define GPIOH_BASEADDR  (AHB1_BASEADDR + 0X1C00U)
#define GPIOI_BASEADDR  (AHB1_BASEADDR + 0X2000U)
#define GPIOJ_BASEADDR  (AHB1_BASEADDR + 0X2400U)
#define GPIOK_BASEADDR  (AHB1_BASEADDR + 0X2800U)



#define TIM2_BASEADDR (APB1_BASEADDR)

#define TIM1_BASEADDR (APB2_BASEADDR)


typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];

} GPIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*)GPIOI_BASEADDR)


typedef struct{
		__vo uint32_t CR;
		__vo uint32_t PLLCFGR;
		__vo uint32_t CFGR;
		__vo uint32_t CIR;
		__vo uint32_t AHB1RSTR;
		__vo uint32_t AHB2RSTR;
		__vo uint32_t AHB3RSTR;
			 uint32_t Reserved;
		__vo uint32_t APB1RSTR;
		__vo uint32_t APB2RSTR;
			 uint32_t Reserved1[2];
		__vo uint32_t AHB1ENR;
		__vo uint32_t AHB2ENR;
		__vo uint32_t AHB3ENR;
			 uint32_t Reserved2;
		__vo uint32_t APB1ENR;
		__vo uint32_t APB2ENR;
			 uint32_t Reserved3[2];
		__vo uint32_t AHB1LPENR;
		__vo uint32_t AHB2LPENR;
		__vo uint32_t AHB3LPENR;
		__vo uint32_t Reserved4;
		__vo uint32_t APB1LPENR;
		__vo uint32_t APB2LPENR;
			 uint32_t Reserved5[2];
		__vo uint32_t BDCR;
		__vo uint32_t CSR;
			 uint32_t Reserved6[2];
		__vo uint32_t SSCGR;
		__vo uint32_t PLLI2SCFGR;


} RCC_RegDef_t;

#define RCC  			((RCC_RegDef_t*)RCC_BASEADDR)

//Setting the clock

#define GPIOA_PCLK_EN()    (RCC -> AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()    (RCC -> AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()    (RCC -> AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC -> AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC -> AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()    (RCC -> AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()    (RCC -> AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()    (RCC -> AHB1ENR |= (1<<3))
#define GPIOI_PCLK_EN()    (RCC -> AHB1ENR |= (1<<3))
//resetting



#define GPIOA_PCLK_DIS()  (RCC -> AHB1RSTR |= (1 << 0))
#define GPIOB_PCLK_DIS()  (RCC -> AHB1RSTR |= (1 << 1))
#define GPIOC_PCLK_DIS()  (RCC -> AHB1RSTR |= (1 << 2))
#define GPIOD_PCLK_DIS()  (RCC -> AHB1RSTR |= (1 << 3))
#define GPIOE_PCLK_DIS()  (RCC -> AHB1RSTR |= (1 << 4))



#define GPIOA_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()		do{(RCC->AHB1RSTR |= (1<<8)); (RCC->AHB1RSTR &= ~(1<<8)); }while(0)










#define ENABLE    1
#define DISABLE    0
#define SET      ENABLE
#define RESET     DISABLE
#define GPIO_PIN_SET	SET

#define GPIO_PIN_RESET  RESET



#endif









