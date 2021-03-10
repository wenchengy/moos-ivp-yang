/************************************************************/
/*    NAME: yang                                              */
/*    ORGN: MIT                                             */
/*    FILE: AppCastingMOOSApp.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef AppCastingMOOSApp_HEADER
#define AppCastingMOOSApp_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class AppCastingMOOSApp : public CMOOSApp
{
 public:
   AppCastingMOOSApp();
   ~AppCastingMOOSApp();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
