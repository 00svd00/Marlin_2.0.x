/*==========================================================================
*=================== FLSunQ - DELTA Printers ===============================
*================= With pins_MKS_ROBIN_MINI.h BOARD (QQS-Pro)===============
*================= With pins_FLSUN_HiSPEED.h BOARD (QQS-Pro)================
*================= With pins_MKS_ROBIN_NANO.h BOARD (Q5)====================
*================= With pins_MKS_ROBIN_NANO_V1_3_F4.h BOARD (Q5-2021-)======
*================= With pins_MKS_ROBIN_NANO_V3.h BOARD (SRM)================
*================= With pins_BTT_SKR_V1_3.h BOARD (SRB)=====================
*===========================================================================
*                         MARLIN_v2.0.9.3
* For a Delta printer start with one of the configuration files in
* the directory and customize for your machine:
* https://github.com/MarlinFirmware/Configurations/tree/release-2.0.9.3/config/examples/delta/FLSUN/ 
* 
* Wiki: https://github.com/Foxies-CSTL/Marlin_2.0.x/wiki
* 
* TIPS/NOTES:
* -For TMC mode UART, look the "pins_FLSUN_HISPEED.h" file (src/pins/stm32f1/) for more information to wire.
* -To enable Stallguard function (Homing and/or probing) with TMC2209 with wiring Diag/EndStop.
* -Comment/Uncomment line to add or modify some options. 
*  Default is actif for QQS and it's uncommented ;-)
*/
//For run tests on my dev'printers!!
//#define XP_DEV
//===================================================
#ifndef XP_DEV                       // (Default)

/*_______________________1___________________________*/
//==================== Hardware =====================//
/*-------------Motherboard/Printer-(1 CHOICE)-------*/
//#define QQSP                         // (Default_QQS) env = flsun_hispeedv1
#define Q5                         // env = mks_robin_nano35 or (Q5_2021) env = mks_robin_nano_v1_3_f4
#define DEBUG_TO_UART
                                     // for Q5_2021 = uncomment/comment your MoBo in configuration.h (Line114)
//#define SR_MKS                     // env = mks_robin_nano_v3_usb_flash_drive_msc
//#define SR_BTT                     // env = lpc1768
              
      // NOTE: change in platformio.ini file or
      // click on the "Default" icon on the bottom edge of the window and 
      // choose "env:xxxxxxx").

/*________________________2___________________________*/
          /*-----Type Stepper Drivers-(1 CHOICE)-----*/
/* MODE STOCK for QQS & Q5 & SR */
#define STOCK                         // (S) (Default_QQS) For 4xA4988(green or red color).
                                      // (S) (Default_Q5) For 3xTMC2208+1xA4988.
                                      // (S) (Default_SR) For 4xTMC2209_UART.

/* MODE STANDALONE XYZ+E for QQS & Q5 */
//#define ALL_TMC8                    // (8) For 4xTMC2208_STANDALONE
//#define ALL_TMC9                    // (9) For 4xTMC2209_STANDALONE

/* MODE UART XYZ+E for QQS & Q5 */
//#define Q_UART8                     // (U8) 4xTMC2208_UART Note: remove on your printer the module WIFI and wire your TMC.
//#define Q_UART9                     // (U9) 4xTMC2209_UART Note: remove on your printer the module WIFI and wire your TMC.

/* SPECIAL MODE UART XYZ+E for QQS-Pro */
//#define QQS_UARTH                   // (UH) Mode special 2209 wiring with one I/O pin (Remove module ESP12)

/**========================2bis=================================//
 * -- If you have an other stepper driver for EXTRUDER----------//
 * -- Uncomment and choose Options: ----------------------------//
 * -- A4988/DRV8825/LV8729/...      ----------------------------//
 * -- TMC2208_STANDALONE/TMC2209_STANDALONE/TMC2208/TMC2209. ---//
 * =============================================================//
 */
#define DRIVER_EXT TMC2209_STANDALONE    //TMC2209_STANDALONE //A4988//TMC2209  // LV8729//
//Only WITH Q5 older stepper(A4988/DRV8825/LV8729)
//#define INV_EXT

