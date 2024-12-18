/* 
  这个文章主要用于配置Clock，先放在这里，不一定能配好
  如果这个文件配不好，直接修改SystemInit里面的函数即可
 */

#include "main.h"

void Clock_Manage(void) {
    
}

void Clock_Needed(void) {
    RCC->AHB4ENR |= 0x07FF; // 将所有GPIO口的时钟全部打开
    
    // SPI时钟
    RCC->APB1LENR = (0x03<<14); // 使能SPI2/3时钟
    RCC->APB2ENR = (0x03<<12); // 使能SPI1/4时钟
    RCC->APB2ENR |= (0x01<<20); // 使能SPI5时钟
    RCC->APB4ENR = (0x01<<5); // 使能SPI6时钟
    
    // USART/UART时钟
    RCC->APB1LENR |= 0x01<<31; // 使能UART8时钟
    RCC->APB1LENR |= 0X01<<19; // 使能UART4时钟
    RCC->APB1LENR |= 0x03<<17; // 使能USART2，USART3时钟
    RCC->APB2ENR  |= 0x01<<4;  // 使能USART1时钟
    
    // 使能CAN时钟
    RCC->APB1HENR |= 0x01<<8; // 使能FDCAN时钟
}