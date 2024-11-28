// Pin Defines
#define P_SWITCH0_PIN 2
#define GREEN_LED0_PIN 3
#define RED_LED0_PIN 4
#define RED_LED1_PIN 5

// Constant Defines
#define BLINK_DURATION 5000 // ms

// Global Variables
int switchState = 0;

void pinSetup() {
  pinMode(P_SWITCH0_PIN,INPUT);
  pinMode(GREEN_LED0_PIN,OUTPUT);
  pinMode(RED_LED0_PIN,OUTPUT);
  pinMode(RED_LED1_PIN,OUTPUT);
}

void initalLEDBlink() {
  // Blink LEDs in Sequnce
  digitalWrite(GREEN_LED0_PIN,HIGH);
  delay(500);
  digitalWrite(GREEN_LED0_PIN,LOW);

  digitalWrite(RED_LED0_PIN,HIGH);
  delay(500);
  digitalWrite(RED_LED0_PIN,LOW);

  digitalWrite(RED_LED1_PIN,HIGH);
  delay(500);
  digitalWrite(RED_LED1_PIN,LOW);

  // Toggle LEDs
  for (int idx = 0; idx < 2; idx++) {
    digitalWrite(GREEN_LED0_PIN,HIGH);
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,HIGH);

    delay(500);
    
    digitalWrite(GREEN_LED0_PIN,LOW);
    digitalWrite(RED_LED0_PIN,LOW);
    digitalWrite(RED_LED1_PIN,LOW);
    
    delay(500);
  }
}

void defaultLEDState() {
  digitalWrite(GREEN_LED0_PIN,HIGH);
  digitalWrite(RED_LED0_PIN,LOW);
  digitalWrite(RED_LED1_PIN,LOW);
}

void blinkLED(int duration) {
  int elapsed = 0;

  while (elapsed < duration) {
    digitalWrite(GREEN_LED0_PIN,LOW);
    digitalWrite(RED_LED0_PIN,HIGH);
    digitalWrite(RED_LED1_PIN,LOW);
    delay(250);
    digitalWrite(RED_LED0_PIN,LOW);
    digitalWrite(RED_LED1_PIN,HIGH);
    delay(250);

    elapsed += 500;
  }
}

void setup() {
  pinSetup();
  initalLEDBlink();
}

void loop() {
  switchState = digitalRead(P_SWITCH0_PIN);

  if (switchState == LOW) {
    defaultLEDState();
  } else {
    blinkLED(BLINK_DURATION);
  }
}
