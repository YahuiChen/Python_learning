#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

int node::getData() {
    return data;
}

node  * node::getNext() {
    return next;
}

void node::setData(int da) {
    data = da;
}

void node::setNext(node  * x) {
    next = x;
}

list::list() {
    num = 0;
    head = new node(0);
}

list ::~list() {
    node  *p = head;
    node  *q = head->getNext();
    while (p) {
        q = p->getNext();
        if (p != NULL)
            delete p;
        p = q;
    }
}

//头插
void list::insertFront(node &x) {
    node *p = head->getNext();
    head->setNext(&x);
    x.setNext(p);
    num++;
}

//尾插
void list::insertAfter(node &x) {
    node *p = head;
    node *q = NULL;
    while (p) {
        q = p->getNext();
        if (q == NULL)
            p->setNext(&x);
        p = q;
    }
    num++;
}

void list::deleteFront() {
    node *p = head->getNext()->getNext();
    node *q = head->getNext();
    head->setNext(p);
    delete q;
    num--;
}

void list::deleteAfter()
{
    int j = num;
    int i = 0;
    node *p = head;
    for (i = 0; i < num - 1; i++)
    {
        p = p->getNext();
    }
    delete p->getNext();
    p->setNext(NULL);
    num--;
}

void list::printAll() {
    node *p = head->getNext();
    if (p == NULL)
        cout << "表为空" << endl;
    else {
        int i = 1;
        while (p) {
            cout << "第" << i << "个结点" << " " << "data = " << p->getData() << endl;
            i++;
            p = p->getNext();
        }
    }
}