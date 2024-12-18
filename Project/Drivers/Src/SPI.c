#include "main.h"

/* 
要求至少四路SPI，暂时先配置6路，不借用LCD接口资源
SPI6:APB4
SPI1\4\5:APB2
SPI2\3:APB1

SPI1:SCK(PG11),MISO(PG9),NSS(PG10),MOSI(PD7)-复用AF5
SPI2:SCK(PB13),MISO(PB14),NSS(PB12),MOSI(PB15)-复用AF5
SPI3:SCK(PC10),MISO(PC11),NSS(PA4),MOSI(PC12)-复用AF6
SPI4:SCK(PE2),MISO(PE5),NSS(PE4),MOSI(PE6)-复用AF5
SPI5:SCK(PF7),MISO(PF8),NSS(PF6),MOSI(PF9)-复用AF5
SPI6:SCK(PG13),MISO(PG12),NSS(PG8),MOSI(PG14)-复用AF5
 */

/** @brief 此部分用于SPI通信协议的学习备注
 * 1. 接口可设置主从，配置为主模式时需要为从器件提供时钟
 * 2. 器件选择信号由主模式提供，也可以选择由从器件接收
 * 3. 全双工 半双工 单工
 * 4. 设置为主器件时，需要RCC的时钟来提供工作时钟
 * 5. 需要访问SPI寄存器时，SPI_PCLK时钟必须有效，SPI_PCLK时钟主要是给外设总线提供时钟
 */

/** @brief 本段函数用于各SPI初始化
 * 
 */
void SPI_Init(void) {
    // 关于各GPIO的时钟都在clock_manage.c中打开
    // 关于各GPIO的复用都在GPIO_AF.c中实现
    
    // 1. 对SPI_CFG1和SPI_CFG2寄存器进行写操作，配置为主模式

    // 2. 对PSI_CR2寄存器进行写操作以选择传输的长度，如果值未知，必须将TSIZE编程为0

    // 3. 对SPI_CRCPOLY进行写操作，并对SPI2S_CR1寄存器的TCRCINI,RCRCINI和SRC33_17位进行写操作，以根据需要配置CRC多项式和CRC计算

    // 4. 如果使用DMA数据流，在DMA寄存器中配置SPI Tx和Rx专用的DMA数据流

    // 5. 如果需要配置保护，对SPI_CFG1寄存器的IOLOCK位进行编程

    // 关于使能，建议在主器件发送时钟之前配置和使能SPI从器件
    
    
}

/** @brief 本函数用于禁止SPI
 * 
 */
bool SPI_Stop(void) {
  
}
