# RPIPicoWTelegram
Telegram Bot API Example from a Raspberry Pi Pico W in C/C++

This is an example for a Video on my [YoUTube Channel DrJonEA](https://youtube.com/@drjonea)

The Example will check for messages on telegram every 10 seconds and respond to some commands.
+ /test
+ /temp


## Telegram Bot Creation
Using the Telegram @BotFather to create a Bot ID

@BotFather
/newbot

## Variables needed for Build
The following Environmental variables are used to give sensitive data to the build process
+ WIFI_SSID - SSID of your WIFI
+ WIFI_PASSWORD - Password to connect to wifi
+ TELEGRAMBOTKEY - The Telegram Boy Key provided from BotFather
+ TELEGRAMBOTAUTH - The ID of a user who is authorised to use the BOT. This is hard to get, so needs some playing with the API to capture this

## Clone and Build
Repo uses submodules with submodules.

Clone and pull submodules with the commands:
```
git clone https://github.com/jondurrant/RPIPicoWTelegram
git submodule update --init --recursive
```

Build using normal Pico SDK Build process
```
mkdir build
cd build
cmake ..
make
```
Binary will be "build/src/TelegramBot.elf" or "build.srcTelegramBot.uf2"




