/*
*ʵ������ֵ������ִ�����в�����
*������ʼ������һ��Ԫ�أ�������β������һ��Ԫ�أ�
*������ʼ��ɾ��һ��Ԫ�أ�������β��ɾ��һ��Ԫ��
*/

#include <iostream>
#include <stdlib.h>
#include "List1.h"
using namespace std;

void main()
{
    node  *a = new node(3);
    node  *b = new node(2);
    node  *c = new node(1);
    node  *d = new node(4);
    node  *e = new node(5);
    node  *f = new node(6);
    list  z; 
    z.insertFront(*a);
    z.insertFront(*b);
    z.insertFront(*c);
    z.insertAfter(*d);
    z.insertAfter(*e);
    z.insertAfter(*f);
    z.printAll();
    cout << endl;
    z.deleteFront();
    z.deleteAfter();
    //z.deleteNode(6); //ɾ����6�����
    z.printAll(); //��ӡ����
}