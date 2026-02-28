/* 
Copyright 2023 NEO

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//C:\Users\lizhe\qmk_firmware\keyboards\owlab\voice65\hotswap\config.h
//C:\Users\lizhe\qmk_firmware\keyboards\cannonkeys\satisfaction75\config.h
//C:\Users\lizhe\qmk_firmware\keyboards\durgod\dgk6x\config.h
//C:\Users\lizhe\qmk_firmware\keyboards\mechlovin\adelais\rgb_led\rev3\config.h


/* RGB matrix */
#ifdef RGB_MATRIX_ENABLE
// i2c setting


/*
I2Cv2 使用I2CV2的芯片
STM32F0xx
STM32F3xx
STM32F7xx
STM32L4xx

config.h Overrride    Description    Default默认值  I2C1或者2在mcuconf.h中定义，默认是I2C1
I2C_DRIVER    I2C peripheral to use - I2C1 -> I2CD1, I2C2 -> I2CD2 etc.    I2CD1
I2C1_SCL_PIN    The pin definition for SCL    B6
I2C1_SCL_PAL_MODE    The alternate function mode for SCL    4
I2C1_SDA_PIN    The pin definition for SDA    B7
I2C1_SDA_PAL_MODE    The alternate function mode for SDA    4
*/

// #define I2C_DRIVER I2CD1
// #define I2C1_SCL_PIN B6
// #define I2C1_SDA_PIN B7
// #define I2C1_SCL_PAL_MODE 4
// #define I2C1_SDA_PAL_MODE 4

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1
#define I2C1_TIMINGR_PRESC 0x00U
#define I2C1_TIMINGR_SCLDEL 0x03U
#define I2C1_TIMINGR_SDADEL 0x01U
#define I2C1_TIMINGR_SCLH 0x03U
#define I2C1_TIMINGR_SCLL 0x09U


/* 
I2Cv2 configuration structure.

config.h Override    Default
I2C1_TIMINGR_PRESC    0U
I2C1_TIMINGR_SCLDEL    7U
I2C1_TIMINGR_SDADEL    0U
I2C1_TIMINGR_SCLH    38U
I2C1_TIMINGR_SCLL    129U
 */
// #define I2C1_TIMINGR_PRESC   0U
// #define I2C1_TIMINGR_SCLDEL  7U
// #define I2C1_TIMINGR_SDADEL  0U
// #define I2C1_TIMINGR_SCLH   38U
// #define I2C1_TIMINGR_SCLL   129U



// #    define RGB_MATRIX_DISABLE_KEYCODES //禁用默认的RGB_TOGGLE等键值来控制RGB矩阵，而使用其他键和代码来控制
#    define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#    define RGB_MATRIX_KEYPRESSES           // reacts to keypresses
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_LED_PROCESS_LIMIT  4
#    define RGB_MATRIX_LED_FLUSH_LIMIT    26
// #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#    define RGB_MATRIX_STARTUP_VAL        64
#    define DRIVER_ADDR_1                 0b0110000
//   #define DRIVER_ADDR_2 0b1010011
#    define DRIVER_COUNT                  1  //2
#    define RGB_MATRIX_LED_COUNT          68   //DRIVER_LED_TOTAL              //RGB_MATRIX_LED_COUNT 

// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
// djc: neo defaults above.  my own stuff below
// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
#    define DEBOUNCE_TYPE sym_eager_pk
#    define DEBOUNCE 5
/* rgb settings */
#    define RGB_MATRIX_DEFAULT_ON true
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_VAL
#    define RGB_MATRIX_DEFAULT_HUE 170
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 255
#    define RGB_MATRIX_DEFAULT_SPD 70
/* force enable NKRO */
#    define FORCE_NKRO

/* increase layer count above the default of 5 */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 16

/* include layers that are not used on all keyboards */
#    define CONFIG_HAS_FKEY_LAYR

/* tap time for tap dancing */
#    define TAPPING_TERM 250

/* enable caps word when both shift keys are tapped */
#    define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* do not allow dynamic macros to nest (can cause infinite loop) */
#    define DYNAMIC_MACRO_NO_NESTING

/* allow setting constant mode mouse cursor and wheel speeds */
#    define MK_3_SPEED
#    define MK_C_OFFSET_0 1
#    define MK_C_INTERVAL_0 6
#    define MK_C_OFFSET_1 4
#    define MK_C_INTERVAL_1 8

/* leader key settings */
#    define LEADER_TIMEOUT 250
#    define LEADER_PER_KEY_TIMING
#    define LEADER_NO_TIMEOUT

/* for tmux send_string delays */
#    define TMUX_DELAY 25
#    define CONFIG_VS_LAYR_SEND_STRING_DELAY 35

