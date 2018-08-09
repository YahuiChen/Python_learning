/*
*实现整数型堆栈，能执行下列操作：
*入栈；出栈；
*判断栈为空；
*打印栈中元素
*/

#include <iostream> //这里少了一个#
#include "stack.h"
using namespace std;
//class stack //这里第一个字母应该是小写
//{
//private:
//#define MAX 20 //用宏在这里更适用
//    int array[MAX];
//    int top;
//public:
//    stack() { top = -1; }; //top初始化在这里完成
//    void push(int n);
//    int pop();
//    bool isEmpty();
//    bool isFull(); 
//    void dump();
//};
//void stack::push(int n) //这里应该写明返回类型
//{
//    if (isFull())cout << "栈满"; // 这里应该加括号
//    else {
//        ++top;
//        array[top] = n;
//    }
//}
//int stack::pop() //这里返回类型应该放在句首
//{
//    int t = 0; //这里增加一个返回值
//    if (isEmpty())cout << "栈空";// 这里应该加括号
//    else {
//        t = array[top]; //先取得栈顶
//        array[top] = 0; //栈顶置空
//        top--; //指针下移
//    }
//    return t; //返回栈顶
//}
//bool stack::isEmpty() //判断是否为空 //这里返回类型应该放在句首
//{
//    if (top <= -1)return 1;
//    else return 0;
//}
//bool stack::isFull() //判断是否满 //这里返回类型应该放在句首
//{
//    if (top == (MAX - 1))return 1; //这里少了一个分号
//    else return 0;
//}
//void stack::dump() //这里返回类型应该放在句首
//{
//    int i;
//    for (i = top; i == 0; i--)
//    {
//        cout << "第" << i << "个=" << array[i]; // 这里直接写成员即可，不要类名
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