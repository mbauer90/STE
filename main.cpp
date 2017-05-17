#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "UART1.h"
#include "GPIO.h"
#include "Timer.h"
#include "RDM6300.h"
#include "FIFO.h"
#include "Buzzer.h"
#include "UserManager.h"
//#include "RFIDreader.h"

Timer timer(1000);
UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE,UART::STOPBITS_1);

Buzzer buzzer_porta(8,10000,300);

GPIO botao_apaga_cadastros(7,GPIO::INPUT);
GPIO botao_fechadura(12,GPIO::INPUT);
GPIO botao_cadastro(13,GPIO::INPUT);

GPIO led_verde(9,GPIO::OUTPUT);
GPIO led_vermelho(11,GPIO::OUTPUT);

GPIO rele(10,GPIO::OUTPUT);
User_Manager usuarios;
//RFIDreader leitorRFID;

UART1 uart1;
RDM6300<UART1> leitorRFID(&uart1);

void abre_porta(){

	buzzer_porta.aciona(); //Som
	led_verde.set(true);
	rele.set(true);			//Ativa Rele
	led_vermelho.set(false);
	timer.delay(2000);
	led_verde.set(false);
	rele.set(false);		//Desativa Rele
	led_vermelho.set(true);
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
	//usuarios.cadastra_usuario(leitorRFID.read());

	static unsigned long long id_atual = 0;

	while(uart1.has_data()) {
		leitorRFID.parse(uart1.get());
		if(leitorRFID.has_valid_id())
			id_atual = leitorRFID.get_id();
	}

	usuarios.cadastra_usuario(id_atual);
	id_atual = 0;
}

void faz_som(){

}

void loop(){
	static unsigned long long id_atual = 0;
	id_atual = 0;

	while(uart1.has_data()) {
		leitorRFID.parse(uart1.get());
		if(leitorRFID.has_valid_id())
			id_atual = leitorRFID.get_id();
	}

	if(usuarios.consulta_usuario(id_atual) >= 0){
		abre_porta();
		id_atual = 0;
		uart1.apagafilas(); 	//Esvaziar uart para não abrir a porta 2 vezes
	}
//	if(id_atual) {
//		char buffer[32];
//		union {
//			unsigned long long ull;
//			unsigned long ul[2];
//			unsigned short us[4];
//		} tmp;
//		tmp.ull = id_atual;
//		sprintf(buffer, "RFID: %04x%04x%04x%04x\r\n", tmp.us[3], tmp.us[2], tmp.us[1], tmp.us[0]);
//		uart.puts(buffer);
//		id_atual = 0;
//	}

	if(ler_botao_fechadura()){
		abre_porta();
	}

	if(ler_botao_cadastro()){
		led_verde.set(true);
		led_vermelho.set(true);

		for(int i=0; i < 30; i++){
			cadastra_usuario();
			timer.delay(100);
		}

		led_verde.set(false);
		led_vermelho.set(false);
	}

	if(ler_botao_apaga_cadastros()){
		usuarios.apaga_tudo();
	}
//
//	//RFID CONSULTANDO (PROFESSOR)
//	if(usuarios.consulta_usuario(id_atual) >= 0){
//	//if(usuarios.consulta_usuario(leitorRFID.read()) >= 0){
//		abre_porta();
//	}

}

int main(){
	//char message[8];
	setup();

	while(true){
		loop();
	}
}




