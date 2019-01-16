#include <USBComposite.h>

#define HID_ID_PID_STATE   32

#define HID_PID_STATE_REPORT_DESCRIPTOR() \
  0x05, 0x01,           /* Usage Page (Generic Desktop) */ \
  0x09, 0x04,           /* Usage (Joystick) */ \
  0xA1, 0x01,           /* Collection (Application) */ \
  \
  0x05, 0x0F,           /* Usage Page (Physical Interface) */ \
  \
  0x09, 0x92,           /*   Usage (PID State report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_PID_STATE, /*   Report ID 2 */ \
  0x09, 0x9F,           /*     Usage (Device is Pause) */ \
  0x09, 0xA0,           /*     Usage (Actuators Enabled) */ \
  0x09, 0xA4,           /*     Usage (Safety Switch) */ \
  0x09, 0xA5,           /*     Usage (Actuator Override Switch) */ \
  0x09, 0xA6,           /*     Usage (Actuator Power) */ \
  0x15, 0x00,           /*     Logical Minimum (0) */ \
  0x25, 0x01,           /*     Logical Maximum (1) */ \
  0x35, 0x00,           /*     Physical Minimum (0) */ \
  0x45, 0x01,           /*     Physical Maximum (1) */ \
  0x75, 0x01,           /*     Report Size (1) */ \
  0x95, 0x05,           /*     Report Count (5) */ \
  0x81, 0x02,           /*     Input (variable,absolute) */ \
  0x95, 0x03,           /*     Report Count (3) */ \
  0x81, 0x03,           /*     Input (Constant, Variable) */ \
  0x09, 0x94,           /*     Usage (Effect Playing) */ \
  0x15, 0x00,           /*     Logical Minimum (0) */ \
  0x25, 0x01,           /*     Logical Maximum (1) */ \
  0x35, 0x00,           /*     Physical Minimum (0) */ \
  0x45, 0x01,           /*     Physical Maximum (1) */ \
  0x75, 0x01,           /*     Report Size (1) */ \
  0x95, 0x01,           /*     Report Count (1) */ \
  0x81, 0x02,           /*     Input (variable,absolute) */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*     Logical Minimum (1) */ \
  0x25, 0x28,           /*     Logical Maximum (40) */ \
  0x35, 0x01,           /*     Physical Minimum (1) */ \
  0x45, 0x28,           /*     Physical Maximum (40) */ \
  0x75, 0x07,           /*     Report Size (7) */ \
  0x95, 0x01,           /*     Report Count (1) */ \
  0x81, 0x02,           /*     Input (variable,absolute) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0xC0                  /*   End Collection (Application) */

typedef struct {
    uint8_t  reportID;
    uint8_t  deviceIsPaused         : 1;  // 
    uint8_t  actuatorEnabled        : 1; // 
    uint8_t  safetySwitch           : 1; // 
    uint8_t  actuatorOverrideSwitch : 1; // 
    uint8_t  actuatorPower          : 1; // 
    uint8_t  padding                : 3; // 
    uint8_t  effectPlaying          : 1; // 
    uint8_t  effectBlockIndex       : 7; // 
} __packed PIDstateReport_t;

class HID_PID_State : public HIDReporter {
  
  protected:
  
    PIDstateReport_t report;
    bool manualReport = false;
    void safeSendReport(void) {
      if(!manualReport) sendReport();
    }
    
  public:
  
    inline void send(void) {
        sendReport();
    }
    void setManualReportMode(bool mode) { manualReport = mode; }
    bool getManualReportMode() { return manualReport; }
    void begin(void) {}
    void end(void) {}
    
    HID_PID_State(USBHID& HID) : HIDReporter(HID, (uint8_t*)&report, sizeof(report), HID_ID_PID_STATE) {
          report.deviceIsPaused         = 0;
          report.actuatorEnabled        = 1;
          report.safetySwitch           = 0;
          report.actuatorOverrideSwitch = 0;
          report.actuatorPower          = 1;
          report.padding                = 0;
          report.effectPlaying          = 0;
          report.effectBlockIndex       = 0;
      }
};

