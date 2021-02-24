#include <Arduino.h>
#include <USBComposite.h>

#include "FFBdesc.h"
#include "FFBenum.h"

// =====================================================================

enum {
  // INPUT
  JOYSTICK=0,         // id=1
  PID_STATE,          // id=2
  // OUTPUT
  SET_EFFECT,         // id=1
  SET_ENVELOPE,       // id=2
  SET_CONDITION,      // id=3
  SET_PERIODIC,       // id=4
  SET_CONSTANT_FORCE, // id=5
  SET_RAMP_FORCE,     // id=6
  CUSTOM_FORCE_DATA,  // id=7
  DOWNLOAD_FORCE,     // id=8
  EFFECT_OPERATION,   // id=10
  PID_BLOCK_FREE,     // id=11
  PID_DEVICE_CONTROL, // id=12
  DEVICE_GAIN,        // id=13
  SET_CUSTOM_FORCE,   // id=14
  // FEATURE
  CREATE_NEW_EFFECT,  // id=1
  BLOCK_LOAD,         // id=2
  PID_POOL,           // id=3
  // COUNT
  REPORTS_COUNT
} reports_e;

class HID_Joystick {
  
  protected :

    USBHID*               HID;

    HIDReporter           reporter[REPORTS_COUNT];
    HIDBuffer_t           buffer[REPORTS_COUNT];

    struct {
      // INPUT
      struct {
        ReportJoy_t              Joystick;
        ReportStatePID_t         StatePID;
      } input;
      // OUTPUT
      struct {
        ReportSetEffect_t        SetEffect;
        ReportSetEnvelope_t      SetEnvelope;
        ReportSetCondition_t     SetCondition;
        ReportSetPeriodic_t      SetPeriodic;
        ReportSetConstantForce_t SetConstantForce;
        ReportSetRampForce_t     SetRampForce;
        ReportCustomForceData_t  CustomForceData;
        ReportDownloadForce_t    DownloadForce;
        ReportEffectOperation_t  EffectOperation;
        ReportBlockFree_t        BlockFree;
        ReportDeviceControl_t    DeviceControl;
        ReportDeviceGain_t       DeviceGain;
        ReportSetCustomForce_t   SetCustomForce;
      } output;
      // FEATURE
      struct {
        ReportNewEffect_t        NewEffect;
        ReportLoadPID_t          BlockLoad;
        ReportPoolPID_t          PoolPID;
      } feature;
    } data;
    
    volatile uint8_t bufSetEffect[HID_BUFFER_ALLOCATE_SIZE(SIZE_EFFREP,1)]          = {0};
    volatile uint8_t bufSetEnvelope[HID_BUFFER_ALLOCATE_SIZE(SIZE_ENVREP,1)]        = {0};
    volatile uint8_t bufSetCondition[HID_BUFFER_ALLOCATE_SIZE(SIZE_CONDREP,1)]      = {0};
    volatile uint8_t bufSetPeriodic[HID_BUFFER_ALLOCATE_SIZE(SIZE_PRIDREP,1)]       = {0};
    volatile uint8_t bufSetConstantForce[HID_BUFFER_ALLOCATE_SIZE(SIZE_CONSTREP,1)] = {0};
    volatile uint8_t bufSetRampForce[HID_BUFFER_ALLOCATE_SIZE(SIZE_RAMPREP,1)]      = {0};
    volatile uint8_t bufDeviceControl[HID_BUFFER_ALLOCATE_SIZE(SIZE_CTRLREP,1)]     = {0};
    volatile uint8_t bufDeviceGain[HID_BUFFER_ALLOCATE_SIZE(SIZE_GAINREP,1)]        = {0};
    
    volatile uint8_t bufNewEffect[HID_BUFFER_ALLOCATE_SIZE(SIZE_NEWEFREP,1)]        = {0};
    volatile uint8_t bufBlockLoad[HID_BUFFER_ALLOCATE_SIZE(SIZE_BLKLDREP,1)]        = {0};
    volatile uint8_t bufPoolPID[HID_BUFFER_ALLOCATE_SIZE(SIZE_POOLREP,1)]           = {0};
    
