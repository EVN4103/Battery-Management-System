# 15V Battery Management System (BMS)

## Overview
This project is a 15V Battery Management System (BMS) based on ATmega328P. 
It provides real-time voltage and current monitoring along with protection 
against over-voltage, under-voltage, and over-current conditions. 
The system supports I2C and UART communication for external monitoring and integration.

## Features
- Real-time voltage monitoring
- Current sensing
- Over-voltage protection
- Under-voltage protection
- Over-current protection
- I2C communication interface
- UART communication interface

## Hardware
- Microcontroller: ATmega328P
- Battery Voltage: 15V
- Communication: I2C / UART

## Repository Structure
- /hardware → Schematic, PCB layout, Gerbers, BOM
- /firmware → ATmega328P firmware

## PCB Preview
![PCB](hardware/pcb/BMS_15V_PCB_Layout.png)