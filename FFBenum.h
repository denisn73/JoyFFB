
// INPUT reports data structs definition -----------------------------

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
} __packed ReportJoy_t;

typedef struct {                         // FFB: PID State Input Report
    uint8_t  reportID;                   // = 2
    uint8_t  deviceIsPaused         : 1; // 
    uint8_t  actuatorEnabled        : 1; // 
    uint8_t  safetySwitch           : 1; // 
    uint8_t  actuatorOverrideSwitch : 1; // 
    uint8_t  actuatorPower          : 1; // 
    uint8_t  padding                : 3; // 
    uint8_t  effectPlaying          : 1; // 
    uint8_t  effectBlockIndex       : 7; // 
} __packed ReportStatePID_t;

// OUTPUT reports data structs definition ----------------------------

typedef struct {                   // FFB: Set Effect Output Report
  uint8_t  reportId;               // = 1
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  effectType;             // 1..12 (effect usages: 26,27,30,31,32,33,34,40,41,42,43,28)
  uint16_t duration;               // 0..32767 ms
  uint16_t triggerRepeatInterval;  // 0..32767 ms
  uint16_t samplePeriod;           // 0..32767 ms
  uint8_t  gain;                   // 0..255  (physical 0..10000)
  uint8_t  triggerButton;          // button ID (0..8)
  uint8_t  enableAxis;             // bits: 0=X, 1=Y, 2=DirectionEnable
  uint8_t  directionX;             // angle (0=0 .. 255=360deg)
  uint8_t  directionY;             // angle (0=0 .. 255=360deg)
} __packed ReportSetEffect_t;

typedef struct {                   // FFB: Set Envelope Output Report
  uint8_t  reportId;               // = 2
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  attackLevel;            // 
  uint8_t  fadeLevel;              // 
  uint16_t attackTime;             // ms
  uint16_t fadeTime;               // ms
} __packed ReportSetEnvelope_t;

typedef struct {                   // FFB: Set Condition Output Report
  uint8_t  reportId;               // = 3
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  parameterBlockOffset;   // bits: 0..3=parameterBlockOffset, 4..5=instance1, 6..7=instance2
  uint16_t cpOffset;               // 0..255
  int16_t  positiveCoefficient;    // -128..127
  int16_t  negativeCoefficient;    // -128..127
  int16_t  positiveSaturation;     // -128..127
  int16_t  negativeSaturation;     // -128..127
  uint16_t deadBand;               // 0..255
} __packed ReportSetCondition_t;

typedef struct {                   // FFB: Set Periodic Output Report
  uint8_t  reportId;               // = 4
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  magnitude;              // 
  int8_t   offset;                 // 
  uint8_t  phase;                  // 0..255 (=0..359, exp-2)
  uint16_t period;                 // 0..32767 ms
} __packed ReportSetPeriodic_t;

typedef struct {                   // FFB: Set ConstantForce Output Report
  uint8_t  reportId;               // = 5
  uint8_t  effectBlockIndex;       // 1..40
  int16_t  magnitude;              // -255..255
} __packed ReportSetConstantForce_t;

typedef struct {                   // FFB: Set RampForce Output Report
  uint8_t  reportId;               // = 6
  uint8_t  effectBlockIndex;       // 1..40
  int8_t   start;                  // 
  int8_t   end;                    // 
} __packed ReportSetRampForce_t;

typedef struct {                   // FFB: Set CustomForceData Output Report
  uint8_t  reportId;               // = 7
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  dataOffset;             // 
  int8_t   data[12];               // 
} __packed ReportCustomForceData_t;

typedef struct {                   // FFB: Set DownloadForceSample Output Report
  uint8_t  reportId;               // = 8
  int8_t   x;                      // 
  int8_t   y;                      // 
} __packed ReportDownloadForce_t;

typedef struct {                   // FFB: Set EffectOperation Output Report
  uint8_t  reportId;               // = 10
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  operation;              // 1=Start, 2=StartSolo, 3=Stop
  uint8_t  loopCount;              //
} __packed ReportEffectOperation_t;

typedef struct {                   // FFB: Block Free Output Report
  uint8_t  reportId;               // = 11
  uint8_t  effectBlockIndex;       // 1..40
} __packed ReportBlockFree_t;

typedef struct {                   // FFB: Device Control Output Report
  uint8_t  reportId;               // = 12
  uint8_t  control;                // 1=Enable Actuators, 2=Disable Actuators, 4=Stop All Effects, 8=Reset, 16=Pause, 32=Continue
} __packed ReportDeviceControl_t;

typedef struct {                   // FFB: DeviceGain Output Report
  uint8_t  reportId;               // = 13
  uint8_t  gain;                   // 
} __packed ReportDeviceGain_t;

typedef struct {                   // FFB: Set Custom Force Output Report
  uint8_t  reportId;               // = 14
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  sampleCount;            //
  uint16_t samplePeriod;           // 0..32767 ms
} __packed ReportSetCustomForce_t;

// FEATURE reports data structs definition ----------------------------

typedef struct {                   // FFB: Create New Effect Feature Report
  uint8_t  reportId;               // = 1
  uint8_t  effectType;             // Enum (1..12): ET 26,27,30,31,32,33,34,40,41,42,43,28
  uint16_t byteCount;              // 0..511
} __packed ReportNewEffect_t;

typedef struct {                   // FFB: PID Block Load Feature Report
  uint8_t  reportId;               // = 2
  uint8_t  effectBlockIndex;       // 1..40
  uint8_t  loadStatus;             // 1=Success,2=Full,3=Error
  uint16_t ramPoolAvailable;       // =0 or 0xFFFF?
} __packed ReportLoadPID_t;

typedef struct {                   // FFB: PID Pool Feature Report
  //uint8_t  reportId;               // = 3
  uint16_t ramPoolSize;            // 
  uint8_t  maxSimultaneousEffects; // 
  uint8_t  memoryManagement;       // Bits: 0=DeviceManagedPool, 1=SharedParameterBlocks
} __packed ReportPoolPID_t;

// Sizes of reports --------------------------------------------------

// OUTPUT data size
#define SIZE_EFFREP       17
#define SIZE_ENVREP        7
#define SIZE_CONDREP      12
#define SIZE_PRIDREP       9
#define SIZE_CONSTREP      3
#define SIZE_RAMPREP       3
#define SIZE_CSTMREP      15
#define SIZE_SMPLREP       2
#define SIZE_EFOPREP       3
#define SIZE_BLKFRREP      1
#define SIZE_CTRLREP       1
#define SIZE_GAINREP       1
#define SIZE_SETCREP      14

// FEATURE data size
#define SIZE_NEWEFREP      3
#define SIZE_BLKLDREP      4
#define SIZE_POOLREP       4

// EFFECT types enumeration ------------------------------------------

#define FFB_EFFECT_CONSTANT     0x01
#define FFB_EFFECT_RAMP         0x02
#define FFB_EFFECT_SQUARE       0x03
#define FFB_EFFECT_SINE         0x04
#define FFB_EFFECT_TRIANGLE     0x05
#define FFB_EFFECT_SAWTOOTHDOWN 0x06
#define FFB_EFFECT_SAWTOOTHUP   0x07
#define FFB_EFFECT_SPRING       0x08
#define FFB_EFFECT_DAMPER       0x09
#define FFB_EFFECT_INERTIA      0x0A
#define FFB_EFFECT_FRICTION     0x0B
#define FFB_EFFECT_CUSTOM       0x0C

