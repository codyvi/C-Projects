#include <iostream>

using namespace std;

#include "Priority.h"

int main()
{
	Priority p(false);

	cout << p.top() << endl;

	if(p.empty())
	{
		cout << "La P. Queue esta vacía" << endl;
	}

	p.push(10);
	p.push(5);
	p.print();
	

}