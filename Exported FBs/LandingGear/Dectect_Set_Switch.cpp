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

#include "Dectect_Set_Switch.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Dectect_Set_Switch_gen.cpp"
#endif

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "NIOclient.h"

DEFINE_FIRMWARE_FB(FORTE_Dectect_Set_Switch, g_nStringIdDectect_Set_Switch)

const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anDataInputNames[] = {g_nStringIdip_address, g_nStringIdport, g_nStringIdset_alarm_time, g_nStringIdPARAMS, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anDataOutputNames[] = {g_nStringIdin};

const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_Dectect_Set_Switch::scm_anEIWith[] = {0, 1, 2, 3, 255};
const TForteInt16 FORTE_Dectect_Set_Switch::scm_anEIWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREAD_GL_STATUS};

const TDataIOID FORTE_Dectect_Set_Switch::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Dectect_Set_Switch::scm_anEOWithIndexes[] = {-1, 0};
const CStringDictionary::TStringId FORTE_Dectect_Set_Switch::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF_SET_STATUS};


const SFBInterfaceSpec FORTE_Dectect_Set_Switch::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  5, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

using std::cout;
using std::string;
using std::to_string;



void FORTE_Dectect_Set_Switch::executeEvent(int pa_nEIID) {

// string tempParam = st_PARAMS().getValue();

      if(!client.isConnected()){
        //Connect to the simulator 
        long int listenerPort = 0;
        listenerPort = st_port();
        char serverAddress[32] = {0};
        st_ip_address().toString(serverAddress, 32);
        //Forte parameter string have leading and terminating single-quote characters in them, remove them from the server address just created.
        for (int ptr = 1; ptr < 32; ptr++) {
          serverAddress[ptr - 1] = serverAddress[ptr];
          if((ptr > 1) && (serverAddress[ptr] == '\'')){
            serverAddress[ptr - 1] = '\0';
            break;
          }
        }

      if (client.connectToServer(serverAddress, listenerPort))
      {

        cout << "Dectect_Set_Switch connected to the simulator successful\n";
        cout << switchType;

      } else {
        cout <<"Dectect_Set_Switch" << "cannot connect to the simulator at " << serverAddress << 
        "via listenerPort " <<listenerPort <<". " << client.getLastErrorMessage() << "\n";
      }
    }






  switch(pa_nEIID) {
    case scm_nEventREAD_GL_STATUSID:
      if (client.isConnected()) {
        //Request the status of the switch.
        //string params = st_PARAMS().getValue();
        string packet = (string) START_OF_PACKET + st_PARAMS().getValue() + (string) FIELD_SEPARATOR + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
        client.sendPacket(packet);

        //Extract the returned switch value from the reply packet.
        packet = client.recvPacket();
        //cout << "\n Received ["<< packet << "]\n";

        string temp = "";
        if(packet.length() > 0){
          size_t ptrStart = -1;
          size_t ptrEnd = -1;
          ptrStart = packet.find("|");
          if(ptrStart > (size_t) 0) {
            ptrEnd = packet.find("|",ptrStart + 1);

            if(ptrEnd > (size_t) 0) {

              temp = packet.substr(ptrStart + 1, ptrEnd - ptrStart - 1);
              if(temp.length() == 1) {
                
                if(temp.substr(0,1) == "T") {
                  st_in() = true;
                  sendOutputEvent(scm_nEventCNF_SET_STATUSID);
                }else{
                  st_in() = false;
                  sendOutputEvent(scm_nEventCNF_SET_STATUSID);

                }
              }else {
                //there is no true or false value in the packet
                //so default the st_in() value to false but do not fire the event.
                st_in() = false;

              }
              
            }

          }

        } 

      }
      
      break;
     
      sendOutputEvent(scm_nEventINITOID);
      break;
  }
  
}




