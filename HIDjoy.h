#include <USBComposite.h>

#include "HIDusage.h"

#define HID_ID_JOY   30

#define HID_JOY_REPORT_DESCRIPTOR() \
  0x05, 0x01,           /* Usage Page (Generic Desktop) */ \
  0x09, 0x04,           /* Usage (Joystick) */ \
  0xA1, 0x01,           /* Collection (Application) */ \
  0x85, HID_ID_JOY,     /* REPORT_ID 1 */ \
  0x05, 0x01,           /*   Usage Page (Generic Desktop) */ \
  \
  0x05, 0x09,           /* Usage Page (Button) */ \
  \
  0x19, 0x01,           /*   Usage Minimum (Button #1) */ \
  0x29, 0x20,           /*   Usage Maximum (Button #32) */ \
  0x15, 0x00,           /*   Logical Minimum (0) */ \
  0x25, 0x01,           /*   Logical Maximum (1) */ \
  0x75, 0x01,           /*   Report Size (1) */ \
  0x95, 0x20,           /*   Report Count (32) */ \
  0x55, 0x00,           /*   Unit Exponent (0) */ \
  0x65, 0x00,           /*   Unit (None) */ \
  0x81, 0x02,           /*   Input (variable,absolute) */ \
  \
  0x05, 0x01,           /* Usage Page (Generic Desktop) */ \
  0x09, 0x39,           /*   Usage (Hat switch) */ \
  0x15, 0x00,           /*   Logical Minimum (0) */ \
  0x25, 0x07,           /*   Logical Maximum (7) */ \
  0x35, 0x00,           /*   Physical Minimum (0) */ \
  0x46, 0x3B, 0x01,     /*   Physical Maximum (315) */ \
  0x65, 0x14,           /*   Unit (Eng Rot:Angular Pos) */ \
  0x75, 0x04,           /*   Report Size (4) */ \
  0x95, 0x01,           /*   Report Count (1) */ \
  0x81, 0x02,           /*   Input (variable,absolute) */ \
  \
  0x09, 0x39,           /*   Usage (Hat switch) */ \
  0x15, 0x00,           /*   Logical Minimum (0) */ \
  0x25, 0x07,           /*   Logical Maximum (7) */ \
  0x35, 0x00,           /*   Physical Minimum (0) */ \
  0x46, 0x3B, 0x01,     /*   Physical Maximum (315) */ \
  0x65, 0x14,           /*   Unit (Eng Rot:Angular Pos) */ \
  0x75, 0x04,           /*   Report Size (4) */ \
  0x95, 0x01,           /*   Report Count (1) */ \
  0x81, 0x02,           /*   Input (variable,absolute) */ \
  \
  0x09, 0x01,           /*   Usage (Pointer) */ \
  0x15, 0x00,           /*   Logical Minimum (0) */ \
  0x27, 0xFF,0xFF,0,0,  /*   Logical Maximum (65535) */ \
  0xA1, 0x00,           /*   Collection (Physical) */ \
  0x09, 0x33,           /*     Usage (Rx) */ \
  0x09, 0x34,           /*     Usage (Ry) */ \
  0x09, 0x36,           /*     Usage (Slider) */ \
  0x09, 0x36,           /*     Usage (Slider) */ \
  0x75, 0x10,           /*     Report Size (16) */ \
  0x95, 0x04,           /*     Report Count (4) */ \
  0x81, 0x02,           /*     Input (variable,absolute) */ \
  0xC0,                 /*   End Collection */ \
  \
  0x05, 0x02,           /* Usage Page (Simulation Controls) */ \
  0x15, 0x00,           /*   Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*   Logical Maximum (255) */ \
  0xA1, 0x00,           /*   Collection (Physical) */ \
  0x09, 0xC8,           /*     Usage (Steering) */ \
  0x09, 0xBB,           /*     Usage (Throttle) */ \
  0x09, 0xC4,           /*     Usage (Accelerator) */ \
  0x09, 0xC5,           /*     Usage (Brake) */ \
  0x09, 0xC6,           /*     Usage (Clutch) */ \
  0x09, 0xC7,           /*     Usage (Shifter) */ \
  0x75, 0x08,           /*     Report Size (8) */ \
  0x95, 0x06,           /*     Report Count (6) */ \
  0x81, 0x02,           /*     Input (variable,absolute) */ \
  0xC0,                 /*   End Collection */ \
  \
  0xC0                  /* End Collection (Application) */

typedef struct {
    uint8_t  reportID;
    uint32_t buttons;     //
    uint8_t  hat;         //
    uint16_t rx;          //
    uint16_t ry;          //
    uint16_t sliderLeft;
    uint16_t sliderRight;
    uint8_t  steering;    // рулевое управление
    uint8_t  throttle;    // газ
    uint8_t  accelerator; // ускоритель
    uint8_t  brake;       // тормоз
    uint8_t  clutch;      // сцепление
    uint8_t  shifter;     // переключатель
} __packed JoyReport_t;

class HID_Joystick : public HIDReporter {
  
  protected:
  
    JoyReport_t report;
    bool manualReport = false;
    void safeSendReport(void);
    
  public:
  
    inline void send(void) {
        sendReport();
    }
    void setManualReportMode(bool manualReport); // in manual report mode, reports only sent when send() is called
    bool getManualReportMode();
    void begin(void);
    void end(void);
    void button(uint8_t button, bool val);
    void hat(uint8_t num, int16_t dir);
    void Xrotate(uint16_t val);
    void Yrotate(uint16_t val);
    void sliderLeft(uint16_t val);
    void sliderRight(uint16_t val);
    void steering(uint8_t val);    // рулевое управление
    void throttle(uint8_t val);    // газ
    void accelerator(uint8_t val); // ускоритель
    void brake(uint8_t val);       // тормоз
    void clutch(uint8_t val);      // сцепление
    void shifter(uint8_t val);     // переключатель
    
    HID_Joystick(USBHID& HID) : HIDReporter(HID, (uint8_t*)&report, sizeof(report), HID_ID_JOY) {
          report.buttons     = 0;
          report.hat         = 255;
          report.rx          = 32767;
          report.ry          = 32767;
          report.sliderLeft  = 0;
          report.sliderRight = 0;
          report.steering    = 127;
          report.accelerator = 0;
          report.throttle    = 0;
          report.brake       = 0;
          report.shifter     = 0;
          report.clutch      = 0;
      }
};

