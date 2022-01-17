/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F103VET6) board pin assignments
 * https://github.com/makerbase-mks/MKS-Robin-Nano-V1.X/tree/master/hardware
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME "MKS Robin Nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//
// Thermocouples
//
//#define TEMP_0_CS_PIN                     PE5   // TC1 - CS1
//#define TEMP_0_CS_PIN                     PE6   // TC2 - CS2

//#define LED_PIN                           PB2

#include "pins_MKS_ROBIN_NANO_common.h"

#if HAS_FSMC_TFT
    #undef TFT_BUFFER_SIZE
    #define TFT_BUFFER_SIZE                  320*8
#endif

#if HAS_TFT_LVGL_UI && FAN1_PIN != PB0 && HEATER_1_PIN != PB0
  #define BOARD_INIT OUT_WRITE(PB0, LOW)
#endif

/*
Модуль MKS WIFI
*/
#define MKS_WIFI

#ifdef MKS_WIFI

 #define MKS_WIFI_SERIAL_NUM                SERIAL_PORT_2
 #define MKS_WIFI_UART                      USART1
  #undef PLATFORM_M997_SUPPORT

 #define MKS_WIFI_IO0                       PA8
 #define MKS_WIFI_IO4                       PC7
 #define MKS_WIFI_IO_RST                    PA5
#endif
