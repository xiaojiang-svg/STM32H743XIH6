/*
本文件主要用于初始化CAN通信,只需要实现1路CAN
FDCAN1:FDCAN_TX(PB9),FDCAN_RX(PB8) -复用AF9 -APB1
*/

#include "main.h"

void CAN_Init(void) {
    // 关于各GPIO的时钟都在clock_manage.c中打开
    // 关于各GPIO的复用都在GPIO_AF.c中实现

}