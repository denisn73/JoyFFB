#include "HIDjoy.h"

const uint8_t reportDescription[] = {
   HID_MOUSE_REPORT_DESCRIPTOR(),
   HID_KEYBOARD_REPORT_DESCRIPTOR(),
   HID_JOY_REPORT_DESCRIPTOR(),
};

USBCompositeSerial CompositeSerial;
USBHID             HID;

HID_Joystick       joy(&HID);

#define RXSIZE 300
uint8 buf[RXSIZE];

void setup()
{
  
  HID.begin(CompositeSerial, reportDescription, sizeof(reportDescription));
  joy.begin();
  joy.setManualReportMode(true);
  pinMode(PC13, OUTPUT);
  
}

void loop()
{

  static bool joyChanged = false;
  
  static uint32_t lastJoyBtnMillis = 0;
  if(millis()-lastJoyBtnMillis >= 100) {
    //
    static uint8_t btnNum = 0;
    static bool    btnState[8];
    joy.button(btnNum+1, btnState[btnNum]);
    btnState[btnNum] = !btnState[btnNum];
    if(++btnNum>=sizeof(btnState)) btnNum = 0;
    //
    joyChanged = true;
    lastJoyBtnMillis = millis();
  }
  
  if(joyChanged) {
    joyChanged = false;
    joy.send();
  }

  static uint32_t lastLedMillis = 0;
  if(millis()-lastLedMillis >= 500) {
    digitalWrite(PC13, !digitalRead(PC13));
    lastLedMillis = millis();
  }

  static uint32_t lastDataMillis = 0;
  if(millis()-lastDataMillis >= 500) {
    CompositeSerial.println("--- OUTPUT -----------------");
    joy.printBufSetEffect();
    joy.printBufSetEnvelope();
    joy.printBufSetCondition();
    joy.printBufSetPeriodic();
    joy.printBufSetConstantForce();
    joy.printBufSetRampForce();
    CompositeSerial.println("--- FEATURE ----------------");
    joy.printBufNewEffect();
    joy.printBufBlockLoad();
    joy.printBufPoolPID();
    CompositeSerial.println();
    lastDataMillis = millis();
    
  }
  
  joy.test();
  
}

