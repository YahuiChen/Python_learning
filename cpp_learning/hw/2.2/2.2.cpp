/*
*ʵ�������Ͷ�ջ����ִ�����в�����
*��ջ����ջ��
*�ж�ջΪ�գ�
*��ӡջ��Ԫ��
*/

#include <iostream> //��������һ��#
#include "stack.h"
using namespace std;
//class stack //�����һ����ĸӦ����Сд
//{
//private:
//#define MAX 20 //�ú������������
//    int array[MAX];
//    int top;
//public:
//    stack() { top = -1; }; //top��ʼ�����������
//    void push(int n);
//    int pop();
//    bool isEmpty();
//    bool isFull(); 
//    void dump();
//};
//void stack::push(int n) //����Ӧ��д����������
//{
//    if (isFull())cout << "ջ��"; // ����Ӧ�ü�����
//    else {
//        ++top;
//        array[top] = n;
//    }
//}
//int stack::pop() //���ﷵ������Ӧ�÷��ھ���
//{
//    int t = 0; //��������һ������ֵ
//    if (isEmpty())cout << "ջ��";// ����Ӧ�ü�����
//    else {
//        t = array[top]; //��ȡ��ջ��
//        array[top] = 0; //ջ���ÿ�
//        top--; //ָ������
//    }
//    return t; //����ջ��
//}
//bool stack::isEmpty() //�ж��Ƿ�Ϊ�� //���ﷵ������Ӧ�÷��ھ���
//{
//    if (top <= -1)return 1;
//    else return 0;
//}
//bool stack::isFull() //�ж��Ƿ��� //���ﷵ������Ӧ�÷��ھ���
//{
//    if (top == (MAX - 1))return 1; //��������һ���ֺ�
//    else return 0;
//}
//void stack::dump() //���ﷵ������Ӧ�÷��ھ���
//{
//    int i;
//    for (i = top; i == 0; i--)
//    {
//        cout << "��" << i << "��=" << array[i]; // ����ֱ��д��Ա���ɣ���Ҫ����
//    }
//}
void main()
{
    int i = 0;
    stack a;
    for (i =0;i<MAX;i++)
    {
        a.push(i);
    }
    a.dump();
    for (i=0;i<MAX;i++)
    {
        cout << a.pop() << endl;
    }
    //cout << a.isEmpty() << endl;
    a.isEmpty();
    exit(0);
  }