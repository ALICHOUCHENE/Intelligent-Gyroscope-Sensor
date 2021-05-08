# Intelligent-Gyroscope-Sensor

Intelligent gyroscope sensor for Electronic stability control

Recognizing how a vehicle is steered and then alerting drivers in real time is of utmost importance to the vehicle and driver’s safety, since fatal accidents are often caused by dangerous vehicle maneuvers, such as rapid turns, fast lane-changes, etc.
In this paper, we make use of an intelligent sensor to take one step forward by developing a real-time accurate recognition system for dangerous vehicle steering maneuvers without the driver’s involvement. 
The basic idea is to use the sensor data to capture differences in the vehicle’s angular speed due to vehicle steering maneuvers, including turns, lane-changes and U-turns. 

   
   
 
 **Here the features of the Sensor :**

- STM32F103C8T6 ARM 32-bit Cortex™-M3 is the CPU of the board. Higher frequency, higher speed and cost-effictive.

- Gyroscope module, MPU6050, with I2C communication protocol. 

- CAN transeiver SN65HVD230

- SWD programming Interface.

- SPI for serial communication.

- USART for AT-commands mode in order to test the sensor before embedded it in the CAN bus.

- Voltage regulator with reverse voltage protection circuit.


**The schematic of the board :**

![alt text](https://github.com/ALICHOUCHENE/Intelligent-Gyroscope-Sensor/blob/main/Schematics/Schematics.PNG)



**The PCB layout of the board :**


![alt text](https://github.com/ALICHOUCHENE/Intelligent-Gyroscope-Sensor/blob/main/PCB/PCB.PNG)


**Board View :**


![alt text](https://github.com/ALICHOUCHENE/Intelligent-Gyroscope-Sensor/blob/main/PCB/3D.PNG)




# Manufacturing : 


After finishing the Routing and verifying the pcb. We will make the board at JLC PCB and we chose also the PCB Assembly service.
Here is the BOM and posistion file needed to order from JLC PCB :


**BOM :**



| Designator | Value         | Footprint                                                 | LCSC Part |
|------------|---------------|-----------------------------------------------------------|-----------|
| C1         | 100nF         | Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder | C49678    |
| C2         | 10nF          | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C3         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C4         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C5         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C6         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C7         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C8         | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C12        | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C13        | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C15        | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C16        | 100nF         | Capacitor_SMD:C_0402_1005Metric                           | C1525     |
| C9         | 4.7uF         | Capacitor_SMD:C_0402_1005Metric                           | C23733    |
| C10        | 4.7uF         | Capacitor_SMD:C_0402_1005Metric                           | C23733    |
| C11        | 4.7uF         | Capacitor_SMD:C_0402_1005Metric                           | C23733    |
| C14        | 2.2uF         | Capacitor_SMD:C_0402_1005Metric                           | C12530    |
| C17        | 470nF         | Capacitor_Tantalum_SMD:CP_EIA-2012-12_Kemet-R             |           |
| C18        | 22pF          | Capacitor_SMD:C_0402_1005Metric                           | C70464    |
| C19        | 22pF          | Capacitor_SMD:C_0402_1005Metric                           | C70464    |
| D1         | LED           | LED_SMD:LED_0402_1005Metric                               | C71911    |
| D2         | LED           | LED_SMD:LED_0402_1005Metric                               | C71911    |
| Q1         | AO3401A       | Package_TO_SOT_SMD:SOT-23                                 | C15127    |
| R1         | 4.7K          | Resistor_SMD:R_0402_1005Metric                            | C25900    |
| R2         | 4.7K          | Resistor_SMD:R_0402_1005Metric                            | C25900    |
| R3         | 100K          | Resistor_SMD:R_0402_1005Metric                            | C25741    |
| R4         | 1K            | Resistor_SMD:R_0402_1005Metric                            | C11702    |
| R5         | 1K            | Resistor_SMD:R_0402_1005Metric                            | C11702    |
| R6         | 10k           | Resistor_SMD:R_0402_1005Metric                            | C25744    |
| R7         | 1M            | Resistor_SMD:R_0402_1005Metric                            | C26083    |
| U1         | AMS1117-3.3   | Package_TO_SOT_SMD:SOT-223-3_TabPin2                      | C6186     |
| U2         | STM32F103C8Tx | Package_QFP:LQFP-48_7x7mm_P0.5mm                          | C8734     |
| U3         | MPU-6050      | Sensor_Motion:InvenSense_QFN-24_4x4mm_P0.5mm              | C24112    |
| U4         | SN65HVD230    | Package_SO:SOIC-8_3.9x4.9mm_P1.27mm                       | C12084    |
| Y1         | 8MHz          | Crystal:Crystal_SMD_0603-2Pin_6.0x3.5mm                   | C111120   |


**Position file :**

| Designator | Value         | Footprint                                   | Mid X      | Mid Y       | Rotation   | Layer |
|------------|---------------|---------------------------------------------|------------|-------------|------------|-------|
| C1         | 100nF         | C_0805_2012Metric_Pad1.15x1.40mm_HandSolder | 106.680000 | -76.708000  | 0.000000   | top   |
| C2         | 10nF          | C_0402_1005Metric                           | 105.156000 | -85.090000  | 0.000000   | top   |
| C3         | 100nF         | C_0402_1005Metric                           | 107.188000 | -85.344000  | 90.000000  | top   |
| C4         | 100nF         | C_0402_1005Metric                           | 119.126000 | -84.074000  | 180.000000 | top   |
| C5         | 100nF         | C_0402_1005Metric                           | 108.458000 | -85.344000  | 270.000000 | top   |
| C6         | 100nF         | C_0402_1005Metric                           | 120.142000 | -95.250000  | 90.000000  | top   |
| C7         | 100nF         | C_0402_1005Metric                           | 105.664000 | -95.758000  | 270.000000 | top   |
| C8         | 100nF         | C_0402_1005Metric                           | 119.126000 | -85.090000  | 180.000000 | top   |
| C9         | 4.7uF         | C_0402_1005Metric                           | 119.126000 | -95.250000  | 90.000000  | top   |
| C10        | 4.7uF         | C_0402_1005Metric                           | 104.648000 | -95.758000  | 270.000000 | top   |
| C11        | 4.7uF         | C_0402_1005Metric                           | 119.126000 | -86.106000  | 180.000000 | top   |
| C12        | 100nF         | C_0402_1005Metric                           | 100.584000 | -87.376000  | 90.000000  | top   |
| C13        | 100nF         | C_0402_1005Metric                           | 103.124000 | -85.090000  | 180.000000 | top   |
| C14        | 2.2uF         | C_0402_1005Metric                           | 102.616000 | -92.456000  | 180.000000 | top   |
| C15        | 100nF         | C_0402_1005Metric                           | 121.920000 | -95.250000  | 90.000000  | top   |
| C16        | 100nF         | C_0402_1005Metric                           | 107.188000 | -102.870000 | 180.000000 | top   |
| C17        | 470nF         | CP_EIA-2012-12_Kemet-R                      | 123.444000 | -74.422000  | 0.000000   | top   |
| C18        | 22pF          | C_0402_1005Metric                           | 116.586000 | -85.090000  | 0.000000   | top   |
| C19        | 22pF          | C_0402_1005Metric                           | 111.760000 | -85.090000  | 180.000000 | top   |
| D1         | LED           | LED_0402_1005Metric                         | 122.428000 | -93.218000  | 180.000000 | top   |
| D2         | LED           | LED_0402_1005Metric                         | 122.428000 | -92.202000  | 180.000000 | top   |
| Q1         | AO3401A       | SOT-23                                      | 106.680000 | -81.534000  | 270.000000 | top   |
| R1         | 4.7K          | R_0402_1005Metric                           | 105.664000 | -93.726000  | 90.000000  | top   |
| R2         | 4.7K          | R_0402_1005Metric                           | 104.648000 | -93.726000  | 90.000000  | top   |
| R3         | 100K          | R_0402_1005Metric                           | 105.156000 | -102.870000 | 0.000000   | top   |
| R4         | 1K            | R_0402_1005Metric                           | 120.396000 | -93.218000  | 180.000000 | top   |
| R5         | 1K            | R_0402_1005Metric                           | 120.396000 | -92.202000  | 180.000000 | top   |
| R6         | 10k           | R_0402_1005Metric                           | 122.936000 | -90.678000  | 90.000000  | top   |
| R7         | 1M            | R_0402_1005Metric                           | 114.554000 | -85.090000  | 180.000000 | top   |
| U1         | AMS1117-3.3   | SOT-223-3_TabPin2                           | 115.570000 | -76.708000  | 0.000000   | top   |
| U2         | STM32F103C8Tx | LQFP-48_7x7mm_P0.5mm                        | 114.046000 | -90.932000  | 270.000000 | top   |
| U3         | MPU-6050      | InvenSense_QFN-24_4x4mm_P0.5mm              | 103.886000 | -89.154000  | 180.000000 | top   |
| U4         | SN65HVD230    | SOIC-8_3.9x4.9mm_P1.27mm                    | 106.934000 | -99.568000  | 180.000000 | top   |
| Y1         | 8MHz          | Crystal_SMD_0603-2Pin_6.0x3.5mm             | 114.300000 | -82.550000  | 180.000000 | top   |





