    bool manualReport = false;

    inline void safeSendReportJoy(void) {
      if(!manualReport) reporter[JOYSTICK].sendReport();
    }

  private :

    uint8_t printBuf(volatile uint8_t* data, uint8_t size) {
      for(uint8_t i=0; i<size; i++) {
        CompositeSerial.print(data[i], HEX);
        CompositeSerial.print(" ");
      }
      CompositeSerial.println();
    }

  public :
  
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
    
    HID_Joystick(USBHID* _HID) : 
      HID(_HID),
      reporter({
        (*_HID, (uint8_t*)&data.input.Joystick,       sizeof(data.input.Joystick),       TLID),
        (*_HID, (uint8_t*)&data.input.StatePID,       sizeof(data.input.StatePID),       TLID+HID_ID_STATE)
      })
//      // INPUT reporters
//      reporter[JOYSTICK]          (*_HID, (uint8_t*)&data.input.Joystick,       sizeof(data.input.Joystick),       TLID),
//      reporter[PID_STATE]         (*_HID, (uint8_t*)&data.input.StatePID,       sizeof(data.input.StatePID),       TLID+HID_ID_STATE),
      // OUTPUT reporters
//      reporter[PID_DEVICE_CONTROL](*_HID, (uint8_t*)&data.output.DeviceControl, sizeof(data.output.DeviceControl), TLID+HID_ID_CTRLREP),
//      reporter[DEVICE_GAIN]       (*_HID, (uint8_t*)&data.output.DeviceGain,    sizeof(data.output.DeviceGain),    TLID+HID_ID_GAINREP),
//      // FEATURE reporters
//      reporter[CREATE_NEW_EFFECT] (*_HID, (uint8_t*)&data.feature.NewEffect,    sizeof(data.feature.NewEffect),    TLID+HID_ID_NEWEFREP),
//      reporter[BLOCK_LOAD]        (*_HID, (uint8_t*)&data.feature.BlockLoad,    sizeof(data.feature.BlockLoad),    TLID+HID_ID_BLKLDREP),
//      reporter[PID_POOL]          (*_HID, (uint8_t*)&data.feature.PoolPID,      sizeof(data.feature.PoolPID),      TLID+HID_ID_POOLREP),
//      // OUTPUT buffers
//      buffer[SET_EFFECT]        (bufSetEffect,        HID_BUFFER_SIZE(SIZE_EFFREP,  1), TLID+HID_ID_EFFREP,   HID_BUFFER_MODE_NO_WAIT),
//      buffer[SET_ENVELOPE]      (bufSetEnvelope,      HID_BUFFER_SIZE(SIZE_ENVREP,  1), TLID+HID_ID_ENVREP,   HID_BUFFER_MODE_NO_WAIT),
//      buffer[SET_CONDITION]     (bufSetCondition,     HID_BUFFER_SIZE(SIZE_CONDREP, 1), TLID+HID_ID_CONDREP,  HID_BUFFER_MODE_NO_WAIT),
//      buffer[SET_PERIODIC]      (bufSetPeriodic,      HID_BUFFER_SIZE(SIZE_PRIDREP, 1), TLID+HID_ID_PRIDREP,  HID_BUFFER_MODE_NO_WAIT),
//      buffer[SET_CONSTANT_FORCE](bufSetConstantForce, HID_BUFFER_SIZE(SIZE_CONSTREP,1), TLID+HID_ID_CONSTREP, HID_BUFFER_MODE_NO_WAIT),
//      buffer[SET_RAMP_FORCE]    (bufSetRampForce,     HID_BUFFER_SIZE(SIZE_RAMPREP, 1), TLID+HID_ID_RAMPREP,  HID_BUFFER_MODE_NO_WAIT),
//      buffer[PID_DEVICE_CONTROL](bufDeviceControl,    HID_BUFFER_SIZE(SIZE_CTRLREP, 1), TLID+HID_ID_CTRLREP,  HID_BUFFER_MODE_NO_WAIT),
//      buffer[DEVICE_GAIN]       (bufDeviceGain,       HID_BUFFER_SIZE(SIZE_GAINREP, 1), TLID+HID_ID_GAINREP,  HID_BUFFER_MODE_NO_WAIT),
//      // FEATURE buffers
//      buffer[CREATE_NEW_EFFECT] (bufNewEffect,        HID_BUFFER_SIZE(SIZE_NEWEFREP,1), TLID+HID_ID_NEWEFREP, HID_BUFFER_MODE_NO_WAIT),
//      buffer[BLOCK_LOAD]        (bufBlockLoad,        HID_BUFFER_SIZE(SIZE_BLKLDREP,1), TLID+HID_ID_BLKLDREP, HID_BUFFER_MODE_NO_WAIT),
//      buffer[PID_POOL]          (bufPoolPID,          HID_BUFFER_SIZE(SIZE_POOLREP, 1), TLID+HID_ID_POOLREP,  HID_BUFFER_MODE_NO_WAIT)
      {
          //
          data.input.Joystick.buttons     = 0;
          data.input.Joystick.hat         = 255;
          data.input.Joystick.rx          = 32767;
          data.input.Joystick.ry          = 32767;
          data.input.Joystick.sliderLeft  = 0;
          data.input.Joystick.sliderRight = 0;
          data.input.Joystick.steering    = 127;
          data.input.Joystick.accelerator = 0;
          data.input.Joystick.throttle    = 0;
          data.input.Joystick.brake       = 0;
          data.input.Joystick.shifter     = 0;
          data.input.Joystick.clutch      = 0;
          //
          data.input.StatePID.deviceIsPaused         = false;
          data.input.StatePID.actuatorEnabled        = false;
          data.input.StatePID.safetySwitch           = false;
          data.input.StatePID.actuatorOverrideSwitch = false;
          data.input.StatePID.actuatorPower          = false;
          data.input.StatePID.effectPlaying          = false;
          data.input.StatePID.effectBlockIndex       = 1;
          data.input.StatePID.padding                = 0;
          //
      }
      
