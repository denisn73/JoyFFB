#include <USBComposite.h>

#include "FFBdesc.h"
#include "FFBenum.h"

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


// =====================================================================

class HID_Joystick {
  
  protected :

    USBHID*           HID;

    HIDReporter       reporterJoy;
    HIDReporter       reporterStatePID;
    
    HIDReporter       reporterNewEffect;
    HIDReporter       reporterPoolPID;
    HIDReporter       reporterLoadPID;

    // INPUT
    ReportJoy_t       reportJoy;
    ReportStatePID_t  reportStatePID;

    // FEATURE
    ReportNewEffect_t reportNewEffect;
    ReportLoadPID_t   reportLoadPID;
    ReportPoolPID_t   reportPoolPID;

    // OUTPUT
    HIDBuffer_t       dataSetEffect;
    HIDBuffer_t       dataSetEnvelope;
    HIDBuffer_t       dataSetCondition;
    HIDBuffer_t       dataSetPeriodic;
    HIDBuffer_t       dataSetConstantForce;
    HIDBuffer_t       dataSetRampForce;
    HIDBuffer_t       dataDeviceControl;
    HIDBuffer_t       dataDeviceGain;

    // FEATURE
    HIDBuffer_t       dataNewEffect;
    HIDBuffer_t       dataBlockLoad;
    HIDBuffer_t       dataPoolPID;
    
    volatile uint8_t bufSetEffect[HID_BUFFER_ALLOCATE_SIZE(SIZE_EFFREP,1)]          = {0};
    volatile uint8_t bufSetEnvelope[HID_BUFFER_ALLOCATE_SIZE(SIZE_ENVREP,1)]        = {0};
    volatile uint8_t bufSetCondition[HID_BUFFER_ALLOCATE_SIZE(SIZE_CONDREP,1)]      = {0};
    volatile uint8_t bufSetPeriodic[HID_BUFFER_ALLOCATE_SIZE(SIZE_PRIDREP,1)]       = {0};
    volatile uint8_t bufSetConstantForce[HID_BUFFER_ALLOCATE_SIZE(SIZE_CONSTREP,1)] = {0};
    volatile uint8_t bufSetRampForce[HID_BUFFER_ALLOCATE_SIZE(SIZE_RAMPREP,1)]      = {0};
    volatile uint8_t bufDeviceControl[HID_BUFFER_ALLOCATE_SIZE(SIZE_CTRLREP,1)]     = {0};
    volatile uint8_t bufDeviceGain[HID_BUFFER_ALLOCATE_SIZE(SIZE_GAINREP,1)]        = {0};
    
    volatile uint8_t bufNewEffect[HID_BUFFER_ALLOCATE_SIZE(SIZE_NEWEFREP,1)];
    volatile uint8_t bufBlockLoad[HID_BUFFER_ALLOCATE_SIZE(SIZE_BLKLDREP,1)];
    volatile uint8_t bufPoolPID[HID_BUFFER_ALLOCATE_SIZE(SIZE_POOLREP,1)];
    
    bool manualReport = false;

