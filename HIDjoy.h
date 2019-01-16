#include <USBComposite.h>

#include "FFBdesc.h"

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
    uint8_t  pid1;
    uint8_t  pid2;
} __packed JoyReport_t;

class HID_Joystick : public HIDReporter {
  
  protected:
  
    JoyReport_t report;
    bool manualReport = false;
    void safeSendReport(void);

    uint8_t buffer[100];
    HIDBuffer_t Data;
    
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

    uint8_t getBufData(uint8_t i) {
      return buffer[i];
    }
    
    HID_Joystick(USBHID& HID) : 
      HIDReporter(HID, (uint8_t*)&report, sizeof(report), TLID),
      Data(buffer, 100, TLID, HID_BUFFER_MODE_NO_WAIT)
      {
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

