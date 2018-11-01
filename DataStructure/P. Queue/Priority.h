#pragma once

#include <vector>

class Priority
{
	public:
		Priority(); //Done 
		Priority(bool p); //Done

		void push(int data); //DONE
		void pop(); //DONE
		int top(); //DONE 
		int size(); //DONE
		bool empty(); //DONE
		void print(); //Used to see if it's working

	private:
		std::vector<int> TheHeap;
		bool p;
		bool compara(int a, int b);
		void cambiar(int& a, int& b);

};

Priority::Priority()
{
	p = true;
}

Priority::Priority(bool p)
{
	this-> p = p;
}

void Priority::push(int data)
{
	TheHeap.push_back(data);
	int counter = TheHeap.size() - 1;
	while(counter/2>=0 && compara(TheHeap[counter], TheHeap[counter/2]))
	{
		cambiar(TheHeap[counter], TheHeap[counter/2]);
		counter/=2;
	}
}

void Priority::pop(){
	cambiar(TheHeap[0], TheHeap[TheHeap.size()-1]);
	TheHeap.erase(TheHeap.end()-1);

	
	for(int i=0;i<(TheHeap.size()-1)/2;++i)
	{
		if(compara(TheHeap[(i+1)*2-1],TheHeap[(i+1)*2]))
		{
			if(!compara(TheHeap[i], TheHeap[(i+1)*2-1]))
			{
				cambiar(TheHeap[i],TheHeap[(i+1)*2-1]);
			}

		} 

		else 
		{
			if(!compara(TheHeap[i], TheHeap[(i+1)*2]))
			{
				cambiar(TheHeap[i],TheHeap[(i+1)*2]);
			}
		}
	}
}

int Priority::top()
{
	if(TheHeap.size() != 0)
	{
		return TheHeap[0];
	}

	return -1;
}

int Priority::size()
{
	return TheHeap.size();
}

bool Priority::empty()
{
	return TheHeap.size() == 0;
}

void Priority::print()
{
	for(int i=0;i < TheHeap.size();++i)
	{
		cout << TheHeap[i] << " ";
	}
	cout<<endl;
}


bool Priority::compara(int a, int b)
{
	return p ? a>b : a<b;
}

void Priority::cambiar(int& a, int& b)
{
	int tmp = a; 
	a = b; 
	b = tmp;
}