    inline void safeSendReportJoy(void) {
      if(!manualReport) reporterJoy.sendReport();
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
    
    uint8_t printBufSetEffect() {
      CompositeSerial.print("[Buf] Set Effect:\t");
      this->printBuf(bufSetEffect, sizeof(bufSetEffect));
    }
    
    uint8_t printBufSetEnvelope() {
      CompositeSerial.print("[Buf] Set Envelope:\t");
      this->printBuf(bufSetEnvelope, sizeof(bufSetEnvelope));
    }
    
    uint8_t printBufSetCondition() {
      CompositeSerial.print("[Buf] Set Condition:\t");
      this->printBuf(bufSetCondition, sizeof(bufSetCondition));
    }
    
    uint8_t printBufSetPeriodic() {
      CompositeSerial.print("[Buf] Set Periodic:\t");
      this->printBuf(bufSetPeriodic, sizeof(bufSetPeriodic));
    }
    
    uint8_t printBufSetConstantForce() {
      CompositeSerial.print("[Buf] Set ConstForce:\t");
      this->printBuf(bufSetConstantForce, sizeof(bufSetConstantForce));
    }
    
    uint8_t printBufSetRampForce() {
      CompositeSerial.print("[Buf] Set RampForce:\t");
      this->printBuf(bufSetRampForce, sizeof(bufSetRampForce));
    }
    
    uint8_t printBufDeviceControl() {
      CompositeSerial.print("[Buf] DeviceCtrl:  \t");
      this->printBuf(bufDeviceControl, sizeof(bufDeviceControl));
    }
    
    uint8_t printBufDeviceGain() {
      CompositeSerial.print("[Buf] DeviceGain:  \t");
      this->printBuf(bufDeviceGain, sizeof(bufDeviceGain));
    }
    
    uint8_t printBufNewEffect() {
      CompositeSerial.print("[Buf] New Effect:\t");
      this->printBuf(bufNewEffect, sizeof(bufNewEffect));
    }
    
    uint8_t printBufBlockLoad() {
      CompositeSerial.print("[Buf] Block Load:\t");
      this->printBuf(bufBlockLoad, sizeof(bufBlockLoad));
    }
    
    uint8_t printBufPoolPID() {
      CompositeSerial.print("[Buf] Pool PID:  \t");
      this->printBuf(bufPoolPID, sizeof(bufPoolPID));
    }
    
    HID_Joystick(USBHID* _HID) : 
      HID(_HID),
      // INPUT reporters
      reporterJoy     (*_HID, (uint8_t*)&reportJoy,       sizeof(reportJoy),       TLID),
      reporterStatePID(*_HID, (uint8_t*)&reportStatePID,  sizeof(reportStatePID),  TLID+HID_ID_STATE),
      // FEATURE reporters
      reporterNewEffect(*_HID, (uint8_t*)&reportNewEffect, sizeof(reportNewEffect), TLID+HID_ID_NEWEFREP),
      reporterLoadPID  (*_HID, (uint8_t*)&reportLoadPID,   sizeof(reportLoadPID),   TLID+HID_ID_BLKLDREP),
      reporterPoolPID  (*_HID, (uint8_t*)&reportPoolPID,   sizeof(reportPoolPID),   TLID+HID_ID_POOLREP),
      // OUTPUT buffers
      dataSetEffect       (bufSetEffect,        HID_BUFFER_SIZE(SIZE_EFFREP,1),   TLID+HID_ID_EFFREP,   HID_BUFFER_MODE_NO_WAIT),
      dataSetEnvelope     (bufSetEnvelope,      HID_BUFFER_SIZE(SIZE_ENVREP,1),   TLID+HID_ID_ENVREP,   HID_BUFFER_MODE_NO_WAIT),
      dataSetCondition    (bufSetCondition,     HID_BUFFER_SIZE(SIZE_CONDREP,1),  TLID+HID_ID_CONDREP,  HID_BUFFER_MODE_NO_WAIT),
      dataSetPeriodic     (bufSetPeriodic,      HID_BUFFER_SIZE(SIZE_PRIDREP,1),  TLID+HID_ID_PRIDREP,  HID_BUFFER_MODE_NO_WAIT),
      dataSetConstantForce(bufSetConstantForce, HID_BUFFER_SIZE(SIZE_CONSTREP,1), TLID+HID_ID_CONSTREP, HID_BUFFER_MODE_NO_WAIT),
      dataSetRampForce    (bufSetRampForce,     HID_BUFFER_SIZE(SIZE_RAMPREP,1),  TLID+HID_ID_RAMPREP,  HID_BUFFER_MODE_NO_WAIT),
      dataDeviceControl   (bufDeviceControl,    HID_BUFFER_SIZE(SIZE_CTRLREP,1),  TLID+HID_ID_CTRLREP,  HID_BUFFER_MODE_NO_WAIT),
      dataDeviceGain      (bufDeviceGain,       HID_BUFFER_SIZE(SIZE_GAINREP,1),  TLID+HID_ID_GAINREP,  HID_BUFFER_MODE_NO_WAIT),
      // FEATURE buffers
      dataNewEffect (bufNewEffect, HID_BUFFER_SIZE(SIZE_NEWEFREP,1), TLID+HID_ID_NEWEFREP, HID_BUFFER_MODE_NO_WAIT),
      dataBlockLoad (bufBlockLoad, HID_BUFFER_SIZE(SIZE_BLKLDREP,1), TLID+HID_ID_BLKLDREP, HID_BUFFER_MODE_NO_WAIT),
      dataPoolPID   (bufPoolPID,   HID_BUFFER_SIZE(SIZE_POOLREP,1),  TLID+HID_ID_POOLREP,  HID_BUFFER_MODE_NO_WAIT)
      {
          //
          reportJoy.buttons     = 0;
          reportJoy.hat         = 255;
          reportJoy.rx          = 32767;
          reportJoy.ry          = 32767;
          reportJoy.sliderLeft  = 0;
          reportJoy.sliderRight = 0;
          reportJoy.steering    = 127;
          reportJoy.accelerator = 0;
          reportJoy.throttle    = 0;
          reportJoy.brake       = 0;
          reportJoy.shifter     = 0;
          reportJoy.clutch      = 0;
          //
          reportStatePID.deviceIsPaused         = false;
          reportStatePID.actuatorEnabled        = false;
          reportStatePID.safetySwitch           = false;
          reportStatePID.actuatorOverrideSwitch = false;
          reportStatePID.actuatorPower          = false;
          reportStatePID.effectPlaying          = false;
          reportStatePID.effectBlockIndex       = 0;
          reportStatePID.padding                = 0;
          //
      }
      
      void begin(void) {
        // add OUTPUT buffers
        HID->addOutputBuffer(&dataSetEffect);
        HID->addOutputBuffer(&dataSetEnvelope);
        HID->addOutputBuffer(&dataSetCondition);
        HID->addOutputBuffer(&dataSetPeriodic);
        HID->addOutputBuffer(&dataSetConstantForce);
        HID->addOutputBuffer(&dataSetRampForce);
        HID->addOutputBuffer(&dataDeviceControl);
        HID->addOutputBuffer(&dataDeviceGain);
        // add FEATURE buffers
        HID->addFeatureBuffer(&dataNewEffect);
        HID->addFeatureBuffer(&dataBlockLoad);
        HID->addFeatureBuffer(&dataPoolPID);
      }
      
      void end(void) {}
      
      inline void send(void) {
          reporterJoy.sendReport();
      }
      
      inline void setManualReportMode(bool mode) {
        manualReport = mode;
      }
      
      inline bool getManualReportMode() {
        return manualReport;
      }

      void test() {
        
          uint8_t value;
          
          if(reporterNewEffect.getFeature((uint8_t*)&reportNewEffect)) {
            CompositeSerial.print("getFature(");
            CompositeSerial.print(value);
            CompositeSerial.println(")");
          }
          
          if(reporterPoolPID.getFeature((uint8_t*)&reportPoolPID)) {
            CompositeSerial.println("reporterPool");
          }
          
          if(reporterLoadPID.getFeature(&value)) {
            CompositeSerial.println("reporterLoad");
            reporterLoadPID.setFeature((uint8_t*)&bufNewEffect);
          }

          if(reporterJoy.getOutput(&value)) {
            CompositeSerial.println("reporterJoy");
          }

          reportPoolPID.ramPoolSize             = 0xFFFF;
          reportPoolPID.maxSimultaneousEffects  = 0x0A; // FFP supports playing up to 10 simultaneous effects
          reportPoolPID.memoryManagement        = 3;
          reporterPoolPID.setFeature((uint8_t*)&reportPoolPID);
          reporterPoolPID.sendReport();

          reportNewEffect.effectType = FFB_EFFECT_CONSTANT;
          reporterNewEffect.setFeature((uint8_t*)&reportNewEffect);
          reporterNewEffect.sendReport();
                    
      }

};

