/*
*实现整数型堆栈，能执行下列操作：
*入栈；出栈；
*判断栈为空；
*打印栈中元素
*/

#include <iostream>
#include "stack.h"
using namespace std;

void main()
{
    int i = 0;
    stack a;
    for (i = 0; i < MAX; i++)
    {
        a.push(i);
    }
    a.dump();
    for (i = 0; i < MAX; i++)
    {
        cout << a.pop() << endl;
    }
    a.isEmpty();
    exit(0);
}