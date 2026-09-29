#include <Wire.h>
#define sensormpu 0x68

int16_t read16() {
  int16_t hi = Wire.read();
  int16_t lo = Wire.read();
  return (hi << 8) | lo;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(sensormpu);
  Wire.write(0x6B);            // registro de energía
  Wire.write(0x00);            // despertar el sensor
  Wire.endTransmission(true);
  Serial.println("timestamp_ms,ax_g,ay_g,az_g,temp_c");
}

void loop() {
  Wire.beginTransmission(sensormpu);
  Wire.write(0x3B);            // primer registro de datos
  Wire.endTransmission(false);
  Wire.requestFrom(sensormpu, 8, true);

  int16_t ax = read16();
  int16_t ay = read16();
  int16_t az = read16();
  int16_t t  = read16();

  Serial.print(millis());           Serial.print(",");
  Serial.print(ax / 16384.0, 3);    Serial.print(",");
  Serial.print(ay / 16384.0, 3);    Serial.print(",");
  Serial.print(az / 16384.0, 3);    Serial.print(",");
  Serial.println(t / 340.0 + 36.53, 2);
  delay(500);
}