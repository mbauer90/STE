/*
 * UserManager.cpp
 *
 *  Created on: 12 de abr de 2017
 *      Author: aluno
 */

#include "UserManager.h"
#include "Lista.h"
Lista<32,int> list_usuario;

User_Manager::User_Manager() {
	// TODO Auto-generated constructor stub

}

void User_Manager::cadastra_usuario(int valor){
	list_usuario.push(valor);
}

int User_Manager::consulta_usuario(int valor){
	return list_usuario.search(valor);
}

void User_Manager::apaga_tudo(){
	return list_usuario.apaga_lista();
}
