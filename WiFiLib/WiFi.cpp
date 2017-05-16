/**
 * @file WiFi.cpp
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
#include "WiFi.h"
SoftwareSerial mySerial(2,3);//some Core must use software serial to 
                             //communicate with Wi-Fi model
                             //mySerial(argument1,argument2),arg1,arg2 are PIN number
ESP8266 wifi(mySerial);

void init_ESP8266()
{
  if (wifi.setOprToStationSoftAP()) 
   {
    #ifdef _DEBUG_
    Serial.print("to station + softap ok\r\n");
    #endif
   }
  else 
   {
    #ifdef _DEBUG_
    Serial.print("to station + softap err\r\n");
    #endif
   }

  if (wifi.joinAP(SSID, PASSWORD))//Join AP
  {      
    #ifdef _DEBUG_
    Serial.print("Join AP success\r\n");  
    Serial.print("IP: ");
    Serial.println(wifi.getLocalIP().c_str());
    #endif
  } 
  else 
   {
    #ifdef _DEBUG_
    Serial.print("Join AP failure\r\n");
    #endif
   }

  if (wifi.disableMUX()) 
    {
      #ifdef _DEBUG_
      Serial.print("single ok\r\n");
      #endif
    }
  else 
    {
      #ifdef _DEBUG_
      Serial.print("single err\r\n");
      #endif
    }    
  #ifdef _DEBUG_
  Serial.print("setup end\r\n");
  #endif
}



String updateSensorData(float *Array, int ArrayLength,String postUrl/*="/Mr.K/get_data.php?0="*/)
{
  if(wifi.createTCP(HOST_NAME,HOST_PORT))//create tcp, if fail, don't send data
  {
    String postString;
    #ifdef _DEBUG_
    Serial.print("create tcp ok \r\n");
    #endif
    postString="GET ";
    postString += postUrl;
    char tempc[15]={0};
    dtostrf(Array[0],1,4,tempc);
    postString+=tempc;
    for(int i=1;i<ArrayLength;++i)
    {
      postString=postString+"&";//+(i+'0')+"=";
      postString+=i;
      postString+="=";
      char tempa[15]={0};
      dtostrf(Array[i],1,4,tempa);
      postString+=tempa;
    }
    
    postString+=" HTTP/1.0\r\n\r\n";
    const char *postArray=postString.c_str();
    wifi.send((const uint8_t*)postArray, strlen(postArray));  
    #ifdef _DEBUG_
    Serial.println(postArray);
    Serial.println("send success");   
    #endif 

    
    String dataGetFromServer="";
    int counter=0;
    while(mySerial.available()>0)
    {
      
      ++counter;
      String data="";
      if(counter==11)
        {
          dataGetFromServer=mySerial.readStringUntil('\n');
          #ifdef _DEBUG_
          Serial.print(counter);
          Serial.println(dataGetFromServer);
          #else
          delay(3);
          #endif
          
        }
      else
        {
          data=mySerial.readStringUntil('\n');
          #ifdef _DEBUG_
          Serial.print(counter);
          Serial.println(data);
          #else
          delay(3);
          #endif
        }
    }
    #ifdef _DEBUG_
    Serial.print("Final data get from server is :");
    Serial.println(dataGetFromServer);
    #endif

    
    if (wifi.releaseTCP())  
      {                                
        #ifdef _DEBUG_
        Serial.print("release tcp ok\r\n");
        #endif
      }
    else 
      {
        #ifdef _DEBUG_
        Serial.print("release tcp err\r\n");
        #endif
      }
        
     postArray = NULL;                                       //release
    return dataGetFromServer;
  }
  else 
   {
    #ifdef _DEBUG_
    Serial.print("create tcp err\r\n");
    #endif
   }
 }

