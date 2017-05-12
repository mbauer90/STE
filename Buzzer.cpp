/*
 * Buzzer.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#include "Buzzer.h"
#include "GPIO.h"
#include "Timer.h"

Timer timer_buzzer(1000);

Buzzer::Buzzer(int pin,int freq, int miliseconds) : _buzzer_out(pin,GPIO::OUTPUT)
{
	//_buzzer_out(pin,GPIO::OUTPUT);
	_frequencia = freq;
	_miliseconds = miliseconds;
}

void Buzzer::aciona(){
	long int val = (500000/(_frequencia));
	//long int t = _miliseconds*1000 / (1000/_frequencia);
	long int t = (_miliseconds*50) / (val*2);

	for(long int i=0; i < t; i++){
		_buzzer_out.set(true);
		timer_buzzer.udelay(val);
		_buzzer_out.set(false);
		timer_buzzer.udelay(val);
	}
}

