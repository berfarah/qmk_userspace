# Basics
BOOTLOADER = atmel-dfu
LTO_ENABLE = yes            # Reduces FW size
NKRO_ENABLE = no            # N-Key Rollover, allows for keys to be pressed simultaneously

# Features
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes        # Audio control and System control

# Peripherals
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
ENCODER_ENABLE = yes
OLED_ENABLE = yes           # OLED display
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.

# Debug
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug

# Niche features
AUDIO_ENABLE = no           # Audio output
MOUSEKEY_ENABLE = no        # Mouse keys
OS_DETECTION_ENABLE = yes   # https://docs.qmk.fm/features/os_detection
SWAP_HANDS_ENABLE = no      # Enable one-hand typing

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
