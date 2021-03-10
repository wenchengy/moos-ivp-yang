/************************************************************/
/*    NAME: yang                                              */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "PrimeFactor.h"
#include "PrimeEntry.h"
#include <cstdint>
#include <list>
#include <string>
using namespace std;



//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
    value = 0;
    m_calc = 0;
}

//---------------------------------------------------------
// Destructor

PrimeFactor::~PrimeFactor()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey();
    string sval = msg.GetString();
    
    if(key=="NUM_VALUE"){
        m_index++;
        value = strtoul(sval.c_str(),NULL,0);
        
        PrimeEntry m_prime;
        m_prime.setOriginalVal(value);
        m_prime.setReceivedIndex(m_index);
        mylist.push_back(m_prime);
       }


#if 0 // Keep these around just for template
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
}
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactor::Iterate()
{
    m_max_iter = 5000;
    
    list<PrimeEntry>::iterator k;
    for(k=mylist.begin(); k!=mylist.end(); k++){
        PrimeEntry& m_prime_entry = *k;
//        m_prime_entry.printf();
        m_prime_entry.factor(m_max_iter);

        if(m_prime_entry.done()){
            m_calc++;
            m_prime_entry.setCalculatedIndex(m_calc);
            m_result_str=m_prime_entry.getReport();
            cout<<"NUM_RESULT: "<<m_result_str<<endl;
            k=mylist.erase(k);
        }
        else{
            break;
        }
        
    
    }
    return(true);
}
 

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactor::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string line  = *p;
      string param = tolower(biteStringX(line, '='));
      string value = line;
      
      if(param == "foo") {
        //handled
      }
      else if(param == "bar") {
        //handled
      }
    }
  }
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactor::RegisterVariables()
{
  // Register("FOOBAR", 0);
  Register("NUM_VALUE",0);
  //Register("NUM_RESULT",0);
}



