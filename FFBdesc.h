
// HID Descriptor definitions - FFB Effects
#define HID_USAGE_CONST 0x26    //    Usage ET Constant Force
#define HID_USAGE_RAMP  0x27    //    Usage ET Ramp
#define HID_USAGE_SQUR  0x30    //    Usage ET Square
#define HID_USAGE_SINE  0x31    //    Usage ET Sine
#define HID_USAGE_TRNG  0x32    //    Usage ET Triangle
#define HID_USAGE_STUP  0x33    //    Usage ET Sawtooth Up
#define HID_USAGE_STDN  0x34    //    Usage ET Sawtooth Down
#define HID_USAGE_SPRNG 0x40    //    Usage ET Spring
#define HID_USAGE_DMPR  0x41    //    Usage ET Damper
#define HID_USAGE_INRT  0x42    //    Usage ET Inertia
#define HID_USAGE_FRIC  0x43    //    Usage ET Friction

// HID Descriptor definitions - FFB Report IDs
#define HID_ID_STATE    0x02  // Usage PID State report
#define HID_ID_EFFREP   0x01  // Usage Set Effect Report
#define HID_ID_ENVREP   0x02  // Usage Set Envelope Report
#define HID_ID_CONDREP  0x03  // Usage Set Condition Report
#define HID_ID_PRIDREP  0x04  // Usage Set Periodic Report
#define HID_ID_CONSTREP 0x05  // Usage Set Constant Force Report
#define HID_ID_RAMPREP  0x06  // Usage Set Ramp Force Report
#define HID_ID_CSTMREP  0x07  // Usage Custom Force Data Report
#define HID_ID_SMPLREP  0x08  // Usage Download Force Sample
#define HID_ID_EFOPREP  0x0A  // Usage Effect Operation Report
#define HID_ID_BLKFRREP 0x0B  // Usage PID Block Free Report
#define HID_ID_CTRLREP  0x0C  // Usage PID Device Control
#define HID_ID_GAINREP  0x0D  // Usage Device Gain Report
#define HID_ID_SETCREP  0x0E  // Usage Set Custom Force Report
#define HID_ID_NEWEFREP 0x01  // Usage Create New Effect Report
#define HID_ID_BLKLDREP 0x02  // Usage Block Load Report
#define HID_ID_POOLREP  0x03  // Usage PID Pool Report

#define HID_FFB_DESC_NULL(...)

