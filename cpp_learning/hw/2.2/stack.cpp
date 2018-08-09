#include <iostream>
#include "stack.h"
using namespace std;

stack::~stack()
{
    delete [] array;
}
void stack::push(int n)
{
    if (isFull())
        cout << "Õ»Âú";
    else {
        ++top;
        array[top] = n;
    }
}
int stack::pop()
{
    int t = 0;
    if (isEmpty())
        cout << "Õ»¿Õ";
    else
    {
        t = array[top];
        array[top] = 0;
        top--;
    }
    return t;
}
bool stack::isEmpty()
{
    if (top <= -1)
    {
       // return 1;
        cout << "Õ»¿Õ" << endl;
    }
    else return 0;
}
bool stack::isFull()
{
    if (top == (MAX - 1))
        return 1;
    else
        return 0;
}
void stack::dump()
{
    int i;
    for (i = top; i == 0; i--)
    {
        cout << "µÚ" << i << "¸ö=" << array[i];
    }
}