/*
*ʵ�������Ͷ�ջ����ִ�����в�����
*��ջ����ջ��
*�ж�ջΪ�գ�
*��ӡջ��Ԫ��
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