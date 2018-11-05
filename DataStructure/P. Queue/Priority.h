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
	int counter = TheHeap.size()-1;
    while(counter/2 >= 0 && compara(TheHeap[counter],TheHeap[counter/2]))
    {
        cambiar(TheHeap[counter], TheHeap[counter/2]);
        counter /= 2;
    }

}

void Priority::pop()
{
	cambiar(TheHeap.front(), TheHeap.back());
    TheHeap.erase(TheHeap.end()-1);
    
    if(!TheHeap.empty())
    {
    	int i = 0;
        int izq = 2*i + 1;
        int der = 2*i + 2;
        int hP;

        while(izq < TheHeap.size() -1)
        {
       
            hP = compara(TheHeap[izq], TheHeap[i]) ? izq : i; 

            if(der <= TheHeap.size() - 1 && compara(TheHeap[der], TheHeap[hP]))
            {
                hP = der;
            }
    
            if(hP != i)
            {
                cambiar(TheHeap[i], TheHeap[hP]);
                i = hP;
            }

            else
            {
                break;
            }
        
            izq = 2*i + 1;
            der = 2*i + 2;
        }

    }   

}

int Priority::top()
{
	return TheHeap.front();
}

int Priority::size()
{
	return TheHeap.size();
}

bool Priority::empty()
{
	return TheHeap.empty();
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

