#ifndef MINSTACK_H
#define MINSTACK_H
#include <iostream>
#include "listStack.h"
using namespace std;

template <typename T>
class minStack{
public:
  void push(T value){

    if (minElementStack.size()==0 || value <= minElementStack.top()){
      minElementStack.push(value);
    }
    originalStack.push(value);
  }
  T pop(){
    if(originalStack.size()==0){
      throw out_of_range("pop: stack is empty.");
    }
    T popped = originalStack.pop();
    if (popped==minElementStack.top()){
      minElementStack.pop();
    }
    return popped;
  }
  T min(){
    if (minElementStack.size()==0){
      throw out_of_range("min: stack is empty.");
    }
    return minElementStack.top();
  }
  int size(){
    return originalStack.size();
  }
  void print(){
    originalStack.print();
  }

private:
  listStack<T> originalStack;
  listStack<T> minElementStack;

};

#endif
