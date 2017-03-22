//#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "GPIO.h"

//char pin_led = 3;
//char pin_botao = 4;

GPIO led(11,GPIO::OUTPUT);
GPIO botao(12,GPIO::INPUT);

UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE,UART::STOPBITS_1);
//UART uart;

void acende_led(){
	//PORTB = PORTB | led_mask;
	led.set(true);
}

void apaga_led(){
	//PORTB = PORTB & ~led_mask;
	led.set(false);
}

bool ler_botao(){
	//return (PINB & botao_mask);
	return botao.get();
}


//void setup(){
////	//DDRB = 0x20;
////	//pinMode(pin, OUTPUT);
//	DDRB = DDRB | led_mask;
//	DDRB = DDRB & ~botao_mask;
//}

void loop(){
	//uart.put('a');
	//uart.put(uart.get() + 1);

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
	//setup();

	while(true){
		loop();
	}
}



