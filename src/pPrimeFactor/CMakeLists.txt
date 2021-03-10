#--------------------------------------------------------
# The CMakeLists.txt for:                       pPrimeFactor
# Author(s):                              yang
#--------------------------------------------------------

SET(SRC
  PrimeFactor.cpp
  PrimeFactor_Info.cpp
  main.cpp
  PrimeEntry.cpp
)

ADD_EXECUTABLE(pPrimeFactor ${SRC})

TARGET_LINK_LIBRARIES(pPrimeFactor
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