/* monitored base layers for macos */
#    define CONFIG_MACOS_BASE_LAYERS { MAC_BASE }
#    define CONFIG_MACOS_BASE_LAYERS_COUNT 1
#    define CONFIG_DEFAULT_MAC_LAYR MAC_BASE
#    define CONFIG_DEFAULT_WIN_LAYR WIN_BASE

/* monitored base layers */
#    define CONFIG_ALL_BASE_LAYERS { MAC_BASE, WIN_BASE }
#    define CONFIG_ALL_BASE_LAYERS_COUNT 2
/* key indexes that changed to shifted version when caps is used */
#    define CONFIG_CAPSLOCK_SHIFTED ((i > 16 && i < 27) || (i > 31 && i < 41) || (i > 45 && i < 53))
#    define CONFIG_CAPSWORD_EXTRA (i == 11)

/* keyfade settings */
#    define CONFIG_KEYFADE_START_DELAY 16
#    define CONFIG_KEYFADE_START_VAL 250
#    define CONFIG_KEYFADE_CALLBACK_INTERVAL 15

/* rgb_matrix_indicators_advanced_user settings */
#    define CONFIG_HAS_LLOCK_KEY
#    define CONFIG_HAS_KLOCK_KEY
#    define CONFIG_BLINK_LAYR_EVEN_WITH_KEYCODE_ASSIGNED
#    define CONFIG_KEY_INDEX_MAX 67

// single indicator config
#    define CONFIG_RGB_LAYER_INDICATORS { I_INDICATOR }
#    define CONFIG_RGB_LAYER_INDICATORS_COUNT 1

// more indicator settings
#    define CONFIG_FLASH_CAPS_ON_ALL_LAYERS
#    define CONFIG_LOCKED_LAYERS_STOP_FLASHING
#    define CONFIG_FN_LAYR_COLOR RGB_GREEN
#    define CONFIG_MREC_KEY_COLOR RGB_MAGENTA
#    define CONFIG_SHIFT_LAYR_COLOR RGB_ORANGE
#    define CONFIG_KCTL_LAYR_COLOR RGB_RED
#    define CONFIG_TMUX_LAYR_COLOR RGB_CYAN
#    define CONFIG_VS_LAYR_COLOR RGB_PURPLE
#    define CONFIG_SYM_LAYR_COLOR RGB_BLUE
#    define CONFIG_WIDE_LAYR_COLOR RGB_TURQUOISE
#    define CONFIG_CIRC_LAYR_COLOR RGB_CORAL
#    define CONFIG_EMO_LAYR_COLOR RGB_PURPLE
#    define CONFIG_FKEY_LAYR_COLOR 0x90,0x90,0x90
#    define CONFIG_DEFUALT_LAYR_COLOR 0x77,0x77,0x77
#    define CONFIG_EXTRA_BASE_LAYR_COLORS \
     { \
         { I_CAPS, RGB_BLUE }, \
         { I_TAB, 0x77,0x77,0x77 }, \
         { I_BSLS, 0x77,0x77,0x77 }, \
         { I_FKEY, 0x77,0x77,0x77 }, \
     }
#    define CONFIG_EXTRA_BASE_LAYR_COLORS_COUNT 4
#    define CONFIG_ACCENT_KEY_COLOR RGB_YELLOW
#    define CONFIG_CAPS_WORD_SHIFT_COLOR 0x77,0x77,0x77
#    define CONFIG_HROWLIGHT_COLOR RGB_GREEN
#    define CONFIG_FJLIGHT_COLOR RGB_WHITE
#    define CONFIG_LEADER_COLORA RGB_TURQUOISE
#    define CONFIG_LEADER_COLORB RGB_CYAN
#    define CONFIG_KEYLIGHT_STD_COLOR RGB_WHITE
#    define CONFIG_EEPROM_RESET_DEFAULT_LAYER MAC_BASE
#    define CONFIG_LOCK_ANIMATION_TIMEOUT 120000
#    define CONFIG_LOCK_RESTORE_ANIMATION_FROM_SUSPEND_MS 50
#    define CONFIG_LOCK_ANIMATION_COLOR_HSV HSV_RED
#    define CONFIG_LOCK_LAYR_EXTRA_FLASH_KEYS { I_LLOCK }
#    define CONFIG_LOCK_LAYR_EXTRA_FLASH_KEYS_COUNT 1

#endif

/* custom sleep setup */
#    define CONFIG_CUSTOM_SLEEP_TIMEOUT 540000
#    define CONFIG_CUSTOM_SLEEP_WARNING 5000
#    define CONFIG_CUSTOM_BLINK_INTERVAL 250

/* this is for the process_key_sequence (good over rdp connections) */
// larger queues use much more sram
#    define CONFIG_MAX_SEQ_QUEUE 2
#    define CONFIG_MAX_KEYS_HELD 5
