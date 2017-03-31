/*
 * FIFO.h
 *
 *  Created on: 31 de mar de 2017
 *      Author: aluno
 */

#ifndef FIFO_H_
#define FIFO_H_


template <int Q_SIZE>
class FIFO {
public:
	FIFO(){
		_head = 0;
		_tail = 0;
	}

	~FIFO() {}

	void push(char value){
		if(((_tail+1) % Q_SIZE) == _head) return;

		_buffer[_tail] = value;

		if(_tail == Q_SIZE){
			_tail = 0;
		}else{
			_tail++;
		}
	}

	char pop(){
		if(_tail==_head) return 0;

		char returnval = _buffer[_head];

			if(_head == Q_SIZE){
				_head = 0;
			}else{
				_head++;
			}

		return returnval;


	}

private:
	int _head, _tail;
	char _buffer[Q_SIZE];
};

#endif /* FIFO_H_ */
