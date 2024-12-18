# 项目介绍
  本工程结构简单，使用者只需要拉取project即可，其余文件夹均为个人学习路径及关于此项目的一些其他尝试，可忽略不计
  本工程基于STM32H743xx系列进行一个最小控制系统的开发
  暂未进行RTOS移植和FATFS文件管理模块的移植

## 启动流程
  本部分作为额外的一个部分，旨在解决一直以来对于嵌入式设备启动流程的疑惑。在这个部分我将从startup.s启动文件开始，逐层跟踪函数跳转，分析启动流程。

# 代码希望实现功能
  多路SPI通信，多路UART/USART(DMA收发)，IIC通信，多路PWM输出，小屏驱动
  SD卡(SDMMC)和FATFS完成二进制读写实例
  多路PWM输入，支持一路CAN通信

# 编译环境及外部库依赖
  编译器：ARM Compiler(Default Compiler version6)
  默认链接库：MicroLIB
  C/C++标准：C99/C++11
  编译器优化等级：-O0
  外部库依赖：STM32_H7_HAL库及STM32_H7_Speripheral标准外设库
## keil配置选项
  target选项页：ARM Compiler(Default Compiler version6)      Use MicroLIB
  C/C++选项页：C99/C++11     优化等级-O0
  Include链接：外部库头文件及各类其他头文件所在路径

# 代码组织架构
请注意代码架构和普通的keil工程存在一些差异，主要原因是我在VSCODE中进行keil工程开发，EIDE插件为工程创建了一些额外文件及对某些文件进行了汇总，但并不会改变在keil中打开工程时的结构
#### Version1.0
├─.cmsis
│  └─include
├─.eide
├─.vscode
├─Build
│  └─Target 1
│      └─.obj
│          ├─CMSIS
│          │  └─Clock
│          ├─Drivers
│          │  └─Src
│          ├─FATFS
│          │  └─Src
│          ├─Lib
│          │  └─Src
│          ├─Src
│          │  └─App
│          └─Startup
├─CMSIS
│  ├─Clock
│  ├─Compiler
│  ├─Core
│  └─Interrupt
├─Config
├─DebugConfig
├─Docs
├─Drivers
│  ├─Inc
│  └─Src
├─FATFS
│  ├─Docs
│  ├─Inc
│  └─Src
├─Include
│  ├─App
│  └─Interrupt
├─Lib
│  ├─hal_conf
│  ├─Inc
│  │  └─Legacy
│  └─Src
│      └─Legacy
├─Listings
├─Platform
├─Src
│  ├─App
│  └─Interrupt
├─Startup
└─Tools

#### version2.0-遵循CMSIS标准
/ProjectRoot
    ├── /CMSIS                 # CMSIS 标准相关文件
    │   ├── /Core              # 核心文件：内核和启动文件
    │   │   ├── core_cm*.h     # Cortex-M 内核定义
    │   │   ├── startup.s      # 启动文件
    │   │   └── system_<device>.c  # 系统初始化
    │   ├── /Device            # 设备相关：厂商提供的设备定义
    │   │   ├── include        # 寄存器定义文件（*.h）
    │   │   ├── source         # 设备驱动实现（*.c）
    │   │   └── linker         # 链接文件（*.scf 或 *.ld）
    │   └── /RTOS              # 可选：CMSIS-RTOS 适配层（如 FreeRTOS、RTX）
    │       ├── include        # RTOS 接口定义
    │       └── source         # RTOS 适配实现
    │
    ├── /Drivers               # 外设驱动（HAL 或 LL 驱动）
    │   ├── /HAL               # 硬件抽象层
    │   │   ├── /UART          # UART 驱动
    │   │   │   ├── uart.c
    │   │   │   └── uart.h
    │   │   ├── /GPIO          # GPIO 驱动
    │   │   │   ├── gpio.c
    │   │   │   └── gpio.h
    │   │   └── /SPI           # SPI 驱动
    │   │       ├── spi.c
    │   │       └── spi.h
    │   └── /BSP               # 板级支持包（Board Support Package）
    │       ├── board_init.c   # 板级初始化代码
    │       └── board.h        # 板级配置定义
    │
    ├── /Middlewares           # 中间件（如协议栈、文件系统）
    │   ├── /FileSystem        # 文件系统（如 FatFS）
    │   │   ├── ff.c
    │   │   └── ff.h
    │   ├── /USB               # USB 协议栈
    │   │   ├── usb_device.c
    │   │   └── usb_device.h
    │   └── /Network           # 网络协议栈（如 LWIP）
    │       ├── lwip.c
    │       └── lwip.h
    │
    ├── /Application           # 应用层代码
    │   ├── /Main              # 主应用逻辑
    │   │   ├── main.c         # 主函数
    │   │   └── main.h
    │   ├── /Tasks             # 各种任务（如果使用 RTOS）
    │   │   ├── task_sensor.c  # 传感器任务
    │   │   ├── task_communication.c  # 通信任务
    │   │   └── task_ui.c      # 用户界面任务
    │   └── /Config            # 应用配置文件
    │       ├── app_config.h   # 应用层配置
    │       ├── task_config.h  # 任务相关配置
    │       └── board_config.h # 板级配置
    │
    ├── /Utilities             # 辅助工具代码
    │   ├── debug.c            # 调试工具代码
    │   ├── log.c              # 日志记录模块
    │   └── utils.h            # 常用工具函数
    │
    ├── /Docs                  # 项目文档
    │   ├── readme.md          # 工程说明文件
    │   ├── changelog.txt      # 修改记录
    │   └── datasheets         # 数据手册
    │
    ├── /Build                 # 构建输出
    │   ├── /Bin               # 二进制文件（如 *.hex, *.bin）
    │   ├── /Obj               # 中间文件（如 *.o）
    │   └── mapfile.map        # 链接文件映射
    │
    ├── /Scripts               # 自定义构建脚本
    │   ├── build.bat          # Windows 构建脚本
    │   ├── build.sh           # Linux 构建脚本
    │   └── generate_code.py   # 自动生成代码工具
    │
    └── KeilProject            # Keil 项目文件
        ├── Project.uvprojx    # Keil 工程文件
        └── Project.uvoptx     # Keil 配置文件
