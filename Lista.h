/*
 * Lista.h
 *
 *  Created on: 12 de abr de 2017
 *      Author: aluno
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "FIFO.h"

template<int Q_SIZE,typename T>
class Lista : public FIFO<Q_SIZE,T>
{
private:
	typedef FIFO<Q_SIZE,T> Base;
public:

	int search(T valor){
		int pos = Base::_head;

		while(pos < Base::_tamanho){
			if(Base::_buffer[pos] == valor){
				return pos;
			}

			pos++;
		}

		return -1;
	}


	T get(int pos){
		return Base::_buffer[pos];
	}

	void apaga_lista(){
		Base::_tail = 0;
		Base::_head = 0;
		Base::_tamanho = 0;
	}
};
#endif /* LISTA_H_ */
