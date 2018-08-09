#ifndef List_H
#define List_H

#include <iostream>
#include <stdlib.h>
using namespace std;
//结点模板类
template <typename t1, typename t2>
class node {
private:
    t1 data1;    //数据成员data1
    t2 data2;    //数据成员data2
    node<t1, t2> *next;  //后继结点指针
public:
    node(t1 da1, t2 da2) :data1(da1), data2(da2), next(NULL) {}  //构造函数
    ~node() {}                        //析构函数
    t1 getData1();                   //获得成员变量data1
    t2 getData2();                   //获得成员变量data2
    node<t1, t2> * getNext();         //获得后继结点地址
    void setData1(t1 da1);           //设置成员变量data1
    void setData2(t2 da2);           //设置成员变量data2
    void setNext(node<t1, t2> * x);   //设置成员变量next
};

template <typename t1, typename t2>
class list {
private:
    int num;            //链表结点个数,不包括头结点
    node<t1, t2> * head; //链表头结点指针
public:
    list();  //构造函数
    ~list(); //析构函数
    void insertFront(node<t1, t2> &x);     //头插法
    void insertAfter(node<t1, t2> &x);     //尾插法
    void insert(int i, node<t1, t2> &x);   //在第i个结点处，插入一个结点
    void deleteNode(int i);               //删除第i个结点
    void setNode(int i, t1 da1, t2 da2);  //设置第i个结点的值
    void printAll();   //打印整个表
};
#endif