<p align="center"></p>

<h1 align="center">
<img width="240" src="doc/SEPSlogo.png">
  <br>
  Smart Eco-Plant System
  <br>
  <a href="3"><img src="https://img.shields.io/github/contributors/Haitem7Bahri/SmartEcoPlantSystem" alt="Contributors"></a>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/issues"><img src="https://img.shields.io/github/issues/Haitem7Bahri/SmartEcoPlantSystem" alt="GitHub Issues"></a>
  <a href="https://github.com/Haitem7Bahri/SmartEcoPlantSystem/pulls"><img src="https://img.shields.io/github/issues-pr/Haitem7Bahri/SmartEcoPlantSystem" alt="GitHub Pull Requests"></a>
  <a href="https://www.gnu.org/licenses/"><img src="https://img.shields.io/github/license/Haitem7Bahri/SmartEcoPlantSystem" alt="License"></a>
  <br>
</h1> 


# Follow us
  <a href="https://www.youtube.com/channel/UCa6wbjpejbbG89zu2GJMtjQ/featured"><img width="52" hspace="5" src="doc/youtube.png"></img></a>
  <a href="https://twitter.com/SmartEcoPlantSy"><img width="34" hspace="5" src="doc/twitter.png"></img></a>


# Contributors
* Haitem Bahri (https://github.com/Haitem7Bahri)
* Tao Xu (https://github.com/TaoXu-Git) 
* Khanisorn Chayangsu (https://github.com/windthestorm)


# Introduction

Smart Eco-Plant system is an intelligent system to help plants grow better by monitoring the environmental parameters the affect growth and manipulate these parameters using actuators to achieve the best atmosphere for the plants to grow better.<br>
<br>
<h1 align="center">
<img width="500" src="doc/system.jpg"></img>
<img width="500" src="doc/1.jpg"></img>
<img width="500" src="doc/2.jpg"></img>

> SmartEcoPlantSystem <br>


# Structure diagram

<img width="900" src="doc/structure.png"></img>
<br>
Brief processflow shown below: 
<br>
<h1 align="center">
<img width="500" src="doc/processflow3.png"></img>

# Wiring diagram

<h1 align="center">
<img width="600" src="doc/wiring.png"></img>


# Components
Smart Eco-Plant System consists of sensor part and actual part. Multiple sensors are in charge of collecting and transmitting the environment parameters. Actuators are applied for adjusting the environment factors to make enviroment suitable for the growth of the required plant. Description for each sensor and actuators is attached. Meanwhile, some important relevant supporting components are also attached. <br>

### Sensors

* Temperature Sensor: `KY-013`<br>
[Link](https://www.amazon.com/KY-013-Analog-Temperature-Sensor-arduino/dp/B07P87M5GW)
<br>

* Soil Moisture Sensor: `SEN-13637`<br>
[Link](https://www.amazon.co.uk/gp/product/B07V6SZYZW/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)
<br>

### Actuators

* Ventilating System: <br>
[Link](https://www.aliexpress.com/item/32855526132.html?albpd=en32855526132&acnt=494-037-6276&aff_platform=aaf&albpg=539263010115&netw=u&albcp=12555209680&pvid=0c99d98e-a417-47d7-a73f-18b41ae4b118&sk=UneMJZVf&scm=1007.23534.124000.0&trgt=539263010115&terminal_id=605da29c290e442d983f3966a9b395c6&needSmbHouyi=false&albbt=Google_7_shopping&src=google&crea=en32855526132&aff_fcid=2211ca5653d3499e80905691564f9f3f-1618792871671-04778-UneMJZVf&gclid=Cj0KCQjwse-DBhC7ARIsAI8YcWKmyHHRcOQm58pDKarFQjtV9aFBtE-vJXvx_3LW_xfRjtH_jiBkoaQaAnTYEALw_wcB&albag=122168291729&aff_fsk=UneMJZVf&albch=shopping&albagn=888888&isSmbAutoCall=false&aff_trace_key=2211ca5653d3499e80905691564f9f3f-1618792871671-04778-UneMJZVf&rmsg=do_not_replacement&device=c&gclsrc=aw.ds)

* Watering System <br>
[Link](https://www.amazon.co.uk/gp/product/B07M8VV4FW/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1)


### Supporting Components

* Microchip `mcp3008`

# Getting Started

1. Make a clone of the repository on your raspberry pi:

`git clone https://github.com/Haitem7Bahri/SmartEcoPlantSystem`

2. Navigate to the repository folder and create build folder:

`mkdir build`

3. Navigate to build folder:

`cd build`

4. Run Cmake from build folder:

`cmake ..`

5. Run Make:

`make`

6. Run Program:

`./SmartEcoPlantSystem`

# License 

This is a free software that can be modified and redistributed under the GPL-30 license.
No warranty is provided with this software, use it at your own responsibility, check the GPL license documentation (LICENSE.md) for more details.

