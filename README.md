# Sensor-test-bench
# ESP32 + MPU6050 test bench simulated in Wokwi: I2C sensor reading, UART logging and Python PASS/FAIL checks
# Sensor Test Bench

Simulated test bench: an ESP32 reads an MPU6050 IMU sensor over I2C
and streams the measurements over UART. A Python script checks the
log and reports PASS/FAIL against configurable thresholds.

## Files
- `sketch.ino`: ESP32 firmware (C++/Arduino), reads the sensor registers over I2C
- `check.py`: Python script that parses the log and reports PASS/FAIL
- `log.csv`: example log captured from the simulation

## How to run
1. Open the simulation in Wokwi: [https://wokwi.com/projects/476523698918266881]
2. Copy the serial monitor output into `log.csv`
3. Run `python check.py log.csv`

## Thresholds
Temperature between 15 and 35 °C, and acceleration magnitude between 0.8 and 1.2 g.
The script exits with code 0 (PASS) or 1 (FAIL).
