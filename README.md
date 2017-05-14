# Air quality analyzer


### Overview
***

**Air quality analyzer** is an electronic based portable device made in order to measure the air quality. This portable device can detect air quality at any place. Specially places where we cannot obtain the air quality data which is obtained using weather stations. Even though, the air quality is measured outdoors using weather stations, people don’t care about the air quality indoors. Most people think that staying indoors is very suitable when there is air pollution outside. But there is a number of harmful gases present even indoors. The air quality data obtained is sent to a website and then saved for analysis. Several gas sensors are used in this device to detect the different kinds of harmful gases present in the atmosphere. The main feature of this device is the cost effectiveness when compared with the other detectors currently available in the market.



### ArduinoCode
***
*Air_pollution_monitor.ino* is the main part of this project. There are two main functions in our machine:
* Real-time monitoring 
* Sending data to server



### ExternalLib
***
This folder contains Libs that Air_pollution_monitor.ino needs. The folder includes are as follows:
* dht.h
* ESP8266.h
* LiquidCrystal_I2C



### WiFiLib
***
This folder contains our own library which is based on ESP8266.h. This Lib makes it much easier to transfer data by simply adjusting your own SSID, PASSWORD and URL.



### Web
***
This folder contains codes on the server.
* *get_data.php* receives data from Arduino, then make a new file contains different aspects of data. It also maintains a *list.txt* which contains data's file name.
* *airquility.html* sends request to *send_data.php*, then show the latest air condition.
* *ShowData.sh* shows all of the data the server got with the name of each field.
* *refreshlist.sh* is used for refresh *list.txt* after you delete some data files.


***

### Contact Us
***
If you have any suggestions, please contact us.
* Mr.K  [1061494593@qq.com](mailto:1061494593@qq.com) Arduino part, WiFiLib, Back-end developer
* Lakshantha Dissanayake [lakshanthad@yahoo.com](mailto:lakshanthad@yahoo.com) Arduino
* 风之笑 [bh1517zhr@163.com](mailto:bh1517zhr@163.com) Front-end developer
