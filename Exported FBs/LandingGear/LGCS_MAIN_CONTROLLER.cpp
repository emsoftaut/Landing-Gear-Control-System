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

#include "LGCS_MAIN_CONTROLLER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "LGCS_MAIN_CONTROLLER_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_LGCS_MAIN_CONTROLLER, g_nStringIdLGCS_MAIN_CONTROLLER)

const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anDataInputNames[] = {g_nStringIdstatus, g_nStringIderror_code, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anDataOutputNames[] = {g_nStringIdgear_lever_status, g_nStringIdset_gear_lever_status, g_nStringIdgear_lever_msg};

const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdSTRING};

const TDataIOID FORTE_LGCS_MAIN_CONTROLLER::scm_anEIWith[] = {0, 255, 0, 255, 1, 255};
const TForteInt16 FORTE_LGCS_MAIN_CONTROLLER::scm_anEIWithIndexes[] = {-1, -1, 0, 2, -1, -1, -1, -1, 4};
const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCYCLE, g_nStringIdCMD_UP_COMFIRM, g_nStringIdCMD_DOWN_COMFIRM, g_nStringIdANALOGICAL_OPEN_COMFIRM, g_nStringIdANALOGICAL_CLOSE_COMFIRM_1, g_nStringIdDOOR_OPEN_COMFIRM, g_nStringIdDOOR_CLOSE_COMFIRM, g_nStringIdERROR};

const TDataIOID FORTE_LGCS_MAIN_CONTROLLER::scm_anEOWith[] = {0, 255, 1, 255, 2, 255};
const TForteInt16 FORTE_LGCS_MAIN_CONTROLLER::scm_anEOWithIndexes[] = {-1, 0, 2, 4};
const CStringDictionary::TStringId FORTE_LGCS_MAIN_CONTROLLER::scm_anEventOutputNames[] = {g_nStringIdGET_GL_STATUS, g_nStringIdCNF_GL_STATUS, g_nStringIdCNF_SET_GL_STATUS_LIGHT, g_nStringIdCNF_MSG};


const SFBInterfaceSpec FORTE_LGCS_MAIN_CONTROLLER::scm_stFBInterfaceSpec = {
  9, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  4, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  3, scm_anDataInputNames, scm_anDataInputTypeIds,
  3, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};



using std::cout;
using std::string;
using std::to_string;


void FORTE_LGCS_MAIN_CONTROLLER::setInitialValues() {
}

void FORTE_LGCS_MAIN_CONTROLLER::alg_initialize(void) {

  	cout << "[LGCS_MAIN_CONTROLLER1] alg_initialize()\n";
   // set default the Gear lever status

  	st_gear_lever_status()= false;
  	
}

void FORTE_LGCS_MAIN_CONTROLLER::alg_CYCLE(void) {
 
}

void FORTE_LGCS_MAIN_CONTROLLER::alg_GearLeverSetUp(void) {
  
    cout << "[LGCS_MAIN_CONTROLLER] alg_GearLeverSetUp()\n";
  	cout << "Landing Gear UP requested...\n";
  	//SET_TEMP() = SET_TEMP();
}

void FORTE_LGCS_MAIN_CONTROLLER::alg_GearLeverSetDown(void) {
 
  	cout << "[LGCS_MAIN_CONTROLLER] alg_GearLeverSetDown\n";
    cout << "Landing Gear DOWN requested...\n";
  //	SET_TEMP() = SET_TEMP();
}

void FORTE_LGCS_MAIN_CONTROLLER::alg_DisplayError(void) {
  
}


void FORTE_LGCS_MAIN_CONTROLLER::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateNORMAL(void) {
  m_nECCState = scm_nStateNORMAL;
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateINIT(void) {
  m_nECCState = scm_nStateINIT;
  alg_initialize();
  sendOutputEvent(scm_nEventCNF_GL_STATUSID);
  sendOutputEvent(scm_nEventCNF_SET_GL_STATUS_LIGHTID);
  sendOutputEvent(scm_nEventCNF_GL_STATUSID);
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateCYCLE(void) {
  m_nECCState = scm_nStateCYCLE;
  alg_CYCLE();
  sendOutputEvent(scm_nEventGET_GL_STATUSID);
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateCMD_UP_COMFIRM(void) {
  m_nECCState = scm_nStateCMD_UP_COMFIRM;
  alg_GearLeverSetUp();
  sendOutputEvent(scm_nEventCNF_SET_GL_STATUS_LIGHTID);
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateCMD_DOWN_COMFIRM(void) {
  m_nECCState = scm_nStateCMD_DOWN_COMFIRM;
  alg_GearLeverSetDown();
  sendOutputEvent(scm_nEventCNF_SET_GL_STATUS_LIGHTID);
}

void FORTE_LGCS_MAIN_CONTROLLER::enterStateERROR(void) {
  m_nECCState = scm_nStateERROR;
  alg_DisplayError();
  sendOutputEvent(scm_nEventCNF_MSGID);
}


void FORTE_LGCS_MAIN_CONTROLLER::executeEvent(int pa_nEIID){
  //cout <<"gear up/down\n";

 //switch (pa_nEIID) {
   // case scm_nEventCMD_UP_COMFIRMID:
   // cout << "Gear UP\n";
   // break;

    //case scm_nEventCMD_DOWN_COMFIRMID:
    //cout << "Gear DOWN\n";
    //break;
  //}



  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNORMAL:
        if(scm_nEventCYCLEID == pa_nEIID)
          enterStateCYCLE();
        else
        if(scm_nEventCMD_UP_COMFIRMID == pa_nEIID)
          enterStateCMD_UP_COMFIRM();
        else
        if(scm_nEventCMD_DOWN_COMFIRMID == pa_nEIID)
          enterStateCMD_DOWN_COMFIRM();
        else
        if(scm_nEventERRORID == pa_nEIID)
          enterStateERROR();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCYCLE:
        if(1)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCMD_UP_COMFIRM:
        if(1)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCMD_DOWN_COMFIRM:
        if(1)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateERROR:
        if(1)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 7.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


