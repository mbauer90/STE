#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "GPIO.h"
#include "Timer.h"
#include "FIFO.h"
#include "Buzzer.h"
#include "UserManager.h"
#include "RFIDreader.h"

Timer timer(1000);
UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE,UART::STOPBITS_1);

GPIO botao_apaga_cadastros(9,GPIO::INPUT);
GPIO botao_cadastro(10,GPIO::INPUT);
GPIO led(11,GPIO::OUTPUT);
GPIO botao_fechadura(12,GPIO::INPUT);

User_Manager usuarios;
RFIDreader leitorRFID;

Buzzer buzzer_porta(8,1000,400);
Buzzer buzzer_porta2(8,10000,300);

void abre_porta(){

	buzzer_porta.aciona(); //Som
	timer.delay(100);
	buzzer_porta2.aciona(); //Som
	led.set(true);
	timer.delay(2000);
	led.set(false);
	timer.delay(500);
}

bool ler_botao_fechadura(){
	return botao_fechadura.get();
}

bool ler_botao_cadastro(){
	return botao_cadastro.get();
}

bool ler_botao_apaga_cadastros(){
	return botao_apaga_cadastros.get();
}

void setup(){
	sei();
}

void cadastra_usuario(){
	usuarios.cadastra_usuario(leitorRFID.get());
}

void faz_som(){

}

void loop(){

	if(ler_botao_fechadura()){
		abre_porta();
	}

	if(ler_botao_cadastro()){
		cadastra_usuario();
	}

	if(ler_botao_apaga_cadastros()){
		usuarios.apaga_tudo();
	}

	//RFID CONSULTANDO (PROFESSOR)
	if(usuarios.consulta_usuario(0xABCDEF12ABCDEF12) >= 0){
		abre_porta();
	}
}

int main(){
	//char message[8];
	setup();

	while(true){
		loop();
	}
}




