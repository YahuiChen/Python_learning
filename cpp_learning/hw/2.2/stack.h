#ifndef STACK_H
#define STACK_H
#include <iostream> 
using namespace std;
class stack
{
private:
#define MAX 10 
  int array[MAX];
  int top;
public:
  stack()
  {
    top = -1;
  };
  ~stack();
  void push(int n);
  int pop();
  bool isEmpty();
  bool isFull();
  void dump();
};
#endif