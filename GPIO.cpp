/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"
#include <avr/io.h>

GPIO::GPIO(int pin,PortDirection_t dir) {
	//Configurar o DDR

	if((pin>=0) & (pin <= 7)){ // PIN D
		mask = (1 << pin);
		_ddr = &DDRD;
		_port = &PORTD;
		_pin = &PIND;
	}else if((pin >= 8) & (pin <=13)){ // PIN B
		mask = (1 << (pin-8));
		_ddr = &DDRB;
		_port = &PORTB;
		_pin = &PINB;
	}else if((pin >= 14) & (pin <=19)){ // PIN C
		 mask = (1 << (pin-14));
		_ddr = &DDRC;
		_port = &PORTC;
		_pin = &PINC;
	}

		if(dir==OUTPUT){
			*_ddr = *_ddr | mask;
		}else{
			*_ddr = *_ddr & ~mask;
		}

//	if((pin>=0) & (pin <= 7)){ // PIN D
//
//		 mask = (1 << pin);
//
//			if(dir==OUTPUT){
//				DDRD = DDRD | mask;
//			}else{
//				DDRD = DDRD & ~mask;
//			}
//	}else if((pin >= 8) & (pin <=13)){ // PIN B
//
//		mask = (1 << pin-7);
//
//			if(dir==OUTPUT){
//				DDRB = DDRB | mask;
//			}else{
//				DDRB = DDRB & ~mask;
//			}
//	}else if((pin >= 14) & (pin <=19)){ // PIN C
//
//		mask = (1 << pin-13);
//
//			if(dir==OUTPUT){
//				DDRC = DDRC | mask;
//			}else{
//				DDRC = DDRC & ~mask;
//			}
//	}

}

GPIO::~GPIO() {}

bool GPIO::get(){
	//ler o PIN
	//return (PINB & mask);
	return (*_pin & mask);
}

void GPIO::set(bool val){
	//escrever no PORT
	if(val){
		//acende
		//PORTB = PORTB | led_mask;
		*_port = *_port | mask;
	}else{
		//apaga
		//PORTB = PORTB & ~led_mask;
		*_port = *_port & ~mask;
	}

}

