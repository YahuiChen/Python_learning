#ifndef List_H
#define List_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
private:
    int data;
    node  *next;
public:
    node(int da) :data(da), next(NULL) {}
    ~node() {}
    int getData();
    node * getNext();         //获得后继结点地址
    void setData(int da);
    void setNext(node * x);   
};

class list {
private:
    int num;
    node * head;
public:
    list();
    ~list();
    void insertFront(node  &x);
    void insertAfter(node  &x);
    void deleteFront();
    void deleteAfter();
    void deleteNode(int i);
    void printAll();
};
#endif