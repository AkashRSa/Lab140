/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Akash/IoTCamp2023/Lab140/src/Lab140.ino"
#include "oled-wing-adafruit.h"

void button1ISR();
void button2ISR();
void setup();
void loop();
#line 3 "c:/Users/Akash/IoTCamp2023/Lab140/src/Lab140.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

#define buttonPin1 D7
#define buttonPin2 D6
volatile bool interruptsEnabled = true;
volatile int counter = 0;

void button1ISR()
{
  Serial.println("test1");
  if (interruptsEnabled)
  {
    Serial.println("test2");
    counter++;
    display.setCursor(0, 0);
    display.println("Counter: " + String(counter));
    display.display();
  }
}

void button2ISR()
{
  interruptsEnabled = !interruptsEnabled;
  if (interruptsEnabled)
  {
    display.setCursor(0, 15);
    Serial.println("Interrupts: Enabled");
    display.display();
  }
  else
  {
    display.setCursor(0, 15);
    Serial.println("Interrupts: Disabled");
    display.display();
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial.isConnected())
  {
  }
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  // attachInterrupt(buttonPin1, button1ISR, FALLING);
  attachInterrupt(buttonPin2, button2ISR, FALLING);
  display.setup();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Counter: " + String(counter));
  Serial.println("Interrupts: Enabled");
  display.display();
}

void loop()
{
  if (!digitalRead(D7))
  {
    Serial.println("test4");
    if (interruptsEnabled)
    {
      Serial.println("test3");
      counter++;
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Counter: " + String(counter));
      display.display();
    }
  }
}
