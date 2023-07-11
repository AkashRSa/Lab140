#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

#define counterButton D7
#define interruptToggle D6

bool areInterruptsAllowed = false;
volatile int counter = 0;

void counterISR()
{
  counter++;
}

void setup()
{
  Serial.begin(9600);
  while (!Serial.isConnected())
  {
  }
  pinMode(counterButton, INPUT_PULLUP);
  pinMode(interruptToggle, INPUT_PULLUP);
  attachInterrupt(counterButton, counterISR, FALLING);
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

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Counter: " + String(counter));
  display.display();
  if (!digitalRead(interruptToggle))
  {
    areInterruptsAllowed = !areInterruptsAllowed;
    if (areInterruptsAllowed)
    {
      interrupts();
    }
    else
    {
      noInterrupts();
    }
  }
}
