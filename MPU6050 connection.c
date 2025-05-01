#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found! Check connections.");
    while (1) yield();
  }
  Serial.println("MPU6050 ready.");

  // Set accelerometer sensitivity
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Read acceleration on all 3 axes
  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;

  // Calculate the total acceleration vector magnitude
  float totalAccel = sqrt(ax * ax + ay * ay + az * az);

  // Simple motion detection: if movement is over threshold
  if (totalAccel > 12) {
    Serial.println("Motion Detected!");
  }

  // Print readings
  Serial.print("Accel X: "); Serial.print(ax);
  Serial.print(" Y: "); Serial.print(ay);
  Serial.print(" Z: "); Serial.print(az);
  Serial.print(" | Total: "); Serial.println(totalAccel);

  delay(200);
}
