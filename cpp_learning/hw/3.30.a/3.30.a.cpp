#include<iostream>
#include "vector.h"
using namespace std;

void find(int x)
{
}
int main()
{
    int i, j, temp;
    /*int list[8];
    for (int i = 0; i < 8; i++)
        list[i] = i;*/
    int array[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
    // exchange(list, array);
   /* for (int i = 0; i < 8; i++)
        list[i] = i;*/
    cin >> i;
    temp = array[i];
    for (j = i; j > 0; j--)
    {
        array[j] = array[j - 1];
    }
    array[0] = temp;
    //MoveToStart(list, array);
}