      void begin(void) {
        // add OUTPUT buffers
        HID->addOutputBuffer(&buffer[SET_EFFECT]);
        HID->addOutputBuffer(&buffer[SET_ENVELOPE]);
        HID->addOutputBuffer(&buffer[SET_CONDITION]);
        HID->addOutputBuffer(&buffer[SET_PERIODIC]);
        HID->addOutputBuffer(&buffer[SET_CONSTANT_FORCE]);
        HID->addOutputBuffer(&buffer[SET_RAMP_FORCE]);
        HID->addOutputBuffer(&buffer[PID_DEVICE_CONTROL]);
        HID->addOutputBuffer(&buffer[DEVICE_GAIN]);
        // add FEATURE buffers
        HID->addFeatureBuffer(&buffer[CREATE_NEW_EFFECT]);
        HID->addFeatureBuffer(&buffer[BLOCK_LOAD]);
        HID->addFeatureBuffer(&buffer[PID_POOL]);

        data.feature.NewEffect.effectType = 1;
        data.feature.NewEffect.byteCount  = 1;
        
        data.feature.BlockLoad.effectBlockIndex = 1;
        data.feature.BlockLoad.loadStatus       = 1;
        data.feature.BlockLoad.ramPoolAvailable = 1;
        
        data.feature.PoolPID.ramPoolSize             = 0xFFFF;
        data.feature.PoolPID.maxSimultaneousEffects  = 0x0A; // FFP supports playing up to 10 simultaneous effects
        data.feature.PoolPID.memoryManagement        = 3;

        reporter[CREATE_NEW_EFFECT].setFeature((uint8_t*)&data.feature.NewEffect);
        reporter[BLOCK_LOAD].setFeature((uint8_t*)&data.feature.BlockLoad);
        reporter[PID_POOL].setFeature((uint8_t*)&data.feature.PoolPID);
        
      }
      
