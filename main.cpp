#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"

char pin_led = 3;
const unsigned char led_mask = (1 << pin_led);
char pin_botao = 4;
const unsigned char botao_mask = (1 << pin_botao);
//bool led_state = 0;
//unsigned long tempo = 1000;

UART uart;

void acende_led(){
	PORTB = PORTB | led_mask;
}

void apaga_led(){
	PORTB = PORTB & ~led_mask;
}

bool ler_botao(){
	return (PINB & botao_mask);
}


void setup(){
	//DDRB = 0x20;
	//pinMode(pin, OUTPUT);
	DDRB = DDRB | led_mask;
	DDRB = DDRB & ~botao_mask;
}

//void loop(){	//APENAS PISCA LED
//	//pinMode(inputPin, INPUT); LER VALOR DA TECLA
//	//int val = digitalRead(inputPin);
//		_delay_ms(tempo);
//		acende_led();
//		_delay_ms(tempo);
//		apaga_led();
//
//}

void loop(){
	//uart.put('a');
	uart.put(uart.get() + 1);

	//if((PINB & (1<<PB4))) acende_led();
	if(ler_botao()){
		//printf("Acendendo led");
		acende_led();
	}
	else{
		//printf("Apagando led");
		apaga_led();
	}

}

int main(){
	setup();

	while(true){
		loop();
	}
}



