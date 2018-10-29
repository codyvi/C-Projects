#pragma once

#include <vector>

#include "Node.h"

template <class T>
class Priority
{
	public:
		Priority();
		Priority(bool priority);

		T top();
		void push(T data);
		void pop();
		int size(); //Done
		bool empty();

	private:
		Node<T> *final;
		int tam;
}

template <class T>
int Priority<T>::size()
{
	return tam;
}

template <class T>
bool Priority<T>::empty()
{
	return final == NULL;
}