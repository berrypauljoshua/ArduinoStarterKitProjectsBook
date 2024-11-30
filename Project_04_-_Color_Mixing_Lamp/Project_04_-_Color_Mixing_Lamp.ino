// Pin Defines
#define RGB_LED0_RED_PIN 9
#define RGB_LED0_GREEN_PIN 10
#define RGB_LED0_BLUE_PIN 11
#define RED_PHOTO_SENSOR0_PIN A0
#define GREEN_PHOTO_SENSOR0_PIN A1
#define BLUE_PHOTO_SENSOR0_PIN A2

// Global Variables
int redLEDValue = 0;
int greenLEDValue = 0;
int blueLEDValue = 0;
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void pinSetup() {
  pinMode(RGB_LED0_RED_PIN,OUTPUT);
  pinMode(RGB_LED0_GREEN_PIN,OUTPUT);
  pinMode(RGB_LED0_BLUE_PIN,OUTPUT);
  pinMode(RED_PHOTO_SENSOR0_PIN,INPUT);
  pinMode(GREEN_PHOTO_SENSOR0_PIN,INPUT);
  pinMode(BLUE_PHOTO_SENSOR0_PIN,INPUT);
}

void setup() {
  pinSetup();
  Serial.begin(9600);
}

void loop() {
  redSensorValue = analogRead(RED_PHOTO_SENSOR0_PIN);
  delay(10);
  greenSensorValue = analogRead(GREEN_PHOTO_SENSOR0_PIN);
  delay(10);
  blueSensorValue = analogRead(BLUE_PHOTO_SENSOR0_PIN);

  redLEDValue = redSensorValue / 4;
  greenLEDValue = greenSensorValue / 4;
  blueLEDValue = blueSensorValue / 4;

  analogWrite(RGB_LED0_RED_PIN,redLEDValue);
  analogWrite(RGB_LED0_GREEN_PIN,greenLEDValue);
  analogWrite(RGB_LED0_BLUE_PIN,blueLEDValue);

  Serial.print("Red Sensor Value: ");
  Serial.print(redSensorValue);
  Serial.print(", Green Sensor Value: ");
  Serial.print(greenSensorValue);
  Serial.print(", Blue Sensor Value: ");
  Serial.println(blueSensorValue);
  Serial.print("Red LED Value: ");
  Serial.print(redLEDValue);
  Serial.print(", Green LED Value: ");
  Serial.print(greenLEDValue);
  Serial.print(", Blue LED Value: ");
  Serial.println(blueLEDValue);
}