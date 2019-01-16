#include <USBComposite.h>

#define HID_ID_SET_EFFECT   31

#define HID_SET_EFFECT_REPORT_DESCRIPTOR() \
  0x05, 0x0F,           /* Usage Page (Physical Interface) */ \
  \
  0x09, 0x21,           /*   Usage (Set Effect Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_SET_EFFECT, /* Report ID 1 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x25,           /*     Usage (Effect Type) */ \
  0xA1, 0x02,           /*       Collection Datalink (Logical) */ \
  0x09, HID_USAGE_CONST,/*         Usage (ET Constant Force) */ \
  0x09, HID_USAGE_RAMP, /*         Usage (ET Ramp) */ \
  0x09, HID_USAGE_SQUR, /*         Usage (ET Square) */ \
  0x09, HID_USAGE_SINE, /*         Usage (ET Sine) */ \
  0x09, HID_USAGE_TRNG, /*         Usage (ET Triangle) */ \
  0x09, HID_USAGE_STUP, /*         Usage (ET Sawtooth Up) */ \
  0x09, HID_USAGE_STDN, /*         Usage (ET Sawtooth Down) */ \
  0x09, HID_USAGE_SPRNG,/*         Usage (ET Spring) */ \
  0x09, HID_USAGE_DMPR, /*         Usage (ET Damper) */ \
  0x09, HID_USAGE_INRT, /*         Usage (ET Inertia) */ \
  0x09, HID_USAGE_FRIC, /*         Usage (ET Friction) */ \
  0x09, 0x28,           /*         Usage (ET Custom Force Data) */ \
  0x15, 0x01,           /*          Logical Minimum (1) */ \
  0x25, 0x0C,           /*          Logical Maximum (12) */ \
  0x35, 0x01,           /*          Physical Minimum (1) */ \
  0x45, 0x0C,           /*          Physical Maximum (12) */ \
  0x75, 0x08,           /*          Report Size (8) */ \
  0x95, 0x01,           /*          Report Count (1) */ \
  0x91, 0x00,           /*          Output (Data) */ \
  0xC0,                 /*       End Collection Datalink (Logical) */ \
  0x09, 0x50,           /*       Usage (Duration) */ \
  0x09, 0x54,           /*       Usage (Trigger Repeat Interval) */ \
  0x09, 0x51,           /*       Usage (Sample Period) */ \
  0x15, 0x00,           /*        Logical Minimum (0) */ \
  0x26, 0xFF, 0x7F,     /*        Logical Maximum (32767) */ \
  0x35, 0x00,           /*        Physical Minimum (1) */ \
  0x46, 0xFF, 0x7F,     /*        Physical Maximum (32767) */ \
  0x66, 0x03, 0x10,     /*        Unit (4099) */ \
  0x55, 0xFD,           /*        Unit Exponent (253) */ \
  0x75, 0x10,           /*        Report Size (16) */ \
  0x95, 0x03,           /*        Report Count (3) */ \
  0x91, 0x02,           /*        Output (Data,Var,Abs) */ \
  0x55, 0x00,           /*        Unit Exponent (0) */ \
  0x66, 0x00, 0x00,     /*        Unit (0) */ \
  0x09, 0x52,           /*       Usage (Gain) */ \
  0x15, 0x00,           /*        Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*        Logical Maximum (255) */ \
  0x35, 0x00,           /*        Physical Minimum (1) */ \
  0x46, 0x10, 0x27,     /*        Physical Maximum (10000) */ \
  0x75, 0x08,           /*        Report Size (8) */ \
  0x95, 0x01,           /*        Report Count (1) */ \
  0x91, 0x02,           /*        Output (Data,Var,Abs) */ \
  0x09, 0x53,           /*       Usage (Trigger Button) */ \
  0x15, 0x01,           /*        Logical Minimum (1) */ \
  0x25, 0x08,           /*        Logical Maximum (8) */ \
  0x35, 0x01,           /*        Physical Minimum (1) */ \
  0x45, 0x08,           /*        Physical Maximum (8) */ \
  0x75, 0x08,           /*        Report Size (8) */ \
  0x95, 0x01,           /*        Report Count (1) */ \
  0x91, 0x02,           /*        Output (Data,Var,Abs) */ \
  0x09, 0x55,           /*       Usage (Axes Enable) */ \
  0xA1, 0x02,           /*         Collection Datalink (Logical) */ \
  0x05, 0x01,           /*           Usage Page (Generic Desktop) */ \
  0x09, 0x30,           /*           Usage (X) */ \
  0x09, 0x31,           /*           Usage (Y) */ \
  0x15, 0x00,           /*           Logical Minimum (0) */ \
  0x25, 0x01,           /*           Logical Maximum (1) */ \
  0x75, 0x01,           /*           Report Size (1) */ \
  0x95, 0x02,           /*           Report Count (2) */ \
  0x91, 0x02,           /*           Output (Data,Var,Abs) */ \
  0xC0,                 /*         End Collection Datalink (Logical) */ \
  \
  0x05, 0x0F,           /*       Usage Page (Physical Interface) */ \
  0x09, 0x56,           /*         Usage (Direction Enable) */ \
  0x95, 0x01,           /*           Report Count (1) */ \
  0x91, 0x02,           /*           Output (Data,Var,Abs) */ \
  0x95, 0x05,           /*           Report Count (5) */ \
  0x91, 0x03,           /*           Output (Constant, Variable) */ \
  0x09, 0x57,           /*         Usage (Direction) */ \
  0xA1, 0x02,           /*           Collection Datalink (Logical) */ \
  0x0B, 0x01,0,0x0A,0,  /*             Usage (Ordinals: Instance 1) */ \
  0x0B, 0x02,0,0x0A,0,  /*             Usage (Ordinals: Instance 2) */ \
  0x66, 0x14, 0x00,     /*             Unit (20) */ \
  0x55, 0xFE,           /*             Unit Exponent (254) */ \
  0x15, 0x00,           /*             Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*             Logical Maximum (255) */ \
  0x35, 0x00,           /*             Physical Minimum (1) */ \
  0x47, 0xA0, 0x8C,0,0, /*             Physical Maximum (36000) */ \
  0x66, 0x00, 0x00,     /*             Unit (0) */ \
  0x75, 0x08,           /*             Report Size (8) */ \
  0x95, 0x02,           /*             Report Count (2) */ \
  0x91, 0x02,           /*             Output (Data,Var,Abs) */ \
  0x55, 0x00,           /*             Unit Exponent (0) */ \
  0x66, 0x00, 0x00,     /*             Unit (0) */ \
  0xC0,                 /*           End Collection Datalink (Logical) */ \
  \
  0x05, 0x0F,           /*       Usage Page (Physical Interface) */ \
  0x09, 0x58,           /*         Usage (Type Specific Block Offset) */ \
  0xA1, 0x02,           /*           Collection (Logical) */ \
  0x0B, 0x01,0,0x0A,0,  /*             Usage (Ordinals: Instance 1) */ \
  0x0B, 0x02,0,0x0A,0,  /*             Usage (Ordinals: Instance 2) */ \
  0x26, 0xFD, 0x7F,     /*             Logical Maximum (32765); 32K RAM or ROM max. */ \
  0x75, 0x10,           /*             Report Size (16) */ \
  0x95, 0x02,           /*             Report Count (2) */ \
  0x91, 0x02,           /*             Output (Data,Var,Abs) */ \
  0xC0,                 /*           End Collection (Logical) */ \
  \
  0xC0                  /*   End Collection Datalink (Logical) (OK) */

typedef struct {
    uint8_t  reportID;
} __packed SetEffectReport_t;

class HID_SetEffect : public HIDReporter {
  
  protected:
  
    SetEffectReport_t report;
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
    
    HID_SetEffect(USBHID& HID) : HIDReporter(HID, (uint8_t*)&report, sizeof(report), HID_ID_SET_EFFECT) {
      
      }
};

