/*
*实现整数值链表，能执行下列操作：
*在链表开始处插入一个元素；在链表尾部插入一个元素；
*在链表开始处删除一个元素；在链表尾部删除一个元素
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
    //z.deleteNode(6); //删除第6个结点
    z.printAll(); //打印链表
}