#define HID_FFB_DESC(...) \
  0x05, 0x0F,           /* Usage Page (Physical Interface) */ \
  \
  0x09, 0x92,           /*   Usage (PID State report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_STATE+TLID, /*  Report ID 2 */ \
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
  0x09, 0x21,           /*   Usage (Set Effect Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_EFFREP+TLID, /* Report ID 1 */ \
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
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x5A,           /*   Usage (Set Envelope Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_ENVREP+TLID, /* Report ID 2 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x5B,           /*     Usage (Attack Level) */ \
  0x09, 0x5D,           /*     Usage (Fade Level) */ \
  0x16, 0x00, 0x00,     /*      Logical Minimum (0) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x36, 0x00, 0x00,     /*      Physical Minimum (0) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x02,           /*      Report Count (2) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x5C,           /*     Usage (Attack Time) */ \
  0x09, 0x5E,           /*     Usage (Fade Time) */ \
  0x66, 0x03, 0x10,     /*      Unit (1003h) English Linear, Seconds */ \
  0x55, 0xFD,           /*      Unit Exponent (FDh) (X10^-3 ==> Milisecond) */ \
  0x27, 0xFF, 0x7F,0,0, /*      Logical Maximum (4294967295) */ \
  0x47, 0xFF, 0x7F,0,0, /*      Physical Maximum (4294967295) */ \
  0x75, 0x20,           /*      Report Size (32) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x45, 0x00,           /*      Physical Maximum (0) */ \
  0x66, 0x00, 0x00,     /*      Unit (0) */ \
  0x55, 0x00,           /*      Unit Exponent (0) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x5F,           /*   Usage (Set Condition Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_CONDREP+TLID,/* Report ID 3 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x23,           /*     Usage (Parameter Block Offset) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x25, 0x03,           /*      Logical Maximum (3) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x45, 0x03,           /*      Physical Maximum (3) */ \
  0x75, 0x04,           /*      Report Size (4) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x58,           /*     Usage (Type Specific Block Off...) */ \
  0xA1, 0x02,           /*     Collection Datalink (Logical) */ \
  0x0B, 0x01,0,0x0A,0,  /*       Usage (Ordinals: Instance 1) */ \
  0x0B, 0x02,0,0x0A,0,  /*       Usage (Ordinals: Instance 2) */ \
  0x75, 0x02,           /*        Report Size (2) */ \
  0x95, 0x02,           /*        Report Count (2) */ \
  0x91, 0x02,           /*        Output (Data,Var,Abs) */ \
  0xC0,                 /*     End Collection Datalink (Logical) */ \
  0x16,0xF0,0xD8,       /*     Logical Minimum (-10000) */ \
  0x26,0x10,0x27,       /*     Logical Maximum (10000) */ \
  0x36,0xF0,0xD8,       /*     Physical Minimum (-10000) */ \
  0x46,0x10,0x27,       /*     Physical Maximum (10000) */ \
  0x09, 0x60,           /*     Usage (CP Offset) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x36,0xF0,0xD8,       /*     Physical Minimum (-10000) */ \
  0x46,0x10,0x27,       /*     Physical Maximum (10000) */ \
  0x09, 0x61,           /*     Usage (Positive Coefficient) */ \
  0x09, 0x62,           /*     Usage (Negative Coefficient) */ \
  0x95, 0x02,           /*      Report Count (2) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x16,0x00,0x00,       /*      Logical Minimum (0) */ \
  0x26,0x10,0x27,       /*      Logical Maximum (10000) */ \
  0x36,0x00,0x00,       /*      Physical Minimum (0) */ \
  0x46,0x10,0x27,       /*      Physical Maximum (10000) */ \
  0x09, 0x63,           /*     Usage (Positive Saturation) */ \
  0x09, 0x64,           /*     Usage (Negative Saturation) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x02,           /*      Report Count (2) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x65,           /*     Usage (Dead Band) */ \
  0x46,0x10,0x27,       /*      Physical Maximum (10000) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x6E,           /*   Usage (Set Periodic Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_PRIDREP+TLID,/* Report ID 4 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x70,           /*     Usage (Magnitude) */ \
  0x16, 0x00, 0x00,     /*      Logical Minimum (0) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x36, 0x00, 0x00,     /*      Physical Minimum (0) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x6F,           /*     Usage (Offset) */ \
  0x16, 0xF0, 0xD8,     /*      Logical Minimum (-10000) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x36, 0xF0, 0xD8,     /*      Physical Minimum (-10000) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x71,           /*     Usage (Phase) */ \
  0x66, 0x14, 0x00,     /*      Unit (14h) (Eng Rotation, Degrees) */ \
  0x55, 0xFE,           /*      Unit Exponent (FEh) (X10^-2) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x27, 0x9F, 0x8C,0,0, /*      Logical Maximum (35999) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x47, 0x9F, 0x8C,0,0, /*      Physical Maximum (35999) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x72,           /*     Usage (Period) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x27, 0xFF, 0x7F,0,0, /*      Logical Maximum (32K) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x47, 0xFF, 0x7F,0,0, /*      Physical Maximum (32K) */ \
  0x66, 0x03, 0x10,     /*      Unit (1003h) (English Linear, Seconds) */ \
  0x55, 0xFD,           /*      Unit Exponent (FDh) (X10^-3 ==> Milisecond) */ \
  0x75, 0x20,           /*      Report Size (32) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x66, 0x00, 0x00,     /*     Unit (0) */ \
  0x55, 0x00,           /*     Unit Exponent (0) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x73,           /*   Usage (Set Constant Force Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_CONSTREP+TLID,/* Report ID 5 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x70,           /*     Usage (Magnitude) */ \
  0x16, 0xF0, 0xD8,     /*      Logical Minimum (-10000) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x36, 0xF0, 0xD8,     /*      Physical Minimum (-10000) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x74,           /*   Usage (Set Ramp Force Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_RAMPREP+TLID,/* Report ID 6 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x75,           /*     Usage (Ramp Start) */ \
  0x09, 0x76,           /*     Usage (Ramp End) */ \
  0x16, 0xF0, 0xD8,     /*      Logical Minimum (-10000) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x36, 0xF0, 0xD8,     /*      Physical Minimum (-10000) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x02,           /*      Report Count (2) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x68,           /*   Usage (Custom Force Data Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_CSTMREP+TLID,/* Report ID 7 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x6C,           /*     Usage (Custom Force Data Offset) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x26, 0x10, 0x27,     /*      Logical Maximum (10000) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x69,           /*     Usage (Custom Force Data) */ \
  0x15, 0x81,           /*      Logical Minimum (-127) */ \
  0x25, 0x7F,           /*      Logical Maximum (127) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0xFF, 0x00,     /*      Physical Maximum (255) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x0C,           /*      Report Count (12) */ \
  0x92, 0x02, 0x01,     /*      Output (Variable, Buffered) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x66,           /*   Usage (Download Force Sample) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_SMPLREP+TLID,/* Report ID 8 */ \
  0x05, 0x01,           /*     Usage Page (Generic Desktop) */ \
  0x09, 0x30,           /*       Usage (X) */ \
  0x09, 0x31,           /*       Usage (Y) */ \
  0x15, 0x81,           /*        Logical Minimum (-127) */ \
  0x25, 0x7F,           /*        Logical Maximum (127) */ \
  0x35, 0x00,           /*        Physical Minimum (0) */ \
  0x46, 0xFF, 0x00,     /*        Physical Maximum (255) */ \
  0x75, 0x08,           /*        Report Size (8) */ \
  0x95, 0x02,           /*        Report Count (2) */ \
  0x91, 0x02,           /*        Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x05, 0x0F,           /*   Usage Page (Physical Interface) */ \
  0x09, 0x77,           /*   Usage (Effect Operation Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_EFOPREP+TLID,/* Report ID 10 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x78,           /*     Usage (Effect Operation) */ \
  0xA1, 0x02,           /*     Collection Datalink (Logical) */ \
  0x09, 0x79,           /*       Usage (Op Effect Start) */ \
  0x09, 0x7A,           /*       Usage (Op Effect Start Solo) */ \
  0x09, 0x7B,           /*       Usage (Op Effect Stop) */ \
  0x15, 0x01,           /*        Logical Minimum (1) */ \
  0x25, 0x03,           /*        Logical Maximum (3) */ \
  0x75, 0x08,           /*        Report Size (8) */ \
  0x95, 0x01,           /*        Report Count (1) */ \
  0x91, 0x00,           /*        Output (Data) */ \
  0xC0,                 /*     End Collection Datalink (Logical) */ \
  0x09, 0x7C,           /*     Usage (Loop Count) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*      Logical Maximum (255) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0xFF, 0x00,     /*      Physical Maximum (255) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x90,           /*   Usage (PID Block Free Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_BLKFRREP+TLID,/* Report ID 11 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x96,           /*   Usage (PID Device Control) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_CTRLREP+TLID,/* Report ID 12 */ \
  0x09, 0x97,           /*     Usage (DC Enable Actuators) */ \
  0x09, 0x98,           /*     Usage (DC Disable Actuators) */ \
  0x09, 0x99,           /*     Usage (DC Stop All Effects) */ \
  0x09, 0x9A,           /*     Usage (DC Device Reset) */ \
  0x09, 0x9B,           /*     Usage (DC Device Pause) */ \
  0x09, 0x9C,           /*     Usage (DC Device Continue) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x06,           /*      Logical Maximum (6) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x00,           /*      Output (Data) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x7D,           /*   Usage (Device Gain Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_GAINREP+TLID,/* Report ID 13 */ \
  0x09, 0x7E,           /*     Usage (Device Gain) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*      Logical Maximum (255) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0x10, 0x27,     /*      Physical Maximum (10000) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x6B,           /*   Usage (Set Custom Force Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_SETCREP+TLID,/* Report ID 14 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x6D,           /*     Usage (Sample Count) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x26, 0xFF, 0x00,     /*      Logical Maximum (255) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0xFF, 0x00,     /*      Physical Maximum (255) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x09, 0x51,           /*     Usage (Sample Period) */ \
  0x66, 0x03, 0x10,     /*      Unit 4099 */ \
  0x55, 0xFD,           /*      Unit (Exponent 253) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x26, 0xFF, 0x7F,     /*      Logical Maximum (32767) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x46, 0xFF, 0x7F,     /*      Physical Maximum (32767) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x91, 0x02,           /*      Output (Data,Var,Abs) */ \
  0x55, 0x00,           /*      Unit (Exponent 0) */ \
  0x66, 0x00, 0x00,     /*      Unit 0 */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0xAB,           /*   Usage (Create New Effect Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_NEWEFREP+TLID,/* Report ID 1 */ \
  0x09, 0x25,           /*      Usage (Effect Type) */ \
  0xA1, 0x02,           /*      Collection Datalink (Logical) */ \
  0x09, HID_USAGE_CONST,/*        Usage (ET Constant Force) */ \
  0x09, HID_USAGE_RAMP, /*        Usage (ET Ramp) */ \
  0x09, HID_USAGE_SQUR, /*        Usage (ET Square) */ \
  0x09, HID_USAGE_SINE, /*        Usage (ET Sine) */ \
  0x09, HID_USAGE_TRNG, /*        Usage (ET Triangle) */ \
  0x09, HID_USAGE_STUP, /*        Usage (ET Sawtooth Up) */ \
  0x09, HID_USAGE_STDN, /*        Usage (ET Sawtooth Down) */ \
  0x09, HID_USAGE_SPRNG,/*        Usage (ET Spring) */ \
  0x09, HID_USAGE_DMPR, /*        Usage (ET Damper) */ \
  0x09, HID_USAGE_INRT, /*        Usage (ET Inertia) */ \
  0x09, HID_USAGE_FRIC, /*        Usage (ET Friction) */ \
  0x09, 0x28,           /*        Usage (ET Custom Force Data) */ \
  0x15, 0x01,           /*         Logical Minimum (1) */ \
  0x25, 0x0C,           /*         Logical Maximum (12) */ \
  0x35, 0x01,           /*         Physical Minimum (1) */ \
  0x45, 0x0C,           /*         Physical Maximum (12) */ \
  0x75, 0x08,           /*         Report Size (8) */ \
  0x95, 0x01,           /*         Report Count (1) */ \
  0xB1, 0x00,           /*         Feature */ \
  0xC0,                 /*      End Collection Datalink (Logical) */ \
  0x05, 0x01,           /*      Usage Page (Generic Desktop) */ \
  0x09, 0x3B,           /*      Usage (Reserved) */ \
  0x15, 0x00,           /*       Logical Minimum (0) */ \
  0x26, 0xFF, 0x01,     /*       Logical Maximum (511) */ \
  0x35, 0x00,           /*       Physical Minimum (0) */ \
  0x46, 0xFF, 0x01,     /*       Physical Maximum (511) */ \
  0x75, 0x0A,           /*       Report Size (10) */ \
  0x95, 0x01,           /*       Report Count (1) */ \
  0xB1, 0x02,           /*       Feature (Variable) */ \
  0x75, 0x06,           /*       Report Size (6) */ \
  0xB1, 0x01,           /*       Feature (Constant) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x05, 0x0F,           /*   Usage Page (Physical Interface) */ \
  0x09, 0x89,           /*   Usage (Block Load Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_BLKLDREP+TLID,/* Report ID 2 */ \
  0x09, 0x22,           /*     Usage (Effect Block Index) */ \
  0x15, 0x01,           /*      Logical Minimum (1) */ \
  0x25, 0x28,           /*      Logical Maximum (40) */ \
  0x35, 0x01,           /*      Physical Minimum (1) */ \
  0x45, 0x28,           /*      Physical Maximum (40) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0xB1, 0x02,           /*      Feature (Variable) */ \
  0x09, 0x8B,           /*     Usage (Block Load Status) */ \
  0xA1, 0x02,           /*     Collection Datalink (Logical) */ \
  0x09, 0x8C,           /*       Usage (Block Load Success) */ \
  0x09, 0x8D,           /*       Usage (Block Load Full) */ \
  0x09, 0x8E,           /*       Usage (Block Load Error) */ \
  0x15, 0x01,           /*        Logical Minimum (1) */ \
  0x25, 0x03,           /*        Logical Maximum (3) */ \
  0x35, 0x01,           /*        Physical Minimum (1) */ \
  0x45, 0x03,           /*        Physical Maximum (3) */ \
  0x75, 0x08,           /*        Report Size (8) */ \
  0x95, 0x01,           /*        Report Count (1) */ \
  0xB1, 0x00,           /*        Feature */ \
  0xC0,                 /*     End Collection Datalink (Logical) */ \
  0x09, 0xAC,           /*     Usage (Undefined) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x27, 0xFF, 0xFF,0,0, /*      Logical Maximum (65535) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x47, 0xFF, 0xFF,0,0, /*      Physical Maximum (65535) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0xB1, 0x00,           /*      Feature */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ \
  \
  0x09, 0x7F,           /*   Usage (PID Pool Report) */ \
  0xA1, 0x02,           /*   Collection Datalink (Logical) */ \
  0x85, HID_ID_POOLREP+TLID,/* Report ID 3 */ \
  0x09, 0x80,           /*     Usage (RAM Pool size) */ \
  0x75, 0x10,           /*      Report Size (16) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x27, 0xFF, 0xFF,0,0, /*      Logical Maximum (65535) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x47, 0xFF, 0xFF,0,0, /*      Physical Maximum (65535) */ \
  0xB1, 0x02,           /*      Feature (Variable) */ \
  0x09, 0x83,           /*     Usage (Simultaneous Effects Max) */ \
  0x26, 0xFF, 0x00,     /*      Logical Maximum (255) */ \
  0x46, 0xFF, 0x00,     /*      Physical Maximum (255) */ \
  0x75, 0x08,           /*      Report Size (8) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0xB1, 0x02,           /*      Feature (Variable) */ \
  0x09, 0xA9,           /*     Usage (Device Managed Pool) */ \
  0x09, 0xAA,           /*     Usage (Shared Parameter Blocks) */ \
  0x75, 0x01,           /*      Report Size (1) */ \
  0x95, 0x02,           /*      Report Count (2) */ \
  0x15, 0x00,           /*      Logical Minimum (0) */ \
  0x25, 0x01,           /*      Logical Maximum (1) */ \
  0x35, 0x00,           /*      Physical Minimum (0) */ \
  0x45, 0x01,           /*      Physical Maximum (1) */ \
  0xB1, 0x02,           /*      Feature (Variable) */ \
  0x75, 0x06,           /*      Report Size (6) */ \
  0x95, 0x01,           /*      Report Count (1) */ \
  0xB1, 0x03,           /*      Feature (Constant, Variable) */ \
  0xC0,                 /*   End Collection Datalink (Logical) (OK) */ 


#define HID_SIMPLE_REPORT_DESCRIPTOR(...) \
  0x05, 0x01,           /* Usage Page (Generic Desktop) */ \
  0x09, 0x04,           /* Usage (Joystick) */ \
  0xA1, 0x01,           /* Collection (Application) */ \
  0x85, TLID,           /* REPORT_ID 1 */ \
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
  HID_FFB_DESC()  \
  \
  0xC0                  /* End Collection (Application) */
  
