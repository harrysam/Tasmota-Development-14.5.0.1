/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*


// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4618                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "Fritz7590ax"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "37810962054745881554"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "192.168.188.123" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1884                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "harry.sam"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "70227022"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     192.168.188.170                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        192.1689.188.1                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            192.168.188.1               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           8.8.8.8              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif





#undef MY_LANGUAGE
#define MY_LANGUAGE            de_DE           // German in Germany


#define lib libesp32_audio

// Select none or only one of the below defines USE_RULES or USE_SCRIPT
//Cam
#define USE_WEBCAM
#undef USE_RULES                              // Add support for rules (+8k code)
#undef USE_SDCARD
#define USE_SDCARD

#define USE_SCRIPT_FATFS_EXT

#define USE_SCRIPT                            // Add support for script (+17k code)

// UFS filesystem
#define UFSYS_SIZE 8192

//#define USE_UFILESYS
//#define GUI_TRASH_FILE

//#ifndef USE_UFILESYS
//#define USE_UFILESYS
//#endif
                     
//#ifndef USE_FEXTRACT
//#define USE_FEXTRACT                      // enables array extraction from database fxt(...)
//#endif


#define USE_SCRIPT_WEB_DISPLAY
#define USE_SCRIPT_JSON_EXPORT
#define USE_ESP32MAIL
#define EMAIL_USER "stuelcken54@web.de"
#define EMAIL_PASSWORD "!Marv2024in"
#define EMAIL_FROM "stuelcken54@web.de"
#define EMAIL_SERVER "smtp.web.de"
#define EMAIL_PORT 587

#define USE_SPI

//Cam Audio
#define MP3_MIC_STREAM
#define USE_I2S_MIC
#define USE_SHINE
//#define USE_I2S_AUDIO
#define MICSRATE 32000
#define MIC_CHANNELS 1

#define USE_LIGHT

// -- Time - Up to three NTP servers in your region
#undef NTP_SERVER3
#define NTP_SERVER3      "2.de.pool.ntp.org"     // [NtpServer3] Select third NTP server by name or IP address (46.249.42.13, 2603:c022:c003:c900::4)

// -- Location ------------------------------------
#undef LATITUDE
#define LATITUDE 53.9883 // [Latitude] Your location to be used with sunrise and sunset
#undef LONGITUDE
#define LONGITUDE 9.8686 // [Longitude] Your location to be used with sunrise and sunset


#ifdef APP_TIMEZONE
#undef APP_TIMEZONE
#define APP_TIMEZONE 99
#endif



#endif  // _USER_CONFIG_OVERRIDE_H_




