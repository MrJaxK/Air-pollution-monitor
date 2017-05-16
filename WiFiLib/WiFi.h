/**
 * @file WiFi.h
 * @author Mr.K <1061494593@qq.com>
 * @date 2017
 *
 *MIT License
 *
 *Copyright (c) 2017 Mr.K
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the ""), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 */
#ifndef WIFI_PART
#define WIFI_PART

#include "../ExternalLib/ESP8266.h"
#include <SoftwareSerial.h>


#define esp8266Serial mySerial

//#define SSID "AndroidAP"
//#define PASSWORD "ogbq1848"
#define SSID "mmp"
#define PASSWORD "13141314"
#define HOST_NAME "139.199.118.226"
#define HOST_PORT 80
// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2

#define _DEBUG_  //debug settings and show status by Serial

void init_ESP8266();
String updateSensorData(float *Array,int ArrayLength,String postUrl="/Mr.K/get_data.php?0=");
#endif
