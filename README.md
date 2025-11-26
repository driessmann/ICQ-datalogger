# ESP32 Environmental Monitoring Project

This repository contains all code and documentation for a project developed for the Python Programming course in the 1ELA Bachelor program at VIVES Technology.

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

---
