/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Switch_Down_confirm
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2022-01-09/Fan -  - 
 *************************************************************************/

#include "Switch_Down_confirm.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Switch_Down_confirm_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Switch_Down_confirm, g_nStringIdSwitch_Down_confirm)

const CStringDictionary::TStringId FORTE_Switch_Down_confirm::scm_anDataInputNames[] = {g_nStringIdG};

const CStringDictionary::TStringId FORTE_Switch_Down_confirm::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};


const TDataIOID FORTE_Switch_Down_confirm::scm_anEIWith[] = {0, 255};
const TForteInt16 FORTE_Switch_Down_confirm::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Switch_Down_confirm::scm_anEventInputNames[] = {g_nStringIdCNF_STATUS_COMFIRM};

const TForteInt16 FORTE_Switch_Down_confirm::scm_anEOWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_Switch_Down_confirm::scm_anEventOutputNames[] = {g_nStringIdEO1};


const SFBInterfaceSpec FORTE_Switch_Down_confirm::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, nullptr, scm_anEOWithIndexes,
  1, scm_anDataInputNames, scm_anDataInputTypeIds,
  0, nullptr, nullptr,
  0, nullptr
};

void FORTE_Switch_Down_confirm::setInitialValues() {
}


void FORTE_Switch_Down_confirm::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}


void FORTE_Switch_Down_confirm::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


