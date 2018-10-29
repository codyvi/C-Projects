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
		int size();
		bool empty();

	private:
		Node<T> *final;
		int tam;
}