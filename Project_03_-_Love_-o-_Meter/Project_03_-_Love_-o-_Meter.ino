// Pin Defines
#define TEMP_SENSOR_PIN A0
#define RED_LED0_PIN 2
#define RED_LED1_PIN 3
#define RED_LED2_PIN 4

// Constant Defines
#define BASE_TEMP 24.0

void pinSetup() {
  pinMode(TEMP_SENSOR_PIN,INPUT);
  pinMode(RED_LED0_PIN,OUTPUT);
  pinMode(RED_LED1_PIN,OUTPUT);
  pinMode(RED_LED2_PIN,OUTPUT);
}

void initialLEDBlink() {
  // Blink LEDs in Sequnce
  digitalWrite(RED_LED0_PIN,HIGH);
  delay(500);
  digitalWrite(RED_LED0_PIN,LOW);

  digitalWrite(RED_LED1_PIN,HIGH);
  delay(500);
  digitalWrite(RED_LED1_PIN,LOW);

  digitalWrite(RED_LED2_PIN,HIGH);
  delay(500);
  digitalWrite(RED_LED2_PIN,LOW);

  // Toggle LEDs
  for (int idx = 0; idx < 2; idx++) {
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,HIGH);
    digitalWrite(RED_LED2_PIN,HIGH);

    delay(500);
    
    digitalWrite(RED_LED0_PIN,LOW);
    digitalWrite(RED_LED1_PIN,LOW);
    digitalWrite(RED_LED2_PIN,LOW);
    
    delay(500);
  }
}

void defaultLEDState() {
  digitalWrite(RED_LED0_PIN,LOW);
  digitalWrite(RED_LED1_PIN,LOW);
  digitalWrite(RED_LED2_PIN,LOW);
}

void setup() {
  pinSetup();
  initialLEDBlink();
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(TEMP_SENSOR_PIN);
  float voltageValue = (sensorValue / 1024.0) * 5;
  float temperatureValue = (voltageValue - 0.5) * 100;

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage Value (mV): ");
  Serial.print(voltageValue);
  Serial.print(", Temperature Value (Celsius):  ");
  Serial.println(temperatureValue);
  
  if (temperatureValue < BASE_TEMP+2) {
    digitalWrite(RED_LED0_PIN,LOW);
    digitalWrite(RED_LED1_PIN,LOW);
    digitalWrite(RED_LED2_PIN,LOW);
  } else if ((temperatureValue >= BASE_TEMP+2) && (temperatureValue < BASE_TEMP+4)) {
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,LOW);
    digitalWrite(RED_LED2_PIN,LOW);
  } else if ((temperatureValue >= BASE_TEMP+4) && (temperatureValue < BASE_TEMP+6)) {
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,HIGH);
    digitalWrite(RED_LED2_PIN,LOW);
  } else if (temperatureValue >= BASE_TEMP+6) {
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,HIGH);
    digitalWrite(RED_LED2_PIN,HIGH);
  }

  delay(250);
}