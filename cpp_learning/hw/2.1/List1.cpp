#include <iostream>
#include <stdlib.h>
#include "List1.h"
using namespace std;

/*
node�ĳ�Ա����
*/
template <typename t1, typename t2>  //����������data1��ֵ
t1 node<t1, t2>::getData1() {
    return data1;
}

template <typename t1, typename t2> //����������data2��ֵ
t2 node<t1, t2>::getData2() {
    return data2;
}

template <typename t1, typename t2>  //���غ�̽��ָ��
node<t1, t2> * node<t1, t2>::getNext() {
    return next;
}

template <typename t1, typename t2>  //����������data1��ֵ
void node<t1, t2>::setData1(t1 da1) {
    data1 = da1;
}

template <typename t1, typename t2>  //����������data2��ֵ
void node<t1, t2>::setData2(t2 da2) {
    data2 = da2;
}

template <typename t1, typename t2>  //���ú�̽��ָ��
void node<t1, t2>::setNext(node<t1, t2> * x) {
    next = x;
}

/*
list�ĳ�Ա����
*/
template <typename t1, typename t2>  //�����캯��������ͷ���(ͷ�����ֵ��û�����壬��Ϊ0)
list<t1, t2>::list() {
    num = 0;
    head = new node<t1, t2>(0, 0);
}

template <typename t1, typename t2>  //�������������������ͷŸ����ڵ㣬����ͷ���
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

//ͷ����
template <typename t1, typename t2>  //��headָ��Ľ�㴦������
void list<t1, t2>::insertFront(node<t1, t2> &x) {
    node<t1, t2> *p = head->getNext();
    head->setNext(&x);
    x.setNext(p);
    num++;
}

//β����
template <typename t1, typename t2>  //������ĩβ������
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

template <typename t1, typename t2>  //�ڵ�i����㴦������
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
        cout << "����λ�ó���" << endl;
        exit(1);
    }
}

template <typename t1, typename t2>   //ɾ����i�����
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
        cout << "ɾ��λ�ó���" << endl;
        exit(1);
    }
}

template <typename t1, typename t2> //���õ�i��������ֵ��data1��data2
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

template <typename t1, typename t2>   //��ӡ�����б�
void list<t1, t2>::printAll() {
    node<t1, t2> *p = head->getNext();
    if (p == NULL)
        cout << "��Ϊ��" << endl;
    else {
        int i = 1;
        while (p) {
            cout << "��" << i << "���" << "data1=" << p->getData1() << "	" << "data2=" << p->getData2() << endl;
            i++;
            p = p->getNext();
        }
    }
}