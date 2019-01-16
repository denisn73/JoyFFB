#include "HIDjoy.h" 

void HID_Joystick::begin(void){
}

void HID_Joystick::end(void){
}

void HID_Joystick::setManualReportMode(bool mode) {
    manualReport = mode;
}

bool HID_Joystick::getManualReportMode() {
    return manualReport;
}

void HID_Joystick::safeSendReport() {  
    if(!manualReport) sendReport();
}

void HID_Joystick::button(uint8_t button, bool val){
    uint32_t mask = ((uint32_t)1 << (button-1));
    if (val) report.buttons |= mask;
    else     report.buttons &= ~mask;
    safeSendReport();
}

void HID_Joystick::steering(uint8_t val){
    if(val > 255) val = 255;
    report.steering = val;
    safeSendReport();
}

void HID_Joystick::throttle(uint8_t val) {
    if(val > 255) val = 255;
    report.throttle = val;
    safeSendReport();
}

void HID_Joystick::accelerator(uint8_t val) {
    if(val > 255) val = 255;
    report.accelerator = val;
    safeSendReport();
}

void HID_Joystick::brake(uint8_t val) {
    if(val > 255) val = 255;
    report.brake = val;
    safeSendReport();
}

void HID_Joystick::shifter(uint8_t val) {
    if(val > 255) val = 255;
    report.shifter = val;
    safeSendReport();
}

void HID_Joystick::sliderLeft(uint16_t val) {
    if(val > 65535) val = 65535;
    report.sliderLeft = val; 
    safeSendReport();
}

void HID_Joystick::sliderRight(uint16_t val) {
    if(val > 65535) val = 65535;
    report.sliderRight = val;  
    safeSendReport();
}

void HID_Joystick::Xrotate(uint16_t val) {
    if(val > 65535) val = 65535;
    report.rx = val;
    safeSendReport();
}

void HID_Joystick::Yrotate(uint16_t val) {
    if(val > 65535) val = 65535;
    report.ry = val;
    safeSendReport();
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
    report.hat &= 0x0F;
    report.hat |= (val << 4);
  } else {
    report.hat &= 0xF0;
    report.hat |= val;
  }
  safeSendReport();
}

