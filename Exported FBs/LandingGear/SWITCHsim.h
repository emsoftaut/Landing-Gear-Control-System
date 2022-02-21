/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SWITCHsim
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2020-01-13/badger - null - 
 *************************************************************************/

#ifndef _SWITCHSIM_H_
#define _SWITCHSIM_H_

#include <funcbloc.h>
#include <forte_lint.h>
#include <forte_bool.h>
#include <forte_string.h>

#include <iostream>
#include <stdio.h>

#include "NIOclient.h"

class FORTE_SWITCHsim: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_SWITCHsim)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_STRING &address() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_LINT &port() {
    return *static_cast<CIEC_LINT*>(getDI(1));
  };

  CIEC_STRING &params() {
    return *static_cast<CIEC_STRING*>(getDI(2));
  };

  CIEC_STRING &TI() {
    return *static_cast<CIEC_STRING*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  CIEC_BOOL &in() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREADID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  	static const SFBInterfaceSpec scm_stFBInterfaceSpec;
   	
  	//
	// Packet structure definitions
	// ============================
	static constexpr const char* START_OF_PACKET = "*";
	static constexpr const char* FIELD_SEPARATOR = "|";
	static constexpr const char* END_OF_PACKET = "&"; 
	
	string switchType = "";

	FORTE_FB_DATA_ARRAY(2, 4, 1, 0);
	
  	void executeEvent(int pa_nEIID);

public:
	NIOclient client;
	FUNCTION_BLOCK_CTOR(FORTE_SWITCHsim){
  	};

  	virtual ~FORTE_SWITCHsim(){};
};
#endif //close the ifdef sequence from the beginning of the file