      void end(void) {}
      
      inline void send(void) {
          reporter[JOYSTICK].sendReport();
      }
      
      inline void setManualReportMode(bool mode) {
        manualReport = mode;
      }
      
      inline bool getManualReportMode() {
        return manualReport;
      }

      void handleINPUT()
      {
        
      }

      void handleOUTPUT()
      {
          if(reporter[SET_EFFECT].getOutput((uint8_t*)&data.output.SetEffect)) {
            CompositeSerial.println("getOutput(SET_EFFECT)");
          }
          if(reporter[SET_ENVELOPE].getOutput((uint8_t*)&data.output.SetEnvelope)) {
            CompositeSerial.println("getOutput(SET_ENVELOPE)");
          }
          if(reporter[SET_CONDITION].getOutput((uint8_t*)&data.output.SetCondition)) {
            CompositeSerial.println("getOutput(SET_CONDITION)");
          }
          if(reporter[SET_PERIODIC].getOutput((uint8_t*)&data.output.SetPeriodic)) {
            CompositeSerial.println("getOutput(SET_PERIODIC)");
          }
          if(reporter[SET_CONSTANT_FORCE].getOutput((uint8_t*)&data.output.SetConstantForce)) {
            CompositeSerial.println("getOutput(SET_CONSTANT_FORCE)");
          }
          if(reporter[SET_RAMP_FORCE].getOutput((uint8_t*)&data.output.SetRampForce)) {
            CompositeSerial.println("getOutput(SET_RAMP_FORCE)");
          }
          if(reporter[CUSTOM_FORCE_DATA].getOutput((uint8_t*)&data.output.CustomForceData)) {
            CompositeSerial.println("getOutput(CUSTOM_FORCE_DATA)");
          }
          if(reporter[DOWNLOAD_FORCE].getOutput((uint8_t*)&data.output.DownloadForce)) {
            CompositeSerial.println("getOutput(DOWNLOAD_FORCE)");
          }
          if(reporter[EFFECT_OPERATION].getOutput((uint8_t*)&data.output.EffectOperation)) {
            CompositeSerial.println("getOutput(EFFECT_OPERATION)");
          }
          if(reporter[PID_BLOCK_FREE].getOutput((uint8_t*)&data.output.BlockFree)) {
            CompositeSerial.println("getOutput(PID_BLOCK_FREE)");
          }
          if(reporter[PID_DEVICE_CONTROL].getOutput((uint8_t*)&data.output.DeviceControl)) {
            CompositeSerial.println("getOutput(PID_DEVICE_CONTROL)");
          }
          if(reporter[DEVICE_GAIN].getOutput((uint8_t*)&data.output.DeviceGain)) {
            CompositeSerial.println("getOutput(DEVICE_GAIN)");
          }
          if(reporter[SET_CUSTOM_FORCE].getOutput((uint8_t*)&data.output.SetCustomForce)) {
            CompositeSerial.println("getOutput(SET_CUSTOM_FORCE)");
          }
      }

      void handleFEATURE()
      {
          if(reporter[CREATE_NEW_EFFECT].getFeature((uint8_t*)&data.feature.NewEffect)) {
            CompositeSerial.println("getFature(CREATE_NEW_EFFECT)");
          }
          if(reporter[BLOCK_LOAD].getFeature((uint8_t*)&data.feature.BlockLoad)) {
            CompositeSerial.println("getFature(BLOCK_LOAD)");
          }
          if(reporter[PID_POOL].getFeature((uint8_t*)&data.feature.PoolPID)) {
            CompositeSerial.println("getFature(PID_POOL)");
          }
      }

      void test() {
        
          handleINPUT();
          handleOUTPUT();
          handleFEATURE();
                    
      }

};

