<p align="center"></p>

<h1 align="center">
<img width="240" src="doc/SEPSlogo.png">
  <br>
  Smart Eco-Plant System
  <br>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/issues"><img src="https://img.shields.io/github/issues/Haitem7Bahri/SmartEcoPlantSystem" alt="GitHub Issues"></a>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/pulls"><img src="https://img.shields.io/github/issues-pr/Haitem7Bahri/SmartEcoPlantSystem" alt="GitHub Pull Requests"></a>
  <a href="https://www.gnu.org/licenses/"><img src="https://img.shields.io/github/license/Haitem7Bahri/SmartEcoPlantSystem" alt="License"></a>
  <br>
  _______________________________________________
  <br>
  
  <br>
  <a href="https://www.youtube.com/channel/UCa6wbjpejbbG89zu2GJMtjQ/featured"><img width="52" hspace="5" src="doc/youtube.png"></img></a>
  <a href="https://twitter.com/SmartEcoPlantSy"><img width="34" hspace="5" src="doc/twitter.png"></img></a>
</h1> 

# Contributors
* Haitem Bahri (https://github.com/Haitem7Bahri)
* Tao Xu (https://github.com/TaoXu-Git) 
* Khanisorn Chayangsu (https://github.com/windthestorm)

# SmartEcoPlantSystem

Smart Eco-Plant system is an intelligent system to help plants grow better by monitoring the environmental parameters the affect growth and manipulate these parameters using actuators to achieve the best atmosphere for the plants to grow better.<br>
<br>
> Brief processflow shown below: <br>

<h1 align="center">
<img width="500" src="doc/processflow.png"></img>

## Components
Smart Eco-Plant System consists of sensor part and actual part. Multiple sensors are in charge of collecting and transmitting the environment parameters. Actuators are applied for adjusting the environment factors to make enviroment suitable for the growth of the required plant. Description for each sensor and actuators is attached. Meanwhile, some important relevant supporting components are also attached. <br>

### Sensors

* Temperature and Humidity Sensor: `DHT22`<br>
  Details in("https://www.ebay.co.uk/itm/DHT22-Digital-Temperature-Humidity-Sensor-AM2302-Module-with-Cable-UK-Seller/313229638949?hash=item48edf0fd25:g:LUEAAOSwuI9gNV7l
") <br>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/tree/main/tests/Temperature%26HumiditySensorTest"><img width="100" hspace="10" src="doc/DHT22_pins.png"></img></a>
* Soil Moisture Sensor: `SEN-13637` <br>
  Details in(https://shop.pimoroni.com/products/sparkfun-soil-moisture-sensor-with-screw-terminals?variant=44592089802&currency=GBP&utm_source=google&utm_medium=cpc&utm_campaign=google+shopping?utm_source=google&utm_medium=surfaces&utm_campaign=shopping&gclid=CjwKCAiAsaOBBhA4EiwAo0_AnIjHytEniALD-TOS6k2NqEpCS4KuGEE_8D-EFHC_6jrr_HvHVhYRqxoC6g8QAvD_BwE#show-reviews) <br>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/tree/main/tests/moistureSensorTest"><img width="100" hspace="10" src="doc/SEN-13637.png"></img></a>
* Carbondioxide Sensor: `JX-CO2-102`<br>
  Details in(https://item.taobao.com/item.htm?spm=a1z09.2.0.0.12072e8dvhnyjR&id=596444927085&_u=22mnc56fba15) <br>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/tree/main/tests/CarbonDioxideSensorTest"><img width="100" hspace="10" src="doc/JX-CO2-102.png"></img></a>

### Actuators

* Watering System

* Ventilating System

### Supporting Components

* Microchip `mcp3008`

## Software
In the project, we use SPI interface to transmit data from sensors to Raspberry Pi. However, the sensors we use are not all support SPI interface. The microchip mcp3008 is applied for unifying the interface which would significantly increasing our coding effiency. For example, the Carbondioxide Sensor uses UART. The support to UART on raspberry pi is really bad but the support to SPI is good.<br>

### How to use UART
It is the latest product of the JingXunChangTong whose customers are the hecienda owners. Therefore, it is relatively cheap and tough while accuracy being still acceptable.
We also provide the carbondioxide sensor's code for UART interface on Raspberry Pi 4b for those who don't want to purchase the mcp3008.<br>
In order to transmit the data, we must enable the UART(not the ubstable miniuart) first.<br>
Open the miniuart via `sudo raspi-config` then `reboot` <br>
Change the default UART serial port via add `dtoverlay=pi3-disable-bt ` to `sudo vi /boot/config.txt` <br>
Then check `ls -l /dev/seri*` <br>
The bluetooth would be closed if we enable the UART, so think twice. <br>

### How to use mcp3008
<img width="200" src="doc/mcp3008.png"></img> <br>



## Instruction



## Credits


...
