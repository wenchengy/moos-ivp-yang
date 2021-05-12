#--------------------------------------------------------
# The CMakeLists.txt for:                       pAppCastingMOOSApp
# Author(s):                              yang
#--------------------------------------------------------

SET(SRC
  AppCastingMOOSApp.cpp
  AppCastingMOOSApp_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pAppCastingMOOSApp ${SRC})

TARGET_LINK_LIBRARIES(pAppCastingMOOSApp
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

