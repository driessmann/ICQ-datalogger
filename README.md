# python climate Monitoring Project

This repository contains all code and documentation for a project developed for my Python Programming course in the 1ELA Bachelor program at VIVES Technology.

The project uses an ESP32-WROOM to read environmental data from a BME680 sensor (via I²C) and an LDR. 

## Collected data

- room light brightness level
- temperature
- humidity
- air pressure
- IAQ (indoor air quality)

These real-time readings are shown on an e-paper display
These data variables can be collected to form an Indoor Climate Quality (ICQ) value.

The python part of this project comes in to play with a raspberry pi running an mqtt broker. All of the measured data will be published to this MQTT broker.

A Python script on the Raspberry Pi subscribes to the MQTT topics, stores the incoming data and generates real-time graphs using Matplotlib.

## Hardware specs

- AZ-Delivery esp32 Dev kit C
- BME680 breakout board
- AZ-Ddelivery LDR KY-018 breakout
- 2.9 inch e-paper display (ZHONGJINGYUAN ZJYE290S08R0G01 [manufaturer data](https://www.alibaba.com/product-detail/2-9-inch-electronic-paper-display_1600542691082.html?spm=a2700.shop_pl.41413.8.42f67121U3EHvZ)
- Raspberry pi 3B+