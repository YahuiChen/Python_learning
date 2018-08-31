#include"set.h"
#include<iostream>
using namespace std;
int main()
{
    Set<int>s;
    for (int i = 0; i <= 10; i++)
    {
        s.insert(i);
    }
    //s.erase(10);
    Set<int>::const_iterator it = s.begin();
    for (; it != s.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}