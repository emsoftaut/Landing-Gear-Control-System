/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Dectect_Set_Switch
 *** Description: Service Interface Function Block Type
 *** Version:
***     1.0: 2022-01-11/Fan -  - 
 *************************************************************************/

#ifndef _DECTECT_SET_SWITCH_H_
#define _DECTECT_SET_SWITCH_H_

#include "funcbloc.h"
#include "forte_bool.h"
#include "forte_lint.h"
#include "forte_string.h"
#include "forte_array_at.h"

#include <iostream>
#include <stdio.h>

#include "NIOclient.h"


class FORTE_Dectect_Set_Switch: public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_Dectect_Set_Switch)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREAD_GL_STATUSID = 1;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNF_SET_STATUSID = 1;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  CIEC_STRING &st_ip_address() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  }
  
  CIEC_LINT &st_port() {
    return *static_cast<CIEC_LINT*>(getDI(1));
  }
  
  CIEC_STRING &st_set_alarm_time() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  }
  
  CIEC_STRING &st_PARAMS() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  }
  
  CIEC_STRING &st_TI() {
    return *static_cast<CIEC_STRING*>(getDI(4));
  }
  
  CIEC_BOOL &st_in() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }

  //structure definitions
  static constexpr const char* START_OF_PACKET = "*";
  static constexpr const char* FIELD_SEPARATOR = "|";
  static constexpr const char* END_OF_PACKET = "&";

  string switchType = "";



  FORTE_FB_DATA_ARRAY(2, 5, 1, 0);

  void executeEvent(int pa_nEIID);

public:
    NIOclient client;
   FORTE_Dectect_Set_Switch(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CFunctionBlock( pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData) {
   };

  virtual ~FORTE_Dectect_Set_Switch() = default;
};

#endif // _DECTECT_SET_SWITCH_H_


