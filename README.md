# Sensor Test Bench

This project simulates a simple sensor test bench using an ESP32 and an
MPU6050 IMU sensor. The ESP32 reads the sensor over I2C and sends the
measurements over UART.

A Python script reads the measurements and reports PASS/FAIL depending
on the defined thresholds.

## Files
- `sketch.ino`: ESP32 code (C++/Arduino) that reads the MPU6050 registers over I2C
- `check.py`: Python script that reads the log and reports PASS/FAIL
- `log.csv`: example log obtained from the simulation

## How to run
1. Open the simulation in Wokwi: [Wokwi simulation](https://wokwi.com/projects/476523698918266881)
2. Copy the serial monitor output into `log.csv`
3. Run `python check.py log.csv`

## Thresholds
- Temperature between 15 and 35 °C
- Acceleration magnitude between 0.8 and 1.2 g

The script exits with code 0 for PASS and 1 for FAIL.
