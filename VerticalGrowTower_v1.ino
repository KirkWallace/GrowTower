#define bot 2
#define top 3
#include "CountTimer.h"

//timing
unsigned long HR = 60; //1 hr is 60 min. the count timer converts time based on minutes as input
unsigned long pON_time = 1; //unit minutes 1
unsigned long pOFF_time = 29; //unit minutes 15
unsigned long lON_time = 8*HR; //unit hours 8
unsigned long lOFF_time = 4*HR; //unit hours 4

//Setup Timers
CountTimer pON(pON_time);
CountTimer pOFF(pOFF_time);
CountTimer lON(lON_time);
CountTimer lOFF(lOFF_time);



void setup() {
   pinMode(bot, OUTPUT);
   pinMode(top, OUTPUT);
   digitalWrite(bot,LOW);
   digitalWrite(top,LOW);
   
   turnPumpOn();
   turnLightOn();
}

void loop() {
  if(pON.timerState && pON.checkTimer(millis()))turnPumpOff();
  if(pOFF.timerState && pOFF.checkTimer(millis()))turnPumpOn();
  if(lON.timerState && lON.checkTimer(millis()))turnLightOff();
  if(lOFF.timerState && lOFF.checkTimer(millis()))turnLightOn();
}

void turnPumpOn(){
  pOFF.setTimerState(false);
  pON.setStartTime(millis());
  pON.setTimerState(true);
  digitalWrite(bot, HIGH);
}

void turnPumpOff(){
  pON.setTimerState(false);
  pOFF.setStartTime(millis());
  pOFF.setTimerState(true);
  digitalWrite(bot, LOW);
}

void turnLightOn(){
  lOFF.setTimerState(false);
  lON.setStartTime(millis());
  lON.setTimerState(true);
  digitalWrite(top, HIGH);
}

void turnLightOff(){
  lON.setTimerState(false);
  lOFF.setStartTime(millis());
  lOFF.setTimerState(true);
  digitalWrite(top, LOW);
}
