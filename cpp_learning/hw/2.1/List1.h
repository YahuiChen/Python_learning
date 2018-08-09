#ifndef List_H
#define List_H

#include <iostream>
#include <stdlib.h>
using namespace std;
//���ģ����
template <typename t1, typename t2>
class node {
private:
    t1 data1;    //���ݳ�Աdata1
    t2 data2;    //���ݳ�Աdata2
    node<t1, t2> *next;  //��̽��ָ��
public:
    node(t1 da1, t2 da2) :data1(da1), data2(da2), next(NULL) {}  //���캯��
    ~node() {}                        //��������
    t1 getData1();                   //��ó�Ա����data1
    t2 getData2();                   //��ó�Ա����data2
    node<t1, t2> * getNext();         //��ú�̽���ַ
    void setData1(t1 da1);           //���ó�Ա����data1
    void setData2(t2 da2);           //���ó�Ա����data2
    void setNext(node<t1, t2> * x);   //���ó�Ա����next
};

template <typename t1, typename t2>
class list {
private:
    int num;            //���������,������ͷ���
    node<t1, t2> * head; //����ͷ���ָ��
public:
    list();  //���캯��
    ~list(); //��������
    void insertFront(node<t1, t2> &x);     //ͷ�巨
    void insertAfter(node<t1, t2> &x);     //β�巨
    void insert(int i, node<t1, t2> &x);   //�ڵ�i����㴦������һ�����
    void deleteNode(int i);               //ɾ����i�����
    void setNode(int i, t1 da1, t2 da2);  //���õ�i������ֵ
    void printAll();   //��ӡ������
};
#endif