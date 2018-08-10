#include <iostream>
#include <stdlib.h>
#include "list.h"
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
    z.printAll();
}