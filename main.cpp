#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "GPIO.h"
#include "Timer.h"

//UART uart;
UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE,UART::STOPBITS_1);

GPIO led(11,GPIO::OUTPUT);
GPIO botao(12,GPIO::INPUT);

Timer timer(1000);
char message[8];

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

void setup(){
	sei();
}

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


	//sprintf(message, "LED: %d\n",botao.get());
	//uart.puts(message);
	//_delay_ms(100);
//
	timer.delay(1000);
	sprintf(message, "Timer: %d\n",timer.millis());
	//sprintf(message, "Timer: %ull\n",timer.micros());
	uart.puts(message);
	//_delay_ms(100);

}

int main(){
	setup();

	while(true){
		loop();
	}
}



