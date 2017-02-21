/*
 * MyExceptions.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef MYEXCEPTIONS_H_
#define MYEXCEPTIONS_H_

using namespace std;

template <class T> class elementNotInVectorException{
private:
T element;
public:

	elementNotInVectorException(T element)
	{
		this->element = element;
	}

	T getElement() const
	{
		return this->element;
	}
};



#endif /* MYEXCEPTIONS_H_ */
