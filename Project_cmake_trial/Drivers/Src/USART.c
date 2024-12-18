/*
实现5路UART/USART串口通信，选取USART1\2\3,UART4\8
USART1:TX(PA9),RX(PA10) -复用AF7 -APB2
USART2:TX(PA2),RX(PA3) -复用AF7 -APB1
USART3:TX(PD8),RX(PD9) -复用AF7 -APB1
UART4:TX(PD1),RX(PD0) -复用AF8 -APB1
UART8:TX(PE1),RX(PE0) -复用AF8 -APB1

*/

#include "main.h"

void USART_UART_Init(void) {
    // 关于各GPIO的时钟都在clock_manage.c中打开
    // 关于各GPIO的复用都在GPIO_AF.c中实现
    
    

}