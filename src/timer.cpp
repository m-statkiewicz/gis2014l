/*
 * timer.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: Mateusz Statkiewicz
 */

#include"timer.h"

Timer::Timer() {
	state = 'n';
}

Timer::Timer(bool startsAtStart) {
	Timer();
	if (startsAtStart == true)
		start();
}

Timer::~Timer() {
}

void Timer::start() throw (TimerException) {
	if (state == 'm') {
		throw TimerException(WRONG_STATE);
	}
	state = 'm';
	gettimeofday(&start_t, NULL);
}

void Timer::stop() throw (TimerException) {
	if (state != 'm') {
		throw TimerException(WRONG_STATE);
	}
	state = 's';
	gettimeofday(&end_t, NULL);
}

double Timer::delta() throw (TimerException) {
	if (state != 's') {
		throw TimerException(WRONG_STATE);
	}
	return (end_t.tv_sec - start_t.tv_sec) + (double) (end_t.tv_usec - start_t.tv_usec) / 1000000;
}
std::string Timer::deltaToString()
{
	std::stringstream ss;
	double sec = delta();
	int min = (int)sec/60;
	sec = sec - min * 60;
	ss << min <<":"<< sec;
	return ss.str();
}