/*__________________________3________________________________*/
        /** =============================
        * =====Type of TFT screen ======
        * == Choice UI TFT (1 CHOICE) ==
        * ==============================
        */
#if ANY(Q5, QQSP)
                /*--- Choice UI TFT ----*/
  #define TFT_COLOR_UI           //(C) (Default) UI Color MARLIN
  //#define TFT_CLASSIC_UI       //(F) Standard LCD (UI Classic LCD)
  //#define TFT_LVGL_UI          //(I) Standard LCD (UI Color MKS) Color MKS (Bug with captor sensor PR22595)
  //#define TFT_BTT_UI           //(r) UI Classic (emulation LCD Marlin) for BTT TFT screen.
  //#define TFT_DWIN_UI          //(D) UI for DGUS screen

  //#define TFT_GENERIC          // For the user who haven't the same screen.
#else
  #define TFT_BTT_UI             //(r) UI Classic (emulation LCD Marlin)
  //#define TFT_DWIN_UI          //(D) UI for DGUS screen like CrealityTouch or Mks H43
#endif

/* ========================================//
* === Note:Languages already integrated ===// 
* ==== in the menu(fr, de, es, it)    =====//
* == For TFT_COLOR_UI, TFT_CLASSIC_UI =====//
* =========================================//
*/
//#define LCD_LANGUAGE en                // Change for your country ('bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'el':'Greek', 'fi':'Finnish', 'hr':'Croatian', 'hu':'Hungarian', 'jp_kana':'Japanese', 'nl':'Dutch', 'pl':'Polish', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', etc)
#define BOOT_MARLIN_LOGO_SMALL         // Small Logo Marlin to reduce de binary. Comment to have normal LOGO(Default).

/*_________________________________4______________________________*/
          /*---- Extruder, Custom effector and Modules -----*/

/**=========================================================
 * =========================================================
 * = QQS/Q5 Stock have a clone (T)ITAN Extruder(Default) ===
 * = SR Stock have a clone (B)MG Extruder (Default) ========
 * = If you have another choose by uncomment your extruder.=
 * ======= Also you can change the direction.===============
 * === Default eStep (T=397/422)/(B=417)/(X+722)/(Lgx562)===
 * =========================================================
 */
                  /* User settings extruder */
//#define INV_EXT                        // Uncommment to reverse direction for BMG_righ/Sherpa/SDHX/LGX.
//#define EXTRUDER_STEPS 562             // Ajust your eSteps.

// BMG_right Extruder (B) step(417) ou SuperDriveHX Extruder (n) step(720).
#define BMG                            //(B) Uncommment for BMG_left.
//#define NEMA14                         //(X) Uncommment for Mini-Sherpa/SuperDrive/Lgx.
//#define OMG                            //(O) Uncommment for OMG.
                  /*  Custom Effector  */
                  /* rods, height, arms*/
//#define SDHX                           // Custom effector with Direct_Drive SuperDriveHX()
//#define FKSN                           // Customn effector FRANKENSUN
                  /* Module Socket_Wifi */ 
#define MOD_WIFI                         //(W) (Default_QQS) With Module ESP8266/ESP12 or Connexion Tx/RX
#define MKS_WIFI
//#define ESP3D_30                       //(w) Enable firmware ESP3D v3.0 (ESP8266/ESP12) only with TFT_LVGL_UI

                  /* Option for Neopixel */
//For LedStrip which need an external power source on Vcc_ledstrip_pin.
//#define NEOPIXEL_LED                   //(n) Use port GPIO Wifi module (PC7)

        /* Option for other Probe (IR, Touch-Mi,.. ) or Sensorless (TMC2209_UART) */
// WARNING:These options need wiring pins DIAG to EndStop plug(Signal).
// more at the bottom page.
//#define STALLGUARD_1                   // (G) Special mod for TMC2209_UART = SENSORLESS_HOMING
//#define STALLGUARD_2                   // (g) Special mod for TMC2209_UART = SENSORLESS_PROBING

//For other PROBE fixed without deploy like IR, buzzer, Nozzle, ...
//#define P_PROBE                        // Uncomment to use a piezo probe like ORION.
                                         // and Set Y,Z OFFSET at zero
