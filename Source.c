#include <Wire.h>
#include <math.h>

// MPU6050 I2C address
const int MPU_ADDRESS = 0x68;

// Accelerometer variables
int16_t AcX, AcY, AcZ;

// Define buzzer pin (change to correct GPIO if needed)
#define buzzerPin D3

// Angle threshold for detecting deviation from vertical
const float ANGLE_THRESHOLD = 10.0; // Change as needed

// Function to initialize MPU6050
void setupMPU6050() {
  Wire.begin(D2, D1); // ESP8266: SDA = D2 (GPIO4), SCL = D1 (GPIO5)
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x6B); // Power management register
  Wire.write(0);    // Wake up MPU6050
  Wire.endTransmission(true);

  // Check if MPU6050 is connected
  Wire.beginTransmission(MPU_ADDRESS);
  if (Wire.endTransmission() != 0) {
    Serial.println("MPU6050 not detected! Check wiring.");
    while (1); // Halt execution if MPU6050 is not detected
  }
}

// Function to read accelerometer data
void readAccelerometer() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDRESS, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
}

// Function to calculate pitch and roll angles
void calculateAngles(float &pitch, float &roll) {
  float Ax = AcX / 16384.0;
  float Ay = AcY / 16384.0;
  float Az = AcZ / 16384.0;

  pitch = atan2(Ay, sqrt(Ax * Ax + Az * Az)) * 57.295779513;
  roll  = atan2(-Ax, sqrt(Ay * Ay + Az * Az)) * 57.295779513;
}

void setup() {
  Serial.begin(115200);
  setupMPU6050();
  
  // Initialize buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Test the buzzer (1 second beep)
  Serial.println("Testing buzzer...");
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  Serial.println("Buzzer test complete.");
}

void loop() {
  readAccelerometer();

  float pitch, roll;
  calculateAngles(pitch, roll);

  // Print raw values and angles for debugging
  Serial.print("Pitch: "); Serial.print(pitch);
  Serial.print(" | Roll: "); Serial.println(roll);

  // Detect if MPU6050 is vertical (Pitch or Roll ≈ ±90°)
  bool isVertical = (abs(pitch) > 50 && abs(pitch) < 100) || (abs(roll) > 80 && abs(roll) < 120);

  // Activate buzzer if it deviates from vertical position
  if (isVertical) {
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF when vertical
    Serial.println("MPU6050 is vertical, buzzer OFF");
  } else {
    digitalWrite(buzzerPin, HIGH); // Buzzer ON when tilted
    Serial.println("WARNING: MPU6050 TILTED! Buzzer ON");
  }
  
  delay(100);
}
