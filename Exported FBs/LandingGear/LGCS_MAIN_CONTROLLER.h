/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: LGCS_MAIN_CONTROLLER
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2022-01-11/Fan -  - 
 *************************************************************************/

#ifndef _LGCS_MAIN_CONTROLLER_H_
#define _LGCS_MAIN_CONTROLLER_H_

#include "basicfb.h"
#include "forte_int.h"
#include "forte_real.h"
#include "forte_string.h"
#include "forte_array_at.h"


#include <iostream>
#include <stdio.h>

class FORTE_LGCS_MAIN_CONTROLLER: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_LGCS_MAIN_CONTROLLER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventCYCLEID = 1;
  static const TEventID scm_nEventCMD_UP_COMFIRMID = 2;
  static const TEventID scm_nEventCMD_DOWN_COMFIRMID = 3;
  static const TEventID scm_nEventANALOGICAL_OPEN_COMFIRMID = 4;
  static const TEventID scm_nEventANALOGICAL_CLOSE_COMFIRM_1ID = 5;
  static const TEventID scm_nEventDOOR_OPEN_COMFIRMID = 6;
  static const TEventID scm_nEventDOOR_CLOSE_COMFIRMID = 7;
  static const TEventID scm_nEventERRORID = 8;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventGET_GL_STATUSID = 0;
  static const TEventID scm_nEventCNF_GL_STATUSID = 1;
  static const TEventID scm_nEventCNF_SET_GL_STATUS_LIGHTID = 2;
  static const TEventID scm_nEventCNF_MSGID = 3;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_REAL &st_status() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  }
  
  CIEC_INT &st_error_code() {
    return *static_cast<CIEC_INT*>(getDI(1));
  }
  
  CIEC_STRING &st_TI() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  }
  
  CIEC_REAL &st_gear_lever_status() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  }
  
  CIEC_REAL &st_set_gear_lever_status() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  }
  
  CIEC_STRING &st_gear_lever_msg() {
    return *static_cast<CIEC_STRING*>(getDO(2));
  }
  

  void alg_initialize(void);
  void alg_CYCLE(void);
  void alg_GearLeverSetUp(void);
  void alg_GearLeverSetDown(void);
  void alg_DisplayError(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateNORMAL = 1;
  static const TForteInt16 scm_nStateINIT = 2;
  static const TForteInt16 scm_nStateCYCLE = 3;
  static const TForteInt16 scm_nStateCMD_UP_COMFIRM = 4;
  static const TForteInt16 scm_nStateCMD_DOWN_COMFIRM = 5;
  static const TForteInt16 scm_nStateERROR = 6;
  
  void enterStateSTART(void);
  void enterStateNORMAL(void);
  void enterStateINIT(void);
  void enterStateCYCLE(void);
  void enterStateCMD_UP_COMFIRM(void);
  void enterStateCMD_DOWN_COMFIRM(void);
  void enterStateERROR(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(4, 3, 3, 0, 0);

public:
  FORTE_LGCS_MAIN_CONTROLLER(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_LGCS_MAIN_CONTROLLER() = default;
};

#endif // _LGCS_MAIN_CONTROLLER_H_