//#define X_PROBE                        // Uncomment and Set an other probe (invert the logic too).

//#define Y_OFFSET 0 //14.7              // Uncomment and set your own Y OffSet
//#define Z_OFFSET 0 //-2.5              // Uncomment and set your own Z OffSet

                  /* User settings Hotend */ 

// For user who change their nozzle thermistor and limited nozzle temp (ie. Volcano)
// by another one ex: "ATC Semitec 104GT-2" = 5 
//#define TEMP_SENSOR_0 13               // uncomment with a good number/type.

// For user who change their HotEnd like Volcano and
// want to increase the temperature limit. 
//#define HEATER_0_MAXTEMP 300

/*__________________________5_____________________________*/
      /** =============================
      * ======= MODE LEVELING==========
      * == type Calibration UBL =======
      * ===== 1 CHOICE for preheat ====
      * ===============================
      */

//#define DELTA_HOME_TO_SAFE_ZONE        // Option to move down after homing to a height where XYZ movement is unconstrained.

#define PREHEAT_BEFORE_PROBING           //(P) (Default) Run a PreHeat bed at 60°C only.
//#define PREHEAT_BEFORE_LEVELING        // Option to preheat (nozzle and bed) before levelling (H80/B60).

// ---Expe tools Levelling-------
//--------IF YOUR USED ABL, DISABLE "SPECIAL MENU DELTA"=> #define CUSTOM_MENU_MAIN
//#define AUTO_BED_LEVELING_BILINEAR     //(A)
#define AUTO_BED_LEVELING_UBL            //(U) (Default) Wizard UBL includes.

//#define SKEW_CORRECTION                // Add another dimension correction. 

/*_______________________6____________________*/
  //======Many options for Modules: ========//
#define LIN_ADVANCE                      // (L) (Default2209) with K=0 For TMC_UART2208 prefer mode spreadCycle(by TFT menu) or commented if problem.
#define POWER_LOSS_RECOVERY              // (Default) Continue print after Power-Loss.

//=================================================================================//
//======================== End_Hardware ===========================================//
//=================================================================================//

/*__________________________7__________________________*/
/** =====================================================
 *  ==== For users who dont have a terminal ============= 
 * = like (Prontoface/Octoprint/HostRepertier/Astoprint)=
 * ====== Choice add menu on TFT: (OPT) =================
 */
#define ADD_MENUS                        // (Default) Add menu PID, DELTA, INFO,...

/*__________________________8__________________________*/
/** ===================================================
* == Option for Host (OCTOPRINT,REPETIER,PRONTERFACE,ESP3D, etc)
* ======================================================
*/
#define HOST_ACTION_COMMANDS             // Default - Action Command Prompt support Message on Octoprint
#define BINARY_FILE_TRANSFER             // Bin transfert for ESP3D firmware v2.1 or others.
                                         // Not compatible with the MEATPACK option. 

//------ Support for MeatPack G-code compression (OCTOPRINT)--------//
//#define MEATPACK_ON_SERIAL_PORT_1      // (M) With connection USB
//#define MEATPACK_ON_SERIAL_PORT_2      // With other connection like Tx/Rx Wifi socket.

//----------Options Plus-----------//
//#define SDCARD_SORT_ALPHA
//#define SD_REPRINT_LAST_SELECTED_FILE // Reselect last print file.
#define SD_CHECK_AND_RETRY

//-----------------------------//
//For tests on my dev'printer!!//
//-----------------------------//
#else
 #include "Config_XP.h"  
#endif

/** ========================================
* == Options for Modules Hardware MKS_WIFI
* ==========================================
* Note:You must update the Wifi module with
* the ESP3D firmware or the MKS(Stock) firmware.
* https://github.com/Foxies-CSTL/Marlin_2.0.x/wiki/5.Firmware-Wifi
*/
#ifdef MOD_WIFI
  #define MOD_AUX                     // Enable UART2 on socket WIFI
  #ifdef ESP3D_30
    #define MKS_WIFI_MODULE           // Work with TFT_LVGL_UI(Modern UI using LVGL-MKS)
    #define USES_MKS_WIFI_FUNCTION    // Bin transfert MKS for ESP3D firmware v3.0 or others
  #endif
