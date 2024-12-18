/*
此文件主要用于配置整个工程的GPIO复用
*/

#include "main.h"


void GPIO_AF_Config(void) {
    // SPI复用
    // SPI1
    GPIOD->MODER |= 0x02<<14; // 调整PD7为复用功能模式
    GPIOD->AFR[0] |= 0x05<<28; // 调整PD7复用为AF5
    GPIOG->MODER |= 0x2A<<18; // 调整PG9-11为复用功能模式
    GPIOD->AFR[1] |= 0x555<<4; // 调整PG9-11复用为AF5
    // SPI2
    GPIOB->MODER |= 0xAA<<24; // 调整PB12-15为复用功能模式
    GPIOB->AFR[1] |= 0x5555<<16; // 调整PB12-15复用为AF5
    // SPI3
    GPIOA->MODER |= 0x02<<8; // 调整PA4为复用功能模式
    GPIOA->AFR[0] |= 0x06<<16; // 调整PA4复用为AF6
    GPIOC->MODER |= 0x2A<<20; // 调整PC10-12为复用功能模式
    GPIOC->AFR[1] |= 0x666<<8; // 调整PC10-12复用为AF6
    // SPI4
    GPIOE->MODER |= 0x2A2<<4; // 调整PE2-5为复用功能模式
    GPIOE->AFR[0] |= 0x55505<<8; //调整PE2-5复用为AF5
    // SPI5
    GPIOF->MODER |= 0xAA<<12; // PF6-9
    GPIOF->AFR[0] |= 0x55<<24;
    GPIOF->AFR[1] |= 0x55;
    // SPI6
    GPIOF->MODER |= 0x02<<16; // PG8
    GPIOF->MODER |= 0X2A<<24; // PG12-14
    GPIOF->AFR[1] |= 0x05;
    GPIOF->AFR[1] |= 0x555<<16;
    
    // USART复用
    // USART1
    GPIOA->MODER |= 0x0A<<18; //PA9 PA10
    GPIOA->AFR[1] |= 0x77<<4;
    // USART2
    GPIOA->MODER |= 0x0A<<4; // PA2 PA3
    GPIOA->AFR[0] |= 0x77<<8;
    //USART3
    GPIOD->MODER |= 0x0A<<16; //PD8 PD9
    GPIOD->AFR[1] |= 0x77;
    //UART4
    GPIOD->MODER |= 0x0A; // PD0 PD1
    GPIOD->AFR[0] |= 0x88;
    //UART8
    GPIOE->MODER |= 0x0A; //PE0 PE1
    GPIOE->AFR[0] |= 0x88;
    
    // CAN复用
    // FDCAN1
    GPIOB->MODER |= 0x0A<<16; //PB8 PB9
    GPIOB->AFR[1] |= 0x99;
    
    
    // I2C复用
    
    
}

