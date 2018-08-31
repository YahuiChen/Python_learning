#include<iostream>
#include "salist.h"
using namespace std;

void find(int x)
{
}
int main()
{
    int i, j, temp;
    SelfAdjustList<int> a;
    for (i = 0; i < 10; i++)
    {
        a.add(i);
    }
    cout << a.top() << endl;
    a.find(1);
    cout << a.top() << endl;
}