#endif

//= For users who dont have a terminal =//
#if BOTH(ADD_MENUS, TFT_CLASSIC_UI)||BOTH(ADD_MENUS, TFT_COLOR_UI)||BOTH(ADD_MENUS, TFT_BTT_UI)
  #define DELTA_CALIBRATION_MENU        //  (Default) Auto for CLASSIC and COLOR.
  #define PID_EDIT_MENU                 //  (Default) Tune PID Bed and Nozzle.
  #define PID_AUTOTUNE_MENU             //  (Default) Tune auto PID.
  #define LCD_INFO_MENU                 //  (Default) Informations printer.
  //#define PREHEAT_SHORTCUT_MENU_ITEM  // Add preheat/temperature menu (first page)
  //#define CANCEL_OBJECTS              // Add menu "Cancel Objet"
  #define TOUCH_IDLE_SLEEP 900          //  (Default) Auto-Sleep screenview.
  #ifndef STALLGUARD_2                   
  // Only with TMC2209 sensorless (need wiring DIAG pins)
    #define PROBE_OFFSET_WIZARD
    #define G26_MESH_VALIDATION         //  (Default) Command G26 to print a Mesh Validation Pattern tool.
    #define CUSTOM_MENU_MAIN            // ENABLE "SPECIAL MENU DELTA"
  #endif
  #ifdef NEOPIXEL_LED
    #define LED_CONTROL_MENU            // To control LedStrip.
  #endif
#endif

/**
 * =================================================
 * ===Part for Hardware definitions=================
 * ===Don't change if you're not sure how to do it.= 
 * =================================================
 */

//Type of Driver TFT Color (1 choice)
#ifdef TFT_DWIN_UI
  #define DGUS_LCD_UI_MKS           //Mks_H43_v1.0 (T5LCFG_800x480)
//Note for QQSP/Q5 DGUS/DWIN: The wiring is done on the UART2 (Wifi socket pins(PA10/PA9) for Tx/Rx).
  //#define DWIN_CREALITY_TOUCHLCD  // CREALITY/SuperRacer (T5LCFG_480x272)
  //#define DWIN_MARLINUI_PORTRAIT  // A DWIN display with Rotary Encoder (Ender-3 v2 OEM display).
  //#define LCD_SERIAL_PORT 1
#elif ENABLED(TFT_BTT_UI)
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER  //(r)(Default) UI Color FLSUN or BTT screen  
#elif ENABLED(TFT_GENERIC)
  #define TFT_DRIVER AUTO
  #define TFT_INTERFACE_FSMC        //Default socket on MKS_nano, mini, hispeed.
  #define TFT_RES_320x240
#else
  #define MKS_ROBIN_TFT32           // (Default) Mks_Robin_TFT_V2.0
  //#define MKS_TS35_V2_0           // Only for NanoV2 or V3
  //#define MKS_ROBIN_TFT35         // Mks_Robin_TFT35V2.0
  //#define MKS_ROBIN_TFT43         // Mks_Robin_TFT43 
  #define TOUCH_SCREEN              // (C/F) (Default) UI MARLIN
#endif

// Set for QQS(4xA4988) or Q5(3x2208+A4988) 
#if BOTH(STOCK, Q5)||BOTH(STOCK, QQSP)
  #ifdef Q5
    #define DRIVER_AXES TMC2208_STANDALONE
  #else
    #define DRIVER_AXES A4988
  #endif  
  #ifndef DRIVER_EXT
    #define DRIVER_EXT A4988
  #endif
#endif

// Set for TMC2208_STANDALONE
#ifdef ALL_TMC8
    #define Q_TMC
    #define DRIVER_AXES TMC2208_STANDALONE
    #ifndef DRIVER_EXT
      #undef LIN_ADVANCE
      #define DRIVER_EXT TMC2208_STANDALONE
    #endif
#endif
// Set for TMC2209_STANDALONE 
#ifdef ALL_TMC9
    #define Q_TMC
    #define DRIVER_AXES TMC2209_STANDALONE
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209_STANDALONE
    #endif
#endif

