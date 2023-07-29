const int sensorPin = A0;  // Analog pin for the sensor data
const int ledPin = 13;     // Built-in LED on Arduino (You can use an external LED as well)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);       // Read the analog sensor data
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert the sensor value to voltage
  float ppm = (voltage - 0.15) * 1000 / 0.3;     // Convert the voltage to ppm value (This calibration may vary for different sensors)

  Serial.print("Air Quality (PPM): ");
  Serial.println(ppm);

  if (ppm > 200) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED if pollution exceeds a threshold value (You can set your own threshold)
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED if pollution is within a safe range
  }

  delay(2000);  // Adjust the delay as needed based on how often you want to measure air quality
}
