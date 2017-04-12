#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "GPIO.h"
#include "Timer.h"
#include "FIFO.h"
#include "UserManager.h"

Timer timer(1000);
UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE,UART::STOPBITS_1);

GPIO botao_cadastro(10,GPIO::INPUT);
GPIO led(11,GPIO::OUTPUT);
GPIO botao_fechadura(12,GPIO::INPUT);

User_Manager usuarios;

void abre_porta(){
	led.set(true);
	timer.delay(2000);
	led.set(false);
}

bool ler_botao_fechadura(){
	return botao_fechadura.get();
}

bool ler_botao_cadastro(){
	return botao_cadastro.get();
}

void setup(){
	sei();
}

void cadastra_usuario(){

}

void loop(){
	if(!ler_botao_fechadura()){
		abre_porta();
	}

//	if(!ler_botao_cadastro()){
//		cadastra_usuario();
//	}
}

//void teste_lista(){
//	char message[32];
//
//	sprintf(message, "%d\n",list_usuario.get(0));
//	uart.puts(message);
//
//	timer.delay(1000);
//}

int main(){
//	char message[8];

	setup();
//
//	usuarios.cadastra_usuario(12);
//	usuarios.cadastra_usuario(13);
//
//	usuarios.apaga_tudo();
//	usuarios.cadastra_usuario(14);

	while(true){
		//loop();
//		sprintf(message, "%d\n",usuarios.consulta_usuario(13));
//		uart.puts(message);
//		timer.delay(1000);
//		sprintf(message, "%d\n",usuarios.consulta_usuario(14));
//		uart.puts(message);
//		timer.delay(1000);
	}
}



