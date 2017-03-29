/*
 * Timer.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned long long Timer::_ticks = 0;

Timer::Timer(Hertz freq) {

	freq2 = freq;
	int div;

	TCCR0A = 0x00; //normal operation
	TIMSK0 = 0X01; //Liga interrupcao de overflow

	if((freq >= 62) and (freq <= 15000)){
		TCCR0B = 0x05; //divisor 1024
		div = 1024;
	}else if((freq > 15000) and (freq <= 62000)){
		TCCR0B = 0x04; //divisor 256
		div = 256;
	}else if((freq > 62000) and (freq <= 250000)){
		TCCR0B = 0x03; //divisor 64
		div = 64;
	}
	long int freqtimer = F_CPU / div;
	int ciclos = freqtimer / freq;
	TCNT0 = 0xFF - ciclos;
	//TCNT0 = 0xF0;
}

Milliseconds Timer::millis(){
	//versao errada
	Milliseconds t = micros() / 1000;
	return t;
	//return _ticks;
}

Microseconds Timer::micros(){
	return (_ticks * (1000000 / freq2));
}

void Timer::delay(Milliseconds ms){
	this->udelay(ms*1000);
}

void Timer::udelay(Microseconds us){


	Microseconds start = micros();
	Microseconds t = start;

	while(t <= start + us){
		t = micros();
	}

}

void Timer::isr_handler(){
	TCNT0 = 0xF0;
	_ticks++;
}

ISR(TIMER0_OVF_vect){
	Timer::isr_handler();
}
