/**
  Assignment 1, Question 1.b, DualQueueStack.h
  Purpose: implementation of a stack with two queues

  @author Warren Cheng
  @version 2019.05.01
*/
#ifndef DQSTACK_H
#define DQSTACK_H

#include <iostream>
#include <queue>
using namespace std;

class DualQueueStack{
public:
  void push(int value){
    q1->push(value);
  }
  int pop(){
    if (q1->empty()){
      throw("pop: stack is empty.");
    }
    int poppedValue;
    int q1Size = q1->size();
    for (size_t i =0; i< q1Size-1; i++){
      /*
        C++ Standard Template Library queue's pop method returns void
        Therefore take the item in the front of the queue before popping it off
      */
      poppedValue = q1->front();
      q1->pop();
      q2->push(poppedValue);
    }
    poppedValue = q1->front();
    q1->pop();


    /*
      variable temp: redirecting the pointers of q1 and q2 so that push method does not require
      checking whether q1 or q2 is the main one that contains all the elements.
    */
    queue<int>* temp = q2;
    q2 = q1;
    q1 = temp;
    return poppedValue;
  }

  int size(){
    int q1Size = q1->size();
    return q1Size;
  }

private:
  queue<int>* q1 = new queue<int>;
  queue<int>* q2 = new queue<int>;
};
#endif
