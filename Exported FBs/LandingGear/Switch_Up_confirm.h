/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Switch_Up_confirm
 *** Description: Switching(demultiplexing) an event based on boolean input G
 *** Version:
***     1.0: 2022-01-09/Fan -  - 
 *************************************************************************/

#ifndef _SWITCH_UP_CONFIRM_H_
#define _SWITCH_UP_CONFIRM_H_

#include "basicfb.h"
#include "forte_bool.h"
#include "forte_array_at.h"


class FORTE_Switch_Up_confirm: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Switch_Up_confirm)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  
  static const TEventID scm_nEventCNF_STATUS_COMFIRMID = 0;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventEO1ID = 0;
  
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_BOOL &st_G() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  


  static const TForteInt16 scm_nStateSTART = 0;
  
  void enterStateSTART(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(1, 1, 0, 0, 0);

public:
  FORTE_Switch_Up_confirm(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Switch_Up_confirm() = default;
};

#endif // _SWITCH_UP_CONFIRM_H_


