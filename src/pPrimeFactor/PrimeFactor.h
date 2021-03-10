/************************************************************/
/*    NAME: yang                                              */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef PrimeFactor_HEADER
#define PrimeFactor_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include <list>
#include "PrimeEntry.h"
using namespace std;
class PrimeFactor : public CMOOSApp
{
 public:
   PrimeFactor();
   ~PrimeFactor();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
 protected:
   void RegisterVariables();

 private: // Configuration variables
    uint64_t value;
    int m_max_iter;
    string m_result_str;
    int i;
    int m_index;
    int m_calc;
    list <PrimeEntry> mylist;
 private: // State variables
};

#endif 
