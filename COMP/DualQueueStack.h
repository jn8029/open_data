/**
  Assignment 1, Question 1.b, DualQueueStack.h
  Purpose: implementation of a stack with two queues

  @author Warren Cheng
  @version 2019.05.01
*/
#ifndef DQSTACK_H
#define DQSTACK_H

#include <iostream>
#include "arrayQueue.h"

using namespace std;

class DualQueueStack{
public:
  void push(int value){
    q1->enqueue(value);
  }
  int pop(){
    if (q1->size()==0){
      throw("pop: stack is empty.");
    }
    int poppedValue;
    int q1Size = q1->size();
    for (size_t i =0; i< q1Size-1; i++){
      poppedValue = q1->dequeue();
      q2->enqueue(poppedValue);
    }
    poppedValue = q1->dequeue();


    /*
      variable temp: redirecting the pointers of q1 and q2 so that push method does not require
      checking whether q1 or q2 is the main one that contains all the elements.
    */
    arrayQueue<int>* temp = q2;
    q2 = q1;
    q1 = temp;
    return poppedValue;
  }

  int size(){
    int q1Size = q1->size();
    return q1Size;
  }

private:
  arrayQueue<int>* q1 = new arrayQueue<int>;
  arrayQueue<int>* q2 = new arrayQueue<int>;
};
#endif
