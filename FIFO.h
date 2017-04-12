/*
 * FIFO.h
 *
 *  Created on: 31 de mar de 2017
 *      Author: aluno
 */

#ifndef FIFO_H_
#define FIFO_H_


template<int Q_SIZE,typename T>
class FIFO {
public:
	static const unsigned int FIFO_ERROR_EMPTY = -1;
	static const unsigned int FIFO_ERROR_FULL = -2;

	FIFO(){
		_head = 0;
		_tail = 0;
		_tamanho = 0;
	}

	~FIFO() {}

	int push(T value){
		//if(((_tail+1) % Q_SIZE) == _head) return;

		if(size() == Q_SIZE) return FIFO_ERROR_FULL;

		_buffer[_tail] = value;
		_tamanho++;

		if(_tail == Q_SIZE){
			_tail = 0;
		}else{
			_tail++;
		}
	}

	T pop(){
		//if(_tail==_head) return FIFO_ERROR_EMPTY;
		if(_tamanho==0) return FIFO_ERROR_EMPTY;

		T returnval = _buffer[_head];
		_tamanho--;

			if(_head == Q_SIZE){
				_head = 0;
			}else{
				_head++;
			}

		return returnval;

	}

	int size(){
		return _tamanho;
	}

protected:
	int _head, _tail, _tamanho;
	T _buffer[Q_SIZE];
};

#endif /* FIFO_H_ */
