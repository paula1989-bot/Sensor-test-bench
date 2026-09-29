#include <Wire.h>

#define MPU 0x68

void setup() {

  Serial.begin(115200);
  Wire.begin();


  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();

}

void loop() {

  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission();

  Wire.requestFrom(MPU, 8);

  
  int ax_alto = Wire.read();
  int ax_bajo = Wire.read();
  int ax = (ax_alto << 8) | ax_bajo;

  
  int ay_alto = Wire.read();
  int ay_bajo = Wire.read();
  int ay = (ay_alto << 8) | ay_bajo;

  
  int az_alto = Wire.read();
  int az_bajo = Wire.read();
  int az = (az_alto << 8) | az_bajo;

  
  int temp_alto = Wire.read();
  int temp_bajo = Wire.read();
  int temp = (temp_alto << 8) | temp_bajo;

  
  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  float temperatura = temp / 340.0 + 36.53;

 
  Serial.print(ax_g);
  Serial.print(",");

  Serial.print(ay_g);
  Serial.print(",");

  Serial.print(az_g);
  Serial.print(",");

  Serial.println(temperatura);

  delay(500);
}