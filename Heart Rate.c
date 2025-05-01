// Basic ECG (AD8232) Reading and Heart Rate Detection with ESP32
// Developed for Arduino IDE

const int ecgPin = 34;  // Analog pin connected to ECG OUT from AD8232
int threshold = 550;    // Threshold for detecting heartbeats (adjustable)

unsigned long lastBeatTime = 0;
int heartRate = 0;
int beatCount = 0;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ecgPin, INPUT);
  startTime = millis();
}

void loop() {
  int ecgValue = analogRead(ecgPin);
  Serial.println(ecgValue);  // Optional: plot the ECG raw signal on Serial Plotter

  unsigned long currentTime = millis();
  
  // Simple peak detection
  if (ecgValue > threshold && (currentTime - lastBeatTime) > 300) { // 300ms debounce (~200 bpm max)
    lastBeatTime = currentTime;
    beatCount++;
    Serial.println("Beat detected!");
  }

  // Calculate heart rate every 10 seconds
  if (currentTime - startTime >= 10000) {
    heartRate = beatCount * 6; // 10 sec × 6 = 60 sec (1 minute)
    Serial.print("Heart Rate: ");
    Serial.print(heartRate);
    Serial.println(" BPM");
    beatCount = 0;
    startTime = currentTime;
  }

  delay(5); // Small delay for stability
}