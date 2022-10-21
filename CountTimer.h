#ifndef CountTimer_h
#define CountTimer_h
#include "Arduino.h"

class CountTimer {
  public:
      CountTimer(unsigned long newDuration); //current time is always in milliseconds duration is always in min
      CountTimer(unsigned long newDuration, unsigned long currentTime); //current time is always in milliseconds duration is always in min
      CountTimer(unsigned long newDuration, unsigned long currentTime, bool state); //current time is always in milliseconds duration is always in min

      bool checkTimer(unsigned long currentTime); //current time is always in milliseconds
      void setStartTime(unsigned long currentTime);
      void setDuration(unsigned long newDuration);
      void setTimerState(bool newState);
      bool timerState;
  private:
      void init(unsigned long newDuration, unsigned long currentTime, bool active);
      unsigned long ctime;
      unsigned long dur;
      unsigned long SEC = 1000; //one second is 1000 milliseconds
      unsigned long MIN = 60*SEC;
      unsigned long HOUR = 60*MIN; 
};
#endif
