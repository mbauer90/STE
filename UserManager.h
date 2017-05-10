/*
 * UserManager.h
 *
 *  Created on: 12 de abr de 2017
 *      Author: aluno
 */

#ifndef USERMANAGER_H_
#define USERMANAGER_H_

class User_Manager {
public:
	User_Manager();
	//~User_Manager();

	void cadastra_usuario(unsigned long long int valor);
	int consulta_usuario(unsigned long long int valor);
	void apaga_tudo();
};

#endif /* USERMANAGER_H_ */
