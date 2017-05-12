/*
 * Buzzer.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "GPIO.h"

class Buzzer {
public:
	Buzzer(int pin,int freq, int miliseconds);
	void aciona();
private:
	GPIO _buzzer_out;
	long int _frequencia;
	long int _miliseconds;
};

#endif /* BUZZER_H_ */