// Software Serial UART for TMC2208
#ifdef Q_UART8
    #define Q_TMC
    #define BOOT_MARLIN_LOGO_SMALL
    #define DRIVER_AXES TMC2208
    #ifndef DRIVER_EXT
      #undef LIN_ADVANCE
      #define DRIVER_EXT TMC2208
    #endif
#endif

// Software Serial UART for TMC2209
#if ANY(Q_UART9, SR_MKS, SR_BTT)
    #define Q_TMC
    #define BOOT_MARLIN_LOGO_SMALL
    #define STEALTHCHOP_E
    #define DRIVER_AXES TMC2209
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif
//Add definition for UART for Q5
#if BOTH(Q5, Q_UART8)||BOTH(Q5, Q_UART9)
    #define X_SERIAL_TX_PIN             PA10  // RXD1
    #define X_SERIAL_RX_PIN             PA10  // RXD1
    #define Y_SERIAL_TX_PIN             PA9   // TXD1
    #define Y_SERIAL_RX_PIN             PA9   // TXD1
    #define Z_SERIAL_TX_PIN             PC7   // IO1
    #define Z_SERIAL_RX_PIN             PC7   // IO1
    #define E0_SERIAL_TX_PIN            PC13  // IO0
    #define E0_SERIAL_RX_PIN            PC13  // IO0
    #define TMC_BAUD_RATE               19200
#endif

/**---------------------------//
 * Special mods TMC2209:      //
 *                            //
 * UART: Single wire          //
 * SENSORLESS: Homing/Probing //
 * ---------------------------//
 */

// Note:
// HardwareSerial with one pins for four drivers
// Compatible with TMC2209. Provides best performance.
// Requires SLAVE_ADDRESS definitions in Configuration_adv.h
// and proper jumper configuration. Uses I/O pins PA8(Default QQS).
#ifdef QQS_UARTH
    #define Q_TMC
    #define BOOT_MARLIN_LOGO_SMALL
    #define TMC_HARDWARE_SERIAL
    #define STEALTHCHOP_E
    #define DRIVER_AXES TMC2209
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif

// Note:
// Need wiring pins DIAG to EndSTOP(Signal).

// Use the function Stallguard1 for homing without endstop
// (Need to adjust the sensitivity).
// SENSORLESS_HOMING             
#ifdef STALLGUARD_1
  #define SENSORLESS_HOMING
#endif
// Use the function StallGuard2 for probing with the nozzle.
// SENSORLESS_PROBING
#ifdef STALLGUARD_2
  #define N_PROBE
  #define Y_OFFSET 0
  #define Z_OFFSET 0
#endif

//===================PART CONSTANTS VARIALBES ===================//

// Variables to calculate steps and current
//eSteps
#ifndef EXTRUDER_STEPS
  #ifdef NEMA14
    #define EXTRUDER_STEPS 720  // Extruder SuperHX, Mini-Sherpa, Orbiter, LGX_Lite
  #elif ANY(BMG, SR_MKS, SR_BTT)
    #define EXTRUDER_STEPS 409  // Extruder BMG(Left/Right)
  #elif ENABLED(OMG)           
    #define EXTRUDER_STEPS 390
  #else
    #define EXTRUDER_STEPS 410  // Extruder TITAN(Default)
  #endif
#endif
//Jerk
#ifndef XYZJERK
  #define XYZJERK  10.0
#endif
#ifndef EJERK
  #ifdef NEMA14
    #define EJERK       5.0
  #else
    #define EJERK       10.0
  #endif
#endif
//Z_OffSet
#ifndef Z_OFFSET
  #ifndef Q5
    #define Y_OFFSET        0
    #define Z_OFFSET       -16.2
  #else
    #define Y_OFFSET        0
    #define Z_OFFSET       -18
  #endif
#endif
// TMC Current in UART mode
#ifndef XYZ_CURRENT
  #define XYZ_CURRENT       900
#endif
#ifndef XYZ_CURRENT_HOME
  #define XYZ_CURRENT_HOME  600
#endif  
#ifndef E_CURRENT
  #ifdef NEMA14
    #define E_CURRENT       380
  #else
    #define E_CURRENT       850
  #endif
#endif
