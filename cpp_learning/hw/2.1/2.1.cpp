/*
*实现整数值链表，能执行下列操作：
*在链表开始处插入一个元素；在链表尾部插入一个元素；
*在链表开始处删除一个元素；在链表尾部删除一个元素
*/

#include <iostream>
#include <stdlib.h>
#include "List1.h"
using namespace std;
//结点模板类
//template <typename t1, typename t2>
//class node {
//private:
//    t1 data1;    //数据成员data1
//    t2 data2;    //数据成员data2
//    node<t1, t2> *next;  //后继结点指针
//public:
//    node(t1 da1, t2 da2) :data1(da1), data2(da2), next(NULL) {}  //构造函数
//    ~node() {}                        //析构函数
//    t1 getData1();                   //获得成员变量data1
//    t2 getData2();                   //获得成员变量data2
//    node<t1, t2> * getNext();         //获得后继结点地址
//    void setData1(t1 da1);           //设置成员变量data1
//    void setData2(t2 da2);           //设置成员变量data2
//    void setNext(node<t1, t2> * x);   //设置成员变量next
//};

//链表模板类
//template <typename t1, typename t2>
//class list {
//private:
//    int num;            //链表结点个数,不包括头结点
//    node<t1, t2> * head; //链表头结点指针
//public:
//    list();  //构造函数
//    ~list(); //析构函数
//    void insertFront(node<t1, t2> &x);     //头插法
//    void insertAfter(node<t1, t2> &x);     //尾插法
//    void insert(int i, node<t1, t2> &x);   //在第i个结点处，插入一个结点
//    void deleteNode(int i);               //删除第i个结点
//    void setNode(int i, t1 da1, t2 da2);  //设置第i个结点的值
//    void printAll();   //打印整个表
//};

/*
node的成员函数
//*/
template <typename t1, typename t2>  //返回数据域data1的值
t1 node<t1, t2>::getData1() {
    return data1;
}

template <typename t1, typename t2> //返回数据域data2的值
t2 node<t1, t2>::getData2() {
    return data2;
}

template <typename t1, typename t2>  //返回后继结点指针
node<t1, t2> * node<t1, t2>::getNext() {
    return next;
}

template <typename t1, typename t2>  //设置数据域data1的值
void node<t1, t2>::setData1(t1 da1) {
    data1 = da1;
}

template <typename t1, typename t2>  //设置数据域data2的值
void node<t1, t2>::setData2(t2 da2) {
    data2 = da2;
}

template <typename t1, typename t2>  //设置后继结点指针
void node<t1, t2>::setNext(node<t1, t2> * x) {
    next = x;
}

/*
list的成员函数
*/
template <typename t1, typename t2>  //链表构造函数，创建头结点(头结点数值域没有意义，置为0)
list<t1, t2>::list() {
    num = 0;
    head = new node<t1, t2>(0, 0);
}

template <typename t1, typename t2>  //链表析构函数，依次释放各个节点，包括头结点
list<t1, t2>::~list() {
    node<t1, t2> *p = head;
    node<t1, t2> *q = head->getNext();
    while (p) {
        q = p->getNext();
        if (p != NULL)
            delete p;
        p = q;
    }
}

//头插入
template <typename t1, typename t2>  //从head指向的结点处插入结点
void list<t1, t2>::insertFront(node<t1, t2> &x) {
    node<t1, t2> *p = head->getNext();
    head->setNext(&x);
    x.setNext(p);
    num++;
}

//尾插入
template <typename t1, typename t2>  //从链表末尾插入结点
void list<t1, t2>::insertAfter(node<t1, t2> &x) {
    node<t1, t2> *p = head;
    node<t1, t2> *q = NULL;
    while (p) {
        q = p->getNext();
        if (q == NULL)
            p->setNext(&x);
        p = q;
    }
    num++;
}

template <typename t1, typename t2>  //在第i个结点处插入结点
void list<t1, t2>::insert(int i, node<t1, t2> &x) {
    if (i == 1)
        insertFront(x);
    else if (i > 1 && i <= num) {
        num++;
        int j = 0;
        node<t1, t2> * p = head;
        node<t1, t2> * q = NULL;
        while (p) {
            j++;
            p = p->getNext();
            q = p->getNext();
            if (j == i - 1) {
                p->setNext(&x);
                x.setNext(q);
                break;
            }
        }
    }
    else {
        cout << "插入位置出错" << endl;
        exit(1);
    }
}

template <typename t1, typename t2>   //删除第i个结点
void list<t1, t2>::deleteNode(int i) {
    if (i >= 1 && i <= num) {
        int j = 0;
        node<t1, t2> * p = head;
        node<t1, t2> * q = NULL;
        while (p) {
            if (j == i - 1) {
                q = p->getNext();
                p->setNext(q->getNext());
                delete q;
                num--;
                break;
            }
            j++;
            p = p->getNext();
        }
    }
    else {
        cout << "删除位置出错" << endl;
        exit(1);
    }
}

template <typename t1, typename t2> //设置第i个结点的数值域data1和data2
void list<t1, t2>::setNode(int i, t1 da1, t2 da2) {
    int j = 0;
    node<t1, t2> *p = head;
    while (p) {
        j++;
        p = p->getNext();
        if (j == i) {
            p->setData1(da1);
            p->setData2(da2);
        }
    }
}

template <typename t1, typename t2>   //打印整个列表
void list<t1, t2>::printAll() {
    node<t1, t2> *p = head->getNext();
    if (p == NULL)
        cout << "表为空" << endl;
    else {
        int i = 1;
        while (p) {
            cout << "第" << i << "结点" << "data1=" << p->getData1() << "	" << "data2=" << p->getData2() << endl;
            i++;
            p = p->getNext();
        }
    }
}

void main() {
    //创建六个结点
    node<int, int> *a = new node<int, int>(1, 2);
    node<int, int> *b = new node<int, int>(2, 3);
    node<int, int> *c = new node<int, int>(3, 4);
    node<int, int> *d = new node<int, int>(4, 5);
    node<int, int> *e = new node<int, int>(5, 6);
    node<int, int> *f = new node<int, int>(6, 7);
    list<int, int> z; //创建链表对象
                      //表尾插入6个结点
    z.insertAfter(*a);
    z.insertAfter(*b);
    z.insertAfter(*c);
    z.insertAfter(*d);
    z.insertAfter(*e);
    z.insertAfter(*f);
    z.setNode(3, 0, 0); //设置第三个结点的data1为0，data2为0
    z.deleteNode(6); //删除第6个结点
    z.printAll(); //打印链表
}