/*
    Operations.cpp
    This file gets from the user some numbers
    in a string and operations, the program then
    assigns them in stack, queue, and priority queue
    then returns the value from the operation that
    comes in the string
    David Alonso Cantú Marttínz A00822455
    Version 1.0
*/

#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

/*
    Calculator
    This function gets the values a and b
    and returns them depending the operation
    parameters:
    a int that stores one value from the stack or queue
    b int that stores one value from the stack or queue
    sOperacion  string that gets the operation that the user needs to do
    returns:
    The result of the operation that the user realized
*/

int Calculator(int a, int b, string sOperacion)
{
    if(sOperacion == "+")
    {
        return a + b;
    }

    else if(sOperacion == "-")
    {
        return a - b;
    }

    else if(sOperacion == "*")
    {
        return a * b;
    }

    else
    {
        return -1;
    }
}

void sOperation(stack<int>& sStack, int a, int b, string d, int& op)
{
    //Assign the top value from the stack to int a
    a = sStack.top();
    sStack.pop();
    //Assign the top value from the stack to int b
    b = sStack.top();
    sStack.pop();
    //Calling Calculator to op
    op = Calculator(b, a, d);
    //Pushing the result to the stack
    sStack.push(op);
}

void sEmpty(stack<int> &sStack)
{
    while(!sStack.empty())
    {
        sStack.pop();
    }
}

void qOperation(queue<int> &qQueue, int a, int b, string d, int& op)
{
    //Assigning the front value from the queue to int a
    a = qQueue.front();
    qQueue.pop();
    //Assigning the front value from the queue to int b
    b = qQueue.front();
    qQueue.pop();
    //Calling Calculator to op
    op = Calculator(b, a, d);
    //Pushing the results to queue
    qQueue.push(op);
}

void qEmpty(queue<int> &qQueue)
{
    while(!qQueue.empty())
    {
        qQueue.pop();
    }
}

void pqOperation(priority_queue<int, vector<int>, greater<int> >& pQueue, int a, int b, string d, int& op)
{
    //Assigning the top value from the priority queue to a
    a = pQueue.top();
    pQueue.pop();
    //Assigning the top value from the priority queue to b
    b = pQueue.top();
    pQueue.pop();
    //Calling Calculator to op
    op = Calculator(b, a, d);
    //Pushing the results to queue
    pQueue.push(op);
}

void pQempty(priority_queue<int, vector<int>, greater<int> >& pQueue)
{
    while(!pQueue.empty())
    {
        pQueue.pop();
    }
}

int main()
{
    string d,data;
    int a, b, opStack, opQueue, opPQueue;
    stack<int> sStack;
    queue<int> qQueue;
    priority_queue<int, vector<int>, greater<int> > pQueue;


    getline(cin, data);
    while (data != "#")
    {
        stringstream ss;
        ss << data;
        //cout <<"Voy al while" << endl;
        while (ss >> d)
        {
            if(d == "+" || d == "-" || d == "*")
            {
                //Operations
                sOperation(sStack, a, b, d, opStack);
                qOperation(qQueue, a, b, d, opQueue);
                pqOperation(pQueue, a, b , d, opPQueue);
            }

            else
            {
                //Push values
                sStack.push(stoi(d));
                qQueue.push(stoi(d));
                pQueue.push(stoi(d));
            }

        }
        cout << opStack << " " << opQueue << " " << opPQueue << endl;
        getline(cin, data);
        sEmpty(sStack);
        qEmpty(qQueue);
        pQempty(pQueue);

    }

    return 0;
}
