#include "Arduino.h"
#include "CountTimer.h"



CountTimer::CountTimer(unsigned long newDuration) {
	init(newDuration,0,false);
}
 
CountTimer::CountTimer(unsigned long newDuration, unsigned long currentTime) {
	init(newDuration, currentTime, true);
}

CountTimer::CountTimer(unsigned long newDuration, unsigned long currentTime, bool active) {
	init(newDuration,currentTime,active);
}

void CountTimer::init(unsigned long newDuration, unsigned long currentTime, bool active) {
	ctime = currentTime;
	dur = newDuration * MIN;
	timerState = active;
}


bool CountTimer::checkTimer(unsigned long currentTime) { //returns whether or not we have hit the timer
	//since this is a very rudimentry timer we are only counting clock cycles; we have three scenarios 
		//1) current time is less than the saved time + duration returns false: 
		//2) current time is greater than or equal to saved time + duration returns true:
		//3) the timer ran out and started over. Check this by seeing if the current time is less than the saved time - duration; 

	if (currentTime >= ctime + dur) return true;
	else if (currentTime < ctime - dur) return true; //should simply reset the timer within the next cycle with a shorter time scale (should only happen every 49.7 days on an arduino Nano)
	else if (currentTime < ctime + dur) return false; //havent met the timer yet
	//else return null; //something weird happened and we are trying to handle it gracefully
}

void CountTimer::setStartTime(unsigned long currentTime) {
	ctime = currentTime; 
}

void CountTimer::setDuration(unsigned long newDuration) {
	dur = newDuration;
}

void CountTimer::setTimerState(bool newState){
	timerState = newState;
}
