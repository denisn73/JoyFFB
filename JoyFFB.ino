#include "HIDjoy.h"
#include "HIDpidState.h"
#include "HIDsetEffect.h"

const uint8_t reportDescription[] = {
   HID_MOUSE_REPORT_DESCRIPTOR(),
   HID_KEYBOARD_REPORT_DESCRIPTOR(),
   HID_JOY_REPORT_DESCRIPTOR(),
   HID_PID_STATE_REPORT_DESCRIPTOR(),
   HID_SET_EFFECT_REPORT_DESCRIPTOR(),
};

USBCompositeSerial CompositeSerial;
USBHID             HID;

HID_Joystick       joystick(HID);
HID_PID_State      pidState(HID);
HID_SetEffect      setEffect(HID);

void setup()
{
  
  HID.begin(CompositeSerial, reportDescription, sizeof(reportDescription));
  //raw.begin();
  joystick.setManualReportMode(true);
  pidState.setManualReportMode(true);
  setEffect.setManualReportMode(true);
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
    joystick.button(btnNum+1, btnState[btnNum]);
    btnState[btnNum] = !btnState[btnNum];
    if(++btnNum>=sizeof(btnState)) btnNum = 0;
    //
    joyChanged = true;
    lastJoyBtnMillis = millis();
  }
  
  if(joyChanged) {
    joyChanged = false;
    joystick.send();
  }

  static uint32_t lastLedMillis = 0;
  if(millis()-lastLedMillis >= 500) {
    digitalWrite(PC13, !digitalRead(PC13));
    lastLedMillis = millis();
  }
  
  /*
  
  static uint32_t lastJoyAxisMillis = 0;
  if(millis()-lastJoyAxisMillis >= 100) {
    //
    static uint16_t xyRotate = 0;
    joystick.Xrotate(65535-xyRotate);
    joystick.Yrotate(xyRotate);
    xyRotate += 1000;
    if(xyRotate > 65535-1000) xyRotate = 0;
    //
    joyChanged = true;
    lastJoyAxisMillis = millis();
  }
  
  static uint32_t lastJoyHatMillis = 0;
  if(millis()-lastJoyHatMillis >= 10) {
    //
    static uint16_t hatRotate = 0;
    joystick.hat(0, hatRotate);
    joystick.hat(1, 360-hatRotate);
    hatRotate++;
    if(hatRotate >= 360) hatRotate = 0;
    //
    joyChanged = true;
    lastJoyHatMillis = millis();
  }
  
  static uint32_t lastJoyRaceMillis = 0;
  if(millis()-lastJoyRaceMillis >= 10) {
    //
    static uint8_t raceValue = 0;
    joystick.brake(raceValue);
    joystick.steering(raceValue+30);
    joystick.throttle(raceValue+60);
    joystick.accelerator(raceValue+90);
    raceValue++;
    //
    joyChanged = true;
    lastJoyRaceMillis = millis();
  }

  //if (raw.getOutput(rawBuf)) {
  //  for (int i=0;i<RAW_RXSIZE;i++) rawBuf[i]++;
  //  raw.send(rawBuf+RAW_RXSIZE-min(RAW_RXSIZE,RAW_TXSIZE),min(RAW_RXSIZE,RAW_TXSIZE));
  //}

  */
  
}

