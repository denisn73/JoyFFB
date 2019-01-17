#include "HIDjoy.h" 

void HID_Joystick::button(uint8_t button, bool val){
    uint32_t mask = ((uint32_t)1 << (button-1));
    if (val) reportJoy.buttons |= mask;
    else     reportJoy.buttons &= ~mask;
    safeSendReportJoy();
}

void HID_Joystick::steering(uint8_t val) {
    reportJoy.steering = val;
    safeSendReportJoy();
}

void HID_Joystick::throttle(uint8_t val) {
    reportJoy.throttle = val;
    safeSendReportJoy();
}

void HID_Joystick::accelerator(uint8_t val) {
    reportJoy.accelerator = val;
    safeSendReportJoy();
}

void HID_Joystick::brake(uint8_t val) {
    reportJoy.brake = val;
    safeSendReportJoy();
}

void HID_Joystick::shifter(uint8_t val) {
    reportJoy.shifter = val;
    safeSendReportJoy();
}

void HID_Joystick::sliderLeft(uint16_t val) {
    reportJoy.sliderLeft = val; 
    safeSendReportJoy();
}

void HID_Joystick::sliderRight(uint16_t val) {
    reportJoy.sliderRight = val;  
    safeSendReportJoy();
}

void HID_Joystick::Xrotate(uint16_t val) {
    reportJoy.rx = val;
    safeSendReportJoy();
}

void HID_Joystick::Yrotate(uint16_t val) {
    reportJoy.ry = val;
    safeSendReportJoy();
}

void HID_Joystick::hat(uint8_t num, int16_t dir) {
    uint8_t val;
       if (dir < 0)   val = 15;
  else if (dir < 23)  val = 0;
  else if (dir < 68)  val = 1;
  else if (dir < 113) val = 2;
  else if (dir < 158) val = 3;
  else if (dir < 203) val = 4;
  else if (dir < 245) val = 5;
  else if (dir < 293) val = 6;
  else if (dir < 338) val = 7;
  else val = 15;
  if(num) {
    reportJoy.hat &= 0x0F;
    reportJoy.hat |= (val << 4);
  } else {
    reportJoy.hat &= 0xF0;
    reportJoy.hat |= val;
  }
  safeSendReportJoy();
}

