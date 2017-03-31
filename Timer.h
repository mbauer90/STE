/*
 * Timer.h
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#ifndef TIMER_H_
#define TIMER_H_

	typedef unsigned long Hertz;
	typedef unsigned long long Microseconds;
	typedef unsigned long long Milliseconds;

class Timer {
public:

	Timer(Hertz f);

	Milliseconds millis();
	Microseconds micros();

	void delay(Milliseconds ms);
	void udelay(Microseconds us);

	static void isr_handler();

	static Timer * self() { return __singleton; }

private:
	static Timer * __singleton;
	static unsigned long long _ticks;
	Hertz freq;
	int ciclos;
};

#endif /* TIMER_H_ */