**此部分并未完完全全遵循CMSIS文件架构，特别是在keil中的文件架构与CMSIS差异很大，接下来做一个更加详细的解释**
├─.cmsis
│  └─include
├─.eide
├─.vscode
├─Application                   # 此部分主要是上层的代码编写
│  ├─config                     # 用作适合当前项目目标平台的配置操作
│  ├─Interrupt                  # 实现功能性中断
│  ├─Main                       # App实现
│  └─Tasks                      # 操作系统任务实现
├─Build                         # 此部分用作项目构建生成中间文件的存储
│  └─Target 1
│      └─.obj
│          ├─Application
│          │  ├─Interrupt
│          │  └─Main
│          ├─CMSIS
│          │  ├─Clock
│          │  └─Core
│          ├─Drivers
│          │  ├─Lib
│          │  │  └─Src
│          │  └─Src
│          ├─FATFS
│          │  └─Src
│          ├─Lib
│          │  └─Src
│          ├─Middlewares
│          │  └─FATFS
│          │      └─Src
│          ├─Src
│          │  └─App
│          └─Startup
├─CMSIS          # 其实就是对针对硬件平台做出了编译器指定，寄存器定义，系统启动，以及适配RTOS，结合CMSIS官方给出的图，**需要注意的是，我把片上外设的寄存器定义也放在了这里面**
│  ├─Compiler    # 这一部分主要是为了跨编译器支持，不同编译器针对不同处理器架构如armCortex-M x86_64 RISC-V等会有不同的优化，所以在跨平台的时候也能让编译器更更好优化
│  ├─Core        # 这个文件夹里面主要包含了有关内核寄存器的定义(core_cm7.h)，MPU相关寄存器的定义(mpu_armv7.h)，启动文件，和系统初始化相关文件
│  ├─Device      # 装链接文件，上面提到的驱动和寄存器定义分别在Driver和/CMSIS/core和CMSIS下的文件解决
│  └─RTOS        # 后面移植RTOS
├─DebugConfig    # 关于Debug的一些配置文件，但是我对debug还不太熟悉
├─Docs
├─Drivers        # 里面包含了外部库驱动和自定义驱动
│  ├─Inc         # 自定义驱动头文件
│  ├─Lib         # HAL库及标准外设库
│  │  ├─hal_conf
│  │  ├─Inc
│  │  │  └─Legacy
│  │  └─Src
│  │      └─Legacy
│  └─Src         # 包含了自定义驱动实现
├─Listings       # 编译生成的中间文件
├─Middlewares    # 文件系统和通信协议栈
│  └─FATFS       # FATFS文件系统移植
│      ├─Docs
│      ├─Inc
│      └─Src
├─Scripts        # 如果只用keil或者VSCODE里面的插件，这个脚本其实基本无用，但考虑到后面的特定开发，先暂留
└─Utilities      # 一些辅助工具，见上，暂留

# 版本更新内容摘要
**暂无更新**

# 编程日志
## 2024.12.18
### 关于时钟配置
以下注释来源于stm32h7xx_ll_rcc.c
```C
/** @note HSE_VALUE is a constant defined in header file (default value 25 MHz), user has to ensure that HSE_VALUE is same as the real frequency of the crystal used. Otherwise, this function may have wrong result.
*/
```
在不同的几个文件中，分别是stm32h7xx_hal_conf.h
```C
/* ########################## Oscillator Values adaptation ####################*/
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSE is used as system clock source, directly or through the PLL).  
  */
#if !defined  (HSE_VALUE) 
#define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz   */
#endif /* HSE_VALUE */
```

systemh7xx_hal_conf_template.h
```C
/* ########################## Oscillator Values adaptation ####################*/
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSE is used as system clock source, directly or through the PLL).
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE    (25000000UL) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT    (100UL)   /*!< Time out for HSE start up, in ms */
#endif /* HSE_STARTUP_TIMEOUT */
```

system_stm32h7xx.c
```C
#include "stm32h7xx.h"
#include <math.h>

#if !defined  (HSE_VALUE)
#define HSE_VALUE    ((uint32_t)25000000) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (CSI_VALUE)
  #define CSI_VALUE    ((uint32_t)4000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* CSI_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)64000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */
```

stm32h7xx_ll_rcc.h
```C
/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_LL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */
#if !defined  (HSE_VALUE)
#if defined(RCC_VER_X) || defined(RCC_VER_3_0)
#define HSE_VALUE    25000000U  /*!< Value of the HSE oscillator in Hz */
#else
#define HSE_VALUE    24000000U  /*!< Value of the HSE oscillator in Hz */
#endif /* RCC_VER_X || RCC_VER_3_0 */
#endif /* HSE_VALUE */
```

可以看到几个文件对HSE_VALUE值的确定存在一些不同，具体最后采用了哪一个值暂不可知，有待后续了解启动流程